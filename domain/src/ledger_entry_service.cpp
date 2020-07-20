#include "../inc/ledger_entry_service.hpp"

#include "../inc/ledger_entry.hpp"

namespace ltui
{
  using namespace std;

  ledger_entry_service::ledger_entry_service(
      shared_ptr<ledger_entry_repository> repo)
    : _repo(move(repo))
  {
  }

  void ledger_entry_service::save(const ledger_entry &entry)
  {
    _repo->insert(entry);
  }
}
