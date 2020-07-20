#include "../inc/ledger_entry_file_repository.hpp"
#include "../../domain/inc/ledger_entry.hpp"

#include <string>

using namespace ltui;
using namespace std;

int main()
{
  string file_path = "test-file.dat";
  ledger_entry_file_repository repo { file_path };

  return 0;
}
