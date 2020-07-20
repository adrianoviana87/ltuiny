#ifndef _LTUI_DOMAIN_STREAM_OPERATIONS_H_
#define _LTUI_DOMAIN_STREAM_OPERATIONS_H_

#include <iostream>

namespace ltui
{
  class ledger_account;
  class ledger_amount;
  class ledger_transaction;
  class ledger_entry;
}

std::ostream& operator<<(std::ostream& stream, const ltui::ledger_account& instance);
std::ostream& operator<<(std::ostream& stream, const ltui::ledger_amount& instance);
std::ostream& operator<<(std::ostream& stream, const ltui::ledger_transaction& instance);
std::ostream& operator<<(std::ostream& stream, const ltui::ledger_entry& instance);

#endif
