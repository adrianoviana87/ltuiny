#ifndef _LTUI_LEDGER_ENTRY_H_
#define _LTUI_LEDGER_ENTRY_H_

#include "./ledger_transaction.hpp"
#include <chrono>
#include <string>
#include <vector>
#include <iosfwd>

namespace ltui
{
  class ledger_entry
  {
    public:
      ledger_entry(
          std::chrono::system_clock::time_point date,
          std::string title,
          std::vector<ledger_transaction> transactions);
    private:
      std::chrono::system_clock::time_point _date;
      std::string _title;
      std::vector<ledger_transaction> _transactions;
      friend std::ostream& operator<<(std::ostream& stream, const ledger_entry& instance);
  };
}

#endif
