#include "../inc/home_view.hpp"
#include <iostream>
#include <memory>

using namespace std;

namespace ltui {
home_view::home_view(std::shared_ptr<router> router)
    : view(), _router(std::move(router)),
      _container(ftxui::Container::Vertical()), _menu() {}

void home_view::initialize_ui() {
  _menu.entries.emplace_back(L"Add Entry");
  _menu.entries.emplace_back(L"Quit");
  _menu.on_enter = [&]() { this->on_menu_selected(this->_menu.selected); };
  _container.Add(&_menu);
  Add(&_container);
}

void home_view::on_menu_selected(int option) {
  if (option == 0) {
    _router->navigate("ledger_entry/new", std::any());
  } else {
    close();
  }
}
} // namespace ltui
