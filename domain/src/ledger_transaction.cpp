#include "../inc/ledger_transaction.hpp"

#include <memory>

namespace ltui
{
  ledger_transaction::ledger_transaction(ledger_account account, ledger_amount amount)
    : _account(std::move(account)),
    _amount(std::move(amount))
  {
  }
}
