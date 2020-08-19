#ifndef LTUI_DOMAIN_OPERATOR_OVERLOADING_H
#define LTUI_DOMAIN_OPERATOR_OVERLOADING_H

#include <iostream>

namespace ltui {
class ledger_account;
class ledger_amount;
class ledger_transaction;
class ledger_entry;
} // namespace ltui

std::ostream &operator<<(std::ostream &stream,
                         const ltui::ledger_account &instance);
std::ostream &operator<<(std::ostream &stream,
                         const ltui::ledger_amount &instance);
std::ostream &operator<<(std::ostream &stream,
                         const ltui::ledger_transaction &instance);
std::ostream &operator<<(std::ostream &stream,
                         const ltui::ledger_entry &instance);

bool operator<(const ltui::ledger_account &lhs,
               const ltui::ledger_account &rhs);
bool operator==(const ltui::ledger_account &lhs,
                const ltui::ledger_account &rhs);
bool operator!=(const ltui::ledger_account &lhs,
                const ltui::ledger_account &rhs);

#endif
