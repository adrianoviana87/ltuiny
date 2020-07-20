#include "../inc/domain_stream_operations.hpp"
#include "../inc/ledger_account.hpp"
#include "../inc/ledger_amount.hpp"
#include "../inc/ledger_transaction.hpp"
#include "../inc/ledger_entry.hpp"

#include <ostream>

using namespace std;
ostream& operator<<(ostream& stream, const ltui::ledger_account& instance)
{
  return stream << instance._val;
}
ostream& operator<<(ostream& stream, const ltui::ledger_amount& instance)
{
  return stream << instance._val << ' ' << instance._commodity;
}

ostream& operator<<(ostream& stream, const ltui::ledger_transaction& instance)
{
  stream << instance._account;
  if (instance._amount)
    stream << "\t\t\t" << *instance._amount;

  return stream;
}

ostream& operator<<(ostream& stream, const ltui::ledger_entry& instance)
{
  stream << instance._date << ' ' << instance._title << '\n';

  for (auto& trans : instance._transactions)
  {
    stream << '\t' << trans << '\n';
  }

  return stream;
}


