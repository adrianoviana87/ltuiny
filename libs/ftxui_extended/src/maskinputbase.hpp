#ifndef LTUI_MASKED_INPUT_BASE_H
#define LTUI_MASKED_INPUT_BASE_H

#include "ftxui/component/component.hpp"

namespace ftxui {
class MaskInputBase : public ComponentBase {
public:
  // Constructor.
  MaskInputBase() = default;
  MaskInputBase(MaskInputBase&) = default;
  MaskInputBase(MaskInputBase&&) = default;
  ~MaskInputBase() override = default;

  MaskInputBase& operator=(const MaskInputBase&) = default;
  MaskInputBase& operator=(MaskInputBase&&) = default;

  // Component implementation.
  Element Render() override;
  bool OnEvent(Event event) override;
  void clear();
  [[nodiscard]] const std::wstring& get_content() const;
  void set_on_enter(std::function<void()> val);
  void set_content(std::wstring val);

protected:
  virtual bool on_char_typed(wchar_t ch) = 0;
  [[nodiscard]] int get_cursor_position() const;
  void set_cursor_position(int val);
  void add_char(wchar_t ch);

private:
  int cursor_position = 0;
  // State.
  std::wstring content;
  std::wstring placeholder;

  // State update callback.
  std::function<void()> on_change = []() {};
  std::function<void()> on_enter = []() {};

};
} // namespace ftxui

#endif
