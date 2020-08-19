#include "./ledger_account.hpp"

#include <memory>

namespace ltui {
ledger_account::ledger_account(std::string val) : _val(std::move(val)) {}

std::string ledger_account::to_string() const { return _val; }
} // namespace ltui
