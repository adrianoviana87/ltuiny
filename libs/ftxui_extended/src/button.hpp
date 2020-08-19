#ifndef LTUI_BUTTON_H
#define LTUI_BUTTON_H

#include "ftxui/component/component.hpp"
#include <string>

namespace ftxui {
class Button : public Component {
public:
  // Constructor.
  Button() = default;
  Button(const Button &) = default;
  Button(Button &&) = default;
  ~Button() override = default;

  Button &operator=(const Button &) = default;
  Button &operator=(Button &&) = default;

  void set_content(Element val);
  void set_style(Decorator val);
  void set_on_enter(std::function<void()> val);

  // Component implementation.
  Element Render() override;
  bool OnEvent(Event event) override;

private:
  // State.
  Element content = text(L"");

  Decorator focused_style = inverted;
  Decorator normal_style = bgcolor(Color::Blue) | color(Color::White);

  // State update callback.
  std::function<void()> on_enter = []() {};
};
} // namespace ftxui

#endif
