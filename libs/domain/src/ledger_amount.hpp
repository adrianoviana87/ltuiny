#ifndef LTUI_LEDGER_AMOUNT_H
#define LTUI_LEDGER_AMOUNT_H

#include "./domain_operator_overloading.hpp"
#include "crosscutting.hpp"
#include <string>

namespace ltui {
class ledger_amount {
public:
  ledger_amount(std::string val, std::string commodity);
  ledger_amount(const ledger_amount &) = default;
  ledger_amount(ledger_amount &&) = default;
  ledger_amount &operator=(const ledger_amount &) NOEXCEPT = default;
  ledger_amount &operator=(ledger_amount &&) NOEXCEPT = default;
  ~ledger_amount() NOEXCEPT = default;

private:
  std::string _val;
  std::string _commodity;
  friend std::ostream & ::operator<<(std::ostream &stream,
                                     const ledger_amount &instance);
};
} // namespace ltui

#endif
