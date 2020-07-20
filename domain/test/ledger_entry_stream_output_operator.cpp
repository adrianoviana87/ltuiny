#include "../inc/ledger_entry.hpp"

#include <iostream>

using namespace std;
using namespace ltui;

int main()
{
  auto date = chrono::system_clock::now();
  string title = "My title";

  ledger_transaction trans1(ledger_account("expenses:tests"), ledger_amount("14.4", "BRL"));
  ledger_transaction trans2(ledger_account("budget:tests"), ledger_amount("-14.4", "BRL"));

  ledger_entry entry { date, title, { trans1, trans2 }};

  cout << entry;

  return 0;
}
