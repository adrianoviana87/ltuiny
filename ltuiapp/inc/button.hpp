#ifndef _LTUI_FTXUI_BUTTON_H_
#define _LTUI_FTXUI_BUTTON_H_

#include <string>
#include "ftxui/component/component.hpp"

namespace ftxui {
class Button : public Component
{
public:
  // Constructor.
  Button() = default;
  ~Button() override = default;

  // State.
  Element content = text(L"");

  Decorator focused_style = inverted;
  Decorator normal_style = bgcolor(Color::Blue) | color(Color::White);

  // State update callback.
  std::function<void()> on_enter = []() {};

  // Component implementation.
  Element Render() override;
  bool OnEvent(Event) override;
};
}// namespace ftxui

#endif
