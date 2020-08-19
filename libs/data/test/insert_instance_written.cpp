#include "domain.hpp"
#include "data.hpp"

#include <memory>
#include <string>

using namespace ltui;
using namespace std;

int main() {
  string file_path = "test-file.dat";
  ledger_entry_file_repository repo{file_path};

  constexpr auto date = "2020/20/07";
  string title = "My title";

  auto trans1 = make_shared<ledger_transaction>(
      ledger_account("expenses:tests"),
      make_optional<ledger_amount>("14.4", "BRL"));
  auto trans2 =
      make_shared<ledger_transaction>(ledger_account("budget:tests"), nullopt);

  ledger_entry entry{date, title, {trans1, trans2}};

  repo.insert(entry);
  return 0;
}
