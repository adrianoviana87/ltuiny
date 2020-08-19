#include "./ledger_entry_file_repository.hpp"
#include "domain.hpp"

#include <fstream>
#include <memory>

namespace ltui {
using namespace std;

ledger_entry_file_repository::ledger_entry_file_repository(string file_path)
    : _file_path(move(file_path)) {}

void ledger_entry_file_repository::insert(const ledger_entry &entry) {
  fstream stream(_file_path, ios::app | ios::ate);

  if (stream.good()) {
    stream << entry;
  }
}
} // namespace ltui
