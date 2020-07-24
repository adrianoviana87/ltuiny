#include "../../crosscutting/inc/string-utils.hpp"
#include "../inc/new_entry_view.hpp"
#include <algorithm>
#include <ftxui/dom/elements.hpp>
#include <memory>
#include <vector>

namespace ltui {
using namespace ftxui;

new_entry_view::new_entry_view(
  std::shared_ptr<ledger_entry_service> service,
  std::shared_ptr<app_settings> settings)
  : _service(std::move(service)),
    _settings(std::move(settings)),
    c_container(Container::Vertical()),
    _transaction_index(-1)
{
}

void new_entry_view::log(std::wstring message)
{
  c_log.entries.push_back(std::move(message));
}

void new_entry_view::log(const std::string &message)
{
  c_log.entries.push_back(to_wstr(message));
}

void new_entry_view::save_transaction()
{
  auto last_account = c_account.content;

  if (_transaction_index < 0) {
    _cur_entry.transactions.push_back({ to_str(c_account.content),
      to_str(c_value.content),
      std::string() });
  } else {
    auto &trans = _cur_entry.transactions.at(_transaction_index);

    trans.account = to_str(c_account.content);
    trans.value = to_str(c_value.content);
  }

  reset_transaction();
}

void new_entry_view::reset_transaction()
{
  clear_transaction();
  if (_formSettings.usePreviousAccount && !_cur_entry.transactions.empty()) {
    std::string accountToUse = _cur_entry.transactions.back().account;
    if (_formSettings.removeAccountLeaf) {
      auto accounts = split_str(accountToUse, ':');
      if (!accounts.empty()) {
        accountToUse = join_str(
          std::begin(accounts),
          std::end(accounts) - 1,
          ':');
      }
    }

    c_account.content = to_wstr(accountToUse);
  }
}

void new_entry_view::clear_transaction()
{
  c_account.content.erase();
  c_value.content.erase();
  _transaction_index = -1;
}

void new_entry_view::initialize_ui()
{
  c_space.character = ' ';

  c_save_trans.normal_style = border | color(Color::Green);
  c_save_trans.content = text(L"Save");
  c_save_trans.on_enter = [this]() {
    save_transaction();
    OnEvent(Event::ArrowUp);
    OnEvent(Event::ArrowUp);
  };

  c_cancel_trans.normal_style = border | color(Color::Red);
  c_cancel_trans.content = text(L"Cancel");
  c_cancel_trans.on_enter = [this]() {
    clear_transaction();
  };

  c_from_last_trans.normal_style = border | color(Color::Yellow);
  c_from_last_trans.content = text(L"Start from last");
  c_from_last_trans.on_enter = [this]() {
    reset_transaction();
  };

  c_account.on_enter = [this]() {
    save_transaction();
  };

  c_value.on_enter = [this]() {
    save_transaction();
    OnEvent(Event::ArrowUp);
  };

  c_usePreviousAccount.label = L"Use Previous Account";
  c_usePreviousAccount.on_change = [this]() {
    _formSettings.usePreviousAccount = c_usePreviousAccount.state;
    if (!_formSettings.usePreviousAccount) {
      c_removeAccountLeaf.state = false;
      _formSettings.removeAccountLeaf = false;
    }
  };

  c_removeAccountLeaf.label = L"Remove Account Leaf";
  c_removeAccountLeaf.on_change = [this]() {
    _formSettings.removeAccountLeaf = c_removeAccountLeaf.state;
  };

  c_transactions.items = &_cur_entry.transactions;
  c_transactions.on_enter = [this](const entry_trans_dto &item) {
    c_account.content = to_wstr(item.account);
    c_value.content = to_wstr(item.value);
    _transaction_index = c_transactions.selected;
  };
  c_transactions.render_item = [](const entry_trans_dto &item) {
    return hbox({ text(to_wstr(item.account)) | flex_grow, text(to_wstr(item.value)) | align_right }) | flex;
  };

  c_container.Add(&c_usePreviousAccount);
  c_container.Add(&c_removeAccountLeaf);
  c_container.Add(&c_date);
  c_container.Add(&c_title);
  c_container.Add(&c_account);
  c_container.Add(&c_value);
  c_container.Add(&c_save_trans);
  c_container.Add(&c_cancel_trans);
  c_container.Add(&c_from_last_trans);
  c_container.Add(&c_transactions);
  Add(&c_container);

  _formSettings.usePreviousAccount = true;
  _formSettings.removeAccountLeaf = true;
  c_usePreviousAccount.state = true;
  c_removeAccountLeaf.state = true;
}

Element new_entry_view::Render()
{
  return window(
    text(L"ADD ENTRY") | center,
    frame(
      vbox({ render_settings(),
        render_header(),
        render_add_transaction(),
        render_transactions() })));
}

Element new_entry_view::render_settings()
{
  return window(
    text(L"Settings"),
    hbox({ c_usePreviousAccount.Render(),
      text(L"  "),
      (_formSettings.usePreviousAccount
          ? c_removeAccountLeaf.Render()
          : filler()) })
      | borderWith(c_space));
}

Element new_entry_view::render_header()
{
  return window(
    text(L"Header"),
    hbox({ hbox({ text(L"Date: "), c_date.Render() }) | size(ftxui::WIDTH, ftxui::EQUAL, 20),
      hbox({ text(L" Title: "), c_title.Render() }) | flex })
      | borderWith(c_space));
}

Element new_entry_view::render_add_transaction()
{
  return window(
    text(L"Add Transaction"),
    vbox({ hbox({ text(L"Account: "), c_account.Render() }),
      hbox({ text(L"Value: "), c_value.Render() }),
      hbox({ c_save_trans.Render(),
        c_cancel_trans.Render(),
        c_from_last_trans.Render() }) })
      | borderWith(c_space));
}

Element new_entry_view::render_transactions()
{
  Element content;

  if (_cur_entry.transactions.empty()) {
    content = text(L"No transactions yet");
  } else {
    content = c_transactions.Render();
  }

  return window(
    text(L"Transactions"),
    content | borderWith(c_space));
}
}// namespace ltui
