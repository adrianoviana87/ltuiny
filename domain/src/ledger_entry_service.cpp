#include "../inc/ledger_entry_service.hpp"

#include "../inc/ledger_entry.hpp"

namespace ltui {
ledger_entry_service::ledger_entry_service(
    std::shared_ptr<ledger_entry_repository> repo)
    : _repo(move(repo)) {}

void ledger_entry_service::save(std::shared_ptr<ledger_entry> entry) {
  _repo->insert(*entry);
  _saved_entries.push_back(std::move(entry));
}

std::shared_ptr<ledger_entry> ledger_entry_service::get_last_entry() const {
  if (_saved_entries.empty()) {
    return nullptr;
  }

  return _saved_entries.back();
}

const std::vector<std::shared_ptr<ledger_entry>> &
ledger_entry_service::get_entries() const {
  return _saved_entries;
}
} // namespace ltui
