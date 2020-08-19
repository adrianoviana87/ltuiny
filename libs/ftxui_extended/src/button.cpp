// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.

#include "./button.hpp"

#include <algorithm>
#include <iostream>
#include <memory>

namespace ftxui {

void Button::set_content(Element val) { content = std::move(val); }

void Button::set_on_enter(std::function<void()> val) {
  on_enter = std::move(val);
}

void Button::set_style(Decorator val) { normal_style = std::move(val); }

Element Button::Render() {
  bool is_focused = Focused();
  auto style = is_focused ? normal_style | focused_style : normal_style;

  return hbox({text(L" "), content, text(L" ")}) | style;
}

bool Button::OnEvent(Event event) {
  if (!Focused()) {
    return false;
  }

  if (event == Event::Return) {
    on_enter();
    return true;
  }

  return false;
}

} // namespace ftxui
