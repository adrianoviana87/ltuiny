#ifndef LTUI_LEDGER_ENTRY_SERVICE_H
#define LTUI_LEDGER_ENTRY_SERVICE_H

#include "crosscutting.hpp"
#include "./ledger_entry_repository.hpp"
#include <memory>
#include <vector>

namespace ltui {
class ledger_entry;

class ledger_entry_service {
public:
  explicit ledger_entry_service(std::shared_ptr<ledger_entry_repository> repo);
  ledger_entry_service(const ledger_entry_service &) = default;
  ledger_entry_service(ledger_entry_service &&) = default;
  ledger_entry_service &operator=(const ledger_entry_service &) = default;
  ledger_entry_service &operator=(ledger_entry_service &&) NOEXCEPT = default;
  ~ledger_entry_service() = default;

  void save(std::shared_ptr<ledger_entry> entry);
  [[nodiscard]] std::shared_ptr<ledger_entry> get_last_entry() const;
  [[nodiscard]] const std::vector<std::shared_ptr<ledger_entry>>&
  get_entries() const;

private:
  std::vector<std::shared_ptr<ledger_entry>> _saved_entries;
  std::shared_ptr<ledger_entry_repository> _repo;
};
} // namespace ltui

#endif
