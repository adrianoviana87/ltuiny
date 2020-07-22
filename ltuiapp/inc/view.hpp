#ifndef _LTUI_VIEW_H_
#define _LTUI_VIEW_H_

#include "ftxui/component/component.hpp"

#include <functional>

namespace ltui
{
  class view : public ftxui::Component
  {
    public:
      view();
      std::function<void()> closed;
      void initialize();
      virtual ~view() noexcept = default;
    protected:
      void close();
      virtual void initialize_ui() = 0;
  };
} // namespace ltui

#endif
