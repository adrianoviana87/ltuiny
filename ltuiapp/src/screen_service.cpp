#include "../inc/screen_service.hpp"
#include "../inc/home_view.hpp"
#include "ftxui/component/input.hpp"
#include "ftxui/dom/elements.hpp"

namespace ltui
{
  using namespace ftxui;

  screen_service::screen_service()
    : _screen(ftxui::ScreenInteractive::Fullscreen())
  {
  }

  void screen_service::render(std::shared_ptr<view> view_instance)
  {
    _current_view = view_instance;
    view_instance->initialize();
    view_instance->closed = [&]() { this->_screen.ExitLoopClosure(); };
    _screen.Loop(_current_view.get());

    /* auto screen = ScreenInteractive::TerminalOutput(); */
    /* MyComponent1 component; */
    /* screen.Loop(&component); */

  }
}

