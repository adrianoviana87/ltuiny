#ifndef _FTXUI_EXTENDED_MONEY_INPUT_H_
#define _FTXUI_EXTENDED_MONEY_INPUT_H_

#include "./maskinputbase.hpp"
#include "../../crosscutting/inc/noexcept.hpp"

namespace ftxui {
class MoneyInput : public MaskInputBase {
public:
  // Constructor.
  MoneyInput() = default;
  MoneyInput(MoneyInput &) = default;
  MoneyInput(MoneyInput &&) NOEXCEPT = default;
  ~MoneyInput() override = default;

  MoneyInput &operator=(const MoneyInput &) = default;
  MoneyInput &operator=(MoneyInput &&) NOEXCEPT = default;
protected:
  bool on_char_typed(wchar_t ch) override;
};
}

#endif
