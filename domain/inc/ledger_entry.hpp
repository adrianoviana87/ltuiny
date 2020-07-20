#ifndef _LTUI_LEDGER_ENTRY_H_
#define _LTUI_LEDGER_ENTRY_H_

#include "./ledger_transaction.hpp"
#include <string>
#include <vector>
#include "./domain_stream_operations.hpp"

namespace ltui
{
  class ledger_entry
  {
    public:
      ledger_entry(
          std::string date,
          std::string title,
          std::vector<ledger_transaction> transactions);
    private:
      std::string _date;
      std::string _title;
      std::vector<ledger_transaction> _transactions;
      friend std::ostream& ::operator<<(std::ostream& stream, const ledger_entry& instance);
  };
}

#endif
