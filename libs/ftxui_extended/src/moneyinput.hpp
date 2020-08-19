#ifndef LTUI_MONEY_INPUT_H
#define LTUI_MONEY_INPUT_H

#include "./maskinputbase.hpp"
#include "crosscutting.hpp"

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
