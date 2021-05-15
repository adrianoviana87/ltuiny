#include "./home_view.hpp"
#include <iostream>
#include <memory>

#include "ftxui/component/component.hpp"
#include "ftxui/component/menu.hpp"

using namespace std;

namespace ltui {

std::vector<std::wstring> menu_entries = {
    L"Add Entry",
    L"Quit",
};
home_view::home_view(std::shared_ptr<router> router)
    : view(), _router(std::move(router)) {}

void home_view::initialize_ui() {
  auto menu = ftxui::Menu(&menu_entries, &menu_selected);
  ftxui::MenuBase::From(menu)->on_enter = [&] { this->on_menu_selected(); };
  Add(menu);
}

void home_view::on_menu_selected() {
  if (menu_selected == 0) {
    _router->navigate("ledger_entry/new", std::any());
  } else {
    close();
  }
}

}  // namespace ltui
