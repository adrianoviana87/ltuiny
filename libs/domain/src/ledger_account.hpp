#ifndef LTUI_LEDGER_ACCOUNT_H
#define LTUI_LEDGER_ACCOUNT_H

#include "./domain_operator_overloading.hpp"
#include "crosscutting.hpp"
#include <string>

namespace ltui {
class ledger_account {
public:
  explicit ledger_account(std::string val);
  ledger_account(const ledger_account &) = default;
  ledger_account(ledger_account &&) = default;
  ~ledger_account() NOEXCEPT = default;
  [[nodiscard]] std::string to_string() const;
  ledger_account &operator=(const ledger_account &rhs) = default;
  ledger_account &operator=(ledger_account &&rhs) NOEXCEPT = default;

private:
  std::string _val;
  friend std::ostream & ::operator<<(std::ostream &stream,
                                     const ledger_account &instance);
  friend bool ::operator<(const ledger_account &lhs, const ledger_account &rhs);
  friend bool ::operator==(const ledger_account &lhs,
                           const ledger_account &rhs);
  friend bool ::operator!=(const ledger_account &lhs,
                           const ledger_account &rhs);
};
} // namespace ltui

#endif
