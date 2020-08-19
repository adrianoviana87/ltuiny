#include "./domain_operator_overloading.hpp"
#include "./ledger_account.hpp"
#include "./ledger_amount.hpp"
#include "./ledger_entry.hpp"
#include "./ledger_transaction.hpp"

#include <ostream>

using namespace std;
ostream &operator<<(ostream &stream, const ltui::ledger_account &instance) {
  return stream << instance._val;
}
ostream &operator<<(ostream &stream, const ltui::ledger_amount &instance) {
  return stream << instance._val << ' ' << instance._commodity;
}

ostream &operator<<(ostream &stream, const ltui::ledger_transaction &instance) {
  stream << instance.account;
  if (instance.amount) {
    stream << "\t\t\t" << *instance.amount;
  }

  return stream;
}

ostream &operator<<(ostream &stream, const ltui::ledger_entry &instance) {
  stream << instance.date << ' ' << instance.title << '\n';

  for (const auto &trans : instance.transactions) {
    stream << '\t' << *trans << '\n';
  }

  return stream;
}

bool operator<(const ltui::ledger_account &lhs,
               const ltui::ledger_account &rhs) {
  return lhs._val < rhs._val;
}

bool operator==(const ltui::ledger_account &lhs,
                const ltui::ledger_account &rhs) {
  return lhs._val == rhs._val;
}

bool operator!=(const ltui::ledger_account &lhs,
                const ltui::ledger_account &rhs) {
  return lhs._val != rhs._val;
}
