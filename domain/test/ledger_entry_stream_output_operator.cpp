#include "../inc/ledger_entry.hpp"

#include <iostream>
#include <optional>

using namespace std;
using namespace ltui;

int main()
{
  auto date = "2020/20/07";
  string title = "My title";

  ledger_transaction trans1(ledger_account("expenses:tests"), make_optional<ledger_amount>("14.4", "BRL"));
  ledger_transaction trans2(ledger_account("budget:tests"), nullopt);

  ledger_entry entry { date, title, { trans1, trans2 }};

  cout << entry;

  return 0;
}
