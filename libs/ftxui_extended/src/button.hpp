#ifndef LTUI_BUTTON_H
#define LTUI_BUTTON_H

#include "ftxui/component/component.hpp"
#include <string>

namespace ftxui {

/// XXX consider using ftxui::Button() instead.
class ButtonExt : public ComponentBase {
 public:
  // Constructor.
  ButtonExt() = default;
  ButtonExt(const ButtonExt &) = default;
  ButtonExt(ButtonExt &&) = default;
  ~ButtonExt() override = default;

  ButtonExt &operator=(const ButtonExt &) = default;
  ButtonExt &operator=(ButtonExt &&) = default;

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
