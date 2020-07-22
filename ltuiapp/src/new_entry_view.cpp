#include "../inc/new_entry_view.hpp"
#include <algorithm>
#include <ftxui/dom/elements.hpp>
#include <vector>
#include "../inc/text.hpp"

namespace ltui
{
  using namespace ftxui;

  new_entry_view::new_entry_view(
      std::shared_ptr<ledger_entry_service> service,
      std::shared_ptr<app_settings> settings)
    : _service(std::move(service)),
    _settings(std::move(settings)),
    c_container(Container::Vertical())
  {
  }

  void new_entry_view::save_transaction()
  {
    _cur_entry.transactions.push_back({
        to_str(c_account.content),
        to_str(c_value.content),
        std::string()
        });

    c_account.content.clear();
    c_value.content.clear();
  }

  void new_entry_view::initialize_ui()
  {
    c_container.Add(&c_date);
    c_container.Add(&c_title);
    c_container.Add(&c_account);
    c_container.Add(&c_value);
    c_container.Add(&c_save_trans);
    Add(&c_container);
    c_save_trans.entries.push_back(L"Save");
    c_save_trans.on_enter = [this]() {
      save_transaction();
      OnEvent(Event::ArrowUp);
      OnEvent(Event::ArrowUp);
    };

    c_account.on_enter = [this]() {
      save_transaction();
    };

    c_value.on_enter = [this]() {
      save_transaction();
      OnEvent(Event::ArrowUp);
    };
  }

  Element new_entry_view::Render()
  {
    return
      window(
          text(L"ADD ENTRY") | center,
          frame(
            vbox({
              window(
                  text(L"Header"),
                  vbox({
                    hbox({ text(L"Date: "), c_date.Render() }) | flex,
                    hbox({ text(L"Title: "), c_title.Render() }) | flex
                    })
                  ),
              window(
                  text(L"Add Transaction"),
                  vbox({
                    hbox({text(L"Account: "), c_account.Render()}),
                    hbox({text(L"Value: "), c_value.Render()}),
                    c_save_trans.Render() | bgcolor(Color::Blue) | color(Color::White)
                    })
                  ),
              window(
                  text(L"Transactions"),
                  RenderTransactions()
                  )
              }))
    );
  }

  Element new_entry_view::RenderTransactions()
  {
    if (_cur_entry.transactions.empty())
      return text(L"No transactions");

    std::vector<Element> els;

    std::transform(
        std::begin(_cur_entry.transactions),
        std::end(_cur_entry.transactions),
        std::back_inserter(els),
        [](auto& item) {
        return
        hbox({
            text(to_wstr(item.account)),
            text(to_wstr(item.value)) | align_right
            });
        });

    return vbox(els);
  }
}
