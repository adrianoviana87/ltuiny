#include "../inc/ledger_transaction.hpp"

#include <memory>

namespace ltui
{
  ledger_transaction::ledger_transaction(ledger_account account, std::optional<ledger_amount> amount)
    : account(std::move(account)),
    amount(std::move(amount))
  {
  }
}
