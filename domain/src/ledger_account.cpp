#include "../inc/ledger_account.hpp"

#include <memory>

namespace ltui
{
  ledger_account::ledger_account(std::string val)
    : _val(std::move(val))
  {
  }
}
