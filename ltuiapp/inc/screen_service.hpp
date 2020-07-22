#ifndef _LTUI_SCREEN_SERVICE_H_
#define _LTUI_SCREEN_SERVICE_H_

#include <memory>
#include "./view.hpp"
#include "ftxui/component/screen_interactive.hpp"

namespace ltui
{
  class screen_service
  {
    public:
      screen_service();
      void render(std::shared_ptr<view> view_instance);
    private:
      ftxui::ScreenInteractive _screen;
      std::shared_ptr<view> _current_view;
  };
}

#endif

