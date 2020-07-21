#ifndef _LTUI_LEDGER_TRANSACTION_H_
#define _LTUI_LEDGER_TRANSACTION_H_

#include "./ledger_account.hpp"
#include "./ledger_amount.hpp"

#include <chrono>
#include <string>
#include <optional>
#include "./domain_operator_overloading.hpp"

namespace ltui
{
  class ledger_transaction
  {
  public:
    ledger_transaction(ledger_account account, std::optional<ledger_amount> amount);
    ledger_transaction(const ledger_transaction &) = default;
    ledger_transaction(ledger_transaction &&) = default;
    ledger_account account;
    std::optional<ledger_amount> amount;
    friend std::ostream & ::operator<<(std::ostream &stream, const ledger_transaction &instance);
  };
} // namespace ltui

#endif
