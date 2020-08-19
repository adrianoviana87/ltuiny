#ifndef LTUI_HOME_VIEW_H
#define LTUI_HOME_VIEW_H

#include "./router.hpp"
#include "./view.hpp"

#include "ftxui/component/container.hpp"
#include "ftxui/component/menu.hpp"

#include <memory>

namespace ltui {
struct home_view : public view {
  explicit home_view(std::shared_ptr<router> router);

protected:
  void initialize_ui() override;

private:
  void on_menu_selected(int option);
  std::shared_ptr<router> _router;
  ftxui::Container _container;
  ftxui::Menu _menu;
};
} // namespace ltui

#endif
