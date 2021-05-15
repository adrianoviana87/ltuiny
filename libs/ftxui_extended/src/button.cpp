// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.

#include "./button.hpp"

#include <algorithm>
#include <iostream>
#include <memory>
#include <ftxui/component/event.hpp>

namespace ftxui {

void ButtonExt::set_content(Element val) { content = std::move(val); }

void ButtonExt::set_on_enter(std::function<void()> val) {
  on_enter = std::move(val);
}

void ButtonExt::set_style(Decorator val) { normal_style = std::move(val); }

Element ButtonExt::Render() {
  bool is_focused = Focused();
  auto style = is_focused ? normal_style | focused_style : normal_style;

  return hbox({text(L" "), content, text(L" ")}) | style;
}

bool ButtonExt::OnEvent(Event event) {
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
