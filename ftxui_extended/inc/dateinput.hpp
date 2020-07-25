#ifndef _FTXUI_EXTENDED_DATE_INPUT_H_
#define _FTXUI_EXTENDED_DATE_INPUT_H_

#include "./maskinputbase.hpp"
#include "../../crosscutting/inc/noexcept.hpp"

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
