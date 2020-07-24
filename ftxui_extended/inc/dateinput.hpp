#ifndef _FTXUI_EXTENDED_DATE_INPUT_H_
#define _FTXUI_EXTENDED_DATE_INPUT_H_

#include "./maskinputbase.hpp"

namespace ftxui {
class DateInput : public MaskInputBase {
public:
  // Constructor.
  DateInput() = default;
  DateInput(DateInput &) = default;
  DateInput(DateInput &&) noexcept = default;
  ~DateInput() override = default;

  DateInput &operator=(const DateInput &) = default;
  DateInput &operator=(DateInput &&) noexcept = default;

protected:
  bool on_char_typed(wchar_t ch) override;
};
} // namespace ftxui

#endif
