#include "./new_entry_view.hpp"

#include "domain.hpp"

#include <algorithm>
#include <numeric>
#include <ftxui/dom/elements.hpp>
#include <memory>
#include <vector>
#include <cmath>

#include "crosscutting.hpp"

namespace ltui {
using namespace ftxui;

new_entry_view::new_entry_view(std::shared_ptr<ledger_entry_service> service,
                               std::shared_ptr<app_settings> settings)
    : _service(std::move(service)), _settings(std::move(settings)),
       _transaction_index(-1) {}

void new_entry_view::save_entry() {
  std::vector<std::shared_ptr<ledger_transaction>> trans;

  std::transform(std::begin(_transactions), std::end(_transactions),
                 std::back_inserter(trans), [](auto &item) {
                   return std::make_shared<ledger_transaction>(
                       ledger_account(item.account),
                       ledger_amount(item.value, item.commodity));
                 });
  auto entry = std::make_shared<ledger_entry>(to_str(c_date->get_content()),
                                              to_str(c_title_content), trans);

  _service->save(entry);
  clear_form();
}

void new_entry_view::clear_form() {
  c_title_content.clear();
  clear_transaction();
  _transactions.clear();
}

bool new_entry_view::save_transaction() {
  if (c_account_content.empty()) {
    return false;
  }

  const auto commodity =
      c_value->get_content().empty() ? "" : to_str(c_commodity_content);
  const double transVal = [&]() {
    if (c_value->get_content().empty()) {
      return 0.0;
    }

    double tmp = 0.0;
    if (str_parse(to_str(c_value->get_content()), tmp)) {
      return tmp;
    }

    return 0.0;
  }();

  if (_transaction_index < 0) {
    _transactions.push_back(
        {to_str(c_account_content), to_str(c_value->get_content()), commodity, transVal});
  } else {
    auto &trans = _transactions.at(_transaction_index);

    trans.account = to_str(c_account_content);
    trans.value = to_str(c_value->get_content());
    trans.commodity = commodity;
    trans.numericValue = transVal;
  }

  reset_transaction();

  return true;
}

void new_entry_view::reset_transaction() {
  auto prev_commodity = c_commodity_content;
  clear_transaction();

  c_commodity_content = prev_commodity;
  if (c_usePreviousAccountState && !_transactions.empty()) {
    std::string accountToUse = _transactions.back().account;
    if (c_removeAccountLeafState) {
      auto accounts = split_str(accountToUse, ':');
      if (!accounts.empty()) {
        accountToUse =
            join_str(std::begin(accounts), std::end(accounts) - 1, ':');
        if (accountToUse.back() != ':') {
          accountToUse += ':';
        }
      }
    }

    c_account_content = to_wstr(accountToUse);
  }
}

void new_entry_view::clear_transaction() {
  c_account_content.clear();
  c_value->clear();
  c_commodity_content.clear();
  _transaction_index = -1;
}

void new_entry_view::initialize_ui() {
  c_space.character = ' ';


  c_save_trans->set_style(border | color(Color::Green));
  c_save_trans->set_content(text(L"Save"));
  c_save_trans->set_on_enter([this] {
    if (save_transaction()) {
      OnEvent(Event::ArrowUp);
      OnEvent(Event::ArrowUp);
      OnEvent(Event::ArrowUp);
    }
  });

  c_cancel_trans->set_style(border | color(Color::Red));
  c_cancel_trans->set_content(text(L"Cancel"));
  c_cancel_trans->set_on_enter([this] { clear_transaction(); });

  c_from_last_trans->set_style(border | color(Color::Yellow));
  c_from_last_trans->set_content(text(L"Start from last"));
  c_from_last_trans->set_on_enter([this] { reset_transaction(); });

  InputBase::From(c_account)->on_enter = [this] { save_transaction(); };

  c_value->set_on_enter([this] {
    if (save_transaction()) {
      OnEvent(Event::ArrowUp);
    }
  });

  InputBase::From(c_commodity)->on_enter = [this] {
    if (save_transaction()) {
      OnEvent(Event::ArrowUp);
      OnEvent(Event::ArrowUp);
    }
  };

  CheckboxBase::From(c_usePreviousAccount)->on_change = [this] {
    if (!c_usePreviousAccountState) {
      c_removeAccountLeafState = false;
    }
  };

  c_transactions->set_items(&_transactions);
  c_transactions->set_on_enter([this](const entry_trans_dto &item) {
    c_account_content = to_wstr(item.account);
    c_value->set_content(to_wstr(item.value));
    _transaction_index = c_transactions->get_selected_index();

    constexpr auto account_distance = 6;
    for (auto i = 0; i < account_distance + _transaction_index; ++i) {
      OnEvent(Event::ArrowUp);
    }
  });

  c_transactions->set_render_item([](const entry_trans_dto &item) {
    return hbox({text(to_wstr(item.account)) | flex_grow,
                 text(to_wstr(item.value + ' ' + item.commodity)) |
                     align_right}) |
           flex;
  });

  c_save_entry->set_content(text(L"Save Entry") | bold);
  c_save_entry->set_style(bgcolor(Color::Green) | color(Color::White));
  c_save_entry->set_on_enter([this] { save_entry(); });

  c_clear_form->set_content(text(L"Clear Form") | bold);
  c_clear_form->set_style(bgcolor(Color::Red) | color(Color::White));
  c_clear_form->set_on_enter([this] { clear_form(); });

  c_quit->set_content(text(L"Quit") | bold);
  c_quit->set_style(bgcolor(Color::GrayDark) | color(Color::White));
  c_quit->set_on_enter([this] { close(); });

  auto container = Container::Vertical({
      c_save_entry,
      c_clear_form,
      c_quit,
      c_usePreviousAccount,
      c_removeAccountLeaf,
      c_date,
      c_title,
      c_account,
      c_value,
      c_commodity,
      c_save_trans,
      c_cancel_trans,
      c_from_last_trans,
      c_transactions,
  });
  Add(container);
}

Element new_entry_view::Render() {
  return window(text(L"ADD ENTRY") | center, frame(vbox({
                                                 render_toolbar(),
                                                 render_settings(),
                                                 render_header(),
                                                 render_add_transaction(),
                                                 render_transactions(),
                                             })));
}

Element new_entry_view::render_toolbar() {
  return vbox({
      hbox({
          c_save_entry->Render(),
          c_clear_form->Render(),
          c_quit->Render(),
      }),
      separator(),
  });
}

Element new_entry_view::render_settings() {
  return window(text(L"Settings"),
                hbox({
                    c_usePreviousAccount->Render(),
                    text(L"  "),
                    (c_usePreviousAccountState ? c_removeAccountLeaf->Render()
                                                : filler()),
                }) | borderWith(c_space));
}

Element new_entry_view::render_header() {
  constexpr auto date_width = 20;
  return window(text(L"Header"), vbox({
                                     hbox({
                                         vbox({
                                             text(L"Date:"),
                                             c_date->Render() | border,
                                         }) | size(WIDTH, EQUAL, date_width),
                                         vbox({
                                             text(L"Title"),
                                             c_title->Render() | border,
                                         }) | flex_grow,
                                     }),
                                 }) | borderWith(c_space));
}

Element new_entry_view::render_add_transaction() {
  constexpr auto value_width = 15;
  constexpr auto commodity_width = 10;
  double transTotal = 0.0;
  transTotal = std::accumulate(
      std::begin(_transactions),
      std::end(_transactions),
      0.0,
      [](auto total, auto& item) {
        return total + item.numericValue;
      });

  // clang-format off
  return window(
      text(L"Add Transaction"),
      vbox({
        hbox({
          vbox({
            text(L"Account:"),
            c_account->Render() | border
          }) | flex_grow,
          vbox({
            text(L"Value:"),
            c_value->Render() | border
          }) | size(ftxui::WIDTH, ftxui::EQUAL, value_width),
          vbox({
            text(L"Com:"),
            c_commodity->Render() | border
          }) | size(ftxui::WIDTH, ftxui::EQUAL, commodity_width)
        }),
        hbox({
          c_save_trans->Render(),
          c_cancel_trans->Render(),
          c_from_last_trans->Render(),
          filler() | flex,
          hbox({
            text(L"Total: ") | bold,
            text(std::to_wstring(transTotal))
          }) | border
        })
      }) | borderWith(c_space));
  // clang-format on
}

Element new_entry_view::render_transactions() {
  Element content;

  if (_transactions.empty()) {
    content = text(L"No transactions yet");
  } else {
    content = c_transactions->Render();
  }

  return window(text(L"Transactions"), content | borderWith(c_space));
}
} // namespace ltui
