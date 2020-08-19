#include "./ledger_amount.hpp"

#include <memory>

namespace ltui {
ledger_amount::ledger_amount(std::string val, std::string commodity)
    : _val(std::move(val)), _commodity(std::move(commodity)) {}
} // namespace ltui
