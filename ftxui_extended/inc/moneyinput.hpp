#ifndef _FTXUI_EXTENDED_MONEY_INPUT_H_
#define _FTXUI_EXTENDED_MONEY_INPUT_H_

#include "./maskinputbase.hpp"

namespace ftxui {
class MoneyInput : public MaskInputBase {
public:
  // Constructor.
  MoneyInput() = default;
  MoneyInput(MoneyInput &) = default;
  MoneyInput(MoneyInput &&) noexcept = default;
  ~MoneyInput() override = default;

  MoneyInput &operator=(const MoneyInput &) = default;
  MoneyInput &operator=(MoneyInput &&) noexcept = default;
protected:
  bool on_char_typed(wchar_t ch) override;
};
}

#endif
