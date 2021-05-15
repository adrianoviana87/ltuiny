#include "./screen_service.hpp"
#include "./home_view.hpp"
#include "ftxui/component/input.hpp"
#include "ftxui/dom/elements.hpp"
#include <memory>

namespace ltui {
using namespace ftxui;

screen_service::screen_service()
    : _screen(ftxui::ScreenInteractive::Fullscreen()) {}

void screen_service::render(std::shared_ptr<view> view_instance) {
  _current_view = std::move(view_instance);
  _current_view->initialize();
  _current_view->set_on_close([&]() { this->_screen.ExitLoopClosure(); });
  _screen.Loop(_current_view);
}
} // namespace ltui
