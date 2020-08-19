#include "domain.hpp"

#include <iostream>
#include <memory>
#include <optional>

using namespace std;
using namespace ltui;

int main() {
  constexpr auto date = "2020/20/07";
  string title = "My title";

  auto trans1 = make_shared<ledger_transaction>(
      ledger_account("expenses:tests"),
      make_optional<ledger_amount>("14.4", "BRL"));
  auto trans2 =
      make_shared<ledger_transaction>(ledger_account("budget:tests"), nullopt);

  ledger_entry entry{date, title, {trans1, trans2}};

  cout << entry;

  return 0;
}
