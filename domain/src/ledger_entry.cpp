#include "../inc/ledger_entry.hpp"

#include <memory>

namespace ltui
{
  ledger_entry::ledger_entry(
      std::string date,
      std::string title,
      std::vector<ledger_transaction> transactions)
    : _date(std::move(date)),
    _title(std::move(title)),
    _transactions(std::move(transactions))
  {
  }
}
