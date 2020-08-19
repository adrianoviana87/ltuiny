#include "./maskinputbase.hpp"
#include "ftxui/component/input.hpp"
#include "ftxui/screen/string.hpp"
#include <algorithm>
#include <memory>

namespace ftxui {

void MaskInputBase::set_on_enter(std::function<void()> val) {
  on_enter = std::move(val);
}

void MaskInputBase::set_content(std::wstring val) {
  content = std::move(val);
  cursor_position = static_cast<int>(content.size()) - 1;
}

int MaskInputBase::get_cursor_position() const { return cursor_position; }

void MaskInputBase::set_cursor_position(int val) { cursor_position = val; }

const std::wstring &MaskInputBase::get_content() const { return content; }

// Component implementation.
Element MaskInputBase::Render() {
  cursor_position = std::max(0, std::min<int>(content.size(), cursor_position));
  auto main_decorator = flex | size(HEIGHT, EQUAL, 1);
  bool is_focused = Focused();

  // Placeholder.
  if (content.empty()) {
    if (is_focused) {
      return text(placeholder) | focus | dim | inverted | main_decorator;
    }

    return text(placeholder) | dim | main_decorator;
  }

  // Not focused.
  if (!is_focused) {
    return text(content) | main_decorator;
  }

  std::wstring part_before_cursor = content.substr(0, cursor_position);
  std::wstring part_at_cursor = cursor_position < (int)content.size()
                                    ? content.substr(cursor_position, 1)
                                    : L" ";
  std::wstring part_after_cursor = cursor_position < (int)content.size() - 1
                                       ? content.substr(cursor_position + 1)
                                       : L"";
  auto focused = is_focused ? focus : select;

  // clang-format off
  return
    hbox(
      text(part_before_cursor),
      text(part_at_cursor) | underlined | focused,
      text(part_after_cursor)
    ) | flex | inverted | frame | main_decorator;
  // clang-format off
}

void MaskInputBase::clear() {
  content.clear();
  cursor_position = 0;
}

bool MaskInputBase::OnEvent(Event event) {
  cursor_position = std::max(0, std::min<int>(content.size(), cursor_position));
  std::wstring c;

  // Backspace.
  if (event == Event::Backspace) {
    clear();
    return true;
  }

  // Delete
  if (event == Event::Delete) {
    clear();
    return true;
  }

  // Enter.
  if (event == Event::Return) {
    on_enter();
    return true;
  }

  if (event == Event::Custom) {
    return false;
  }

  if (event == Event::ArrowLeft && cursor_position > 0) {
    cursor_position--;
    return true;
  }

  if (event == Event::ArrowRight && cursor_position < (int)content.size()) {
    cursor_position++;
    return true;
  }

  // Content
  if (event.is_character()) {
    return on_char_typed(event.character());
  }

  return false;
}

void MaskInputBase::add_char(wchar_t ch) {
  content.insert(cursor_position, 1, ch);
  cursor_position++;
}

}  // namespace ftxui

