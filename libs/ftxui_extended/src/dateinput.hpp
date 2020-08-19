#ifndef LTUI_DATE_INPUT_H
#define LTUI_DATE_INPUT_H

#include "./maskinputbase.hpp"
#include "crosscutting.hpp"

namespace ftxui {
class DateInput : public MaskInputBase {
public:
  // Constructor.
  DateInput() = default;
  DateInput(DateInput &) = default;
  DateInput(DateInput &&) NOEXCEPT = default;
  ~DateInput() override = default;

  DateInput &operator=(const DateInput &) = default;
  DateInput &operator=(DateInput &&) NOEXCEPT = default;

protected:
  bool on_char_typed(wchar_t ch) override;
};
} // namespace ftxui

#endif
