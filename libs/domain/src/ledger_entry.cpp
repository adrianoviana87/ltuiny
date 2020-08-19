#include "./ledger_entry.hpp"

#include <memory>

namespace ltui {
ledger_entry::ledger_entry(
    std::string date, std::string title,
    std::vector<std::shared_ptr<ledger_transaction>> transactions)
    : date(std::move(date)), title(std::move(title)),
      transactions(std::move(transactions)) {}
} // namespace ltui
