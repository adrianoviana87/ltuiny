#ifndef LTUI_SCREEN_SERVICE_H
#define LTUI_SCREEN_SERVICE_H

#include "./view.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include <memory>

namespace ltui {
class screen_service {
public:
  screen_service();
  void render(std::shared_ptr<view> view_instance);

private:
  ftxui::ScreenInteractive _screen;
  std::shared_ptr<view> _current_view;
};
} // namespace ltui

#endif
