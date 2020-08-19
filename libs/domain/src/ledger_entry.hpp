#ifndef LTUI_LEDGER_ENTRY_H
#define LTUI_LEDGER_ENTRY_H

#include "./domain_operator_overloading.hpp"
#include "./ledger_transaction.hpp"
#include <memory>
#include <string>
#include <vector>

namespace ltui {
class ledger_entry {
public:
  ledger_entry(std::string date, std::string title,
               std::vector<std::shared_ptr<ledger_transaction>> transactions);

private:
  std::string date;
  std::string title;
  std::vector<std::shared_ptr<ledger_transaction>> transactions;
  friend std::ostream & ::operator<<(std::ostream &stream,
                                     const ledger_entry &instance);
};
} // namespace ltui

#endif
