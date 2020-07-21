#ifndef _LTUI_LEDGER_ENTRY_H_
#define _LTUI_LEDGER_ENTRY_H_

#include "./ledger_transaction.hpp"
#include <string>
#include <vector>
#include <memory>
#include "./domain_operator_overloading.hpp"

namespace ltui
{
  class ledger_entry
  {
  public:
    ledger_entry(
        std::string date,
        std::string title,
        std::vector<std::shared_ptr<ledger_transaction>> transactions);

    std::string date;
    std::string title;
    std::vector<std::shared_ptr<ledger_transaction>> transactions;
    friend std::ostream & ::operator<<(std::ostream &stream, const ledger_entry &instance);
  };
} // namespace ltui

#endif
