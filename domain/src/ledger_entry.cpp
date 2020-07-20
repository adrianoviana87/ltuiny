#include "../inc/ledger_entry.hpp"

#include <memory>

namespace ltui
{
  ledger_entry::ledger_entry(
      std::chrono::system_clock::time_point date,
      std::string title,
      std::vector<ledger_transaction> transactions)
    : _date(std::move(date)),
    _title(std::move(title)),
    _transactions(std::move(transactions))
  {
  }
}
