#ifndef LTUI_LEDGER_ENTRY_REPOSITORY_H
#define LTUI_LEDGER_ENTRY_REPOSITORY_H

#include "crosscutting.hpp"
namespace ltui {
class ledger_entry;

struct ledger_entry_repository {
  ledger_entry_repository() = default;
  ledger_entry_repository(const ledger_entry_repository &) = default;
  ledger_entry_repository(ledger_entry_repository &&) = default;
  ledger_entry_repository &operator=(const ledger_entry_repository &) = default;
  ledger_entry_repository &
  operator=(ledger_entry_repository &&) NOEXCEPT = default;
  virtual ~ledger_entry_repository() = default;

  virtual void insert(const ledger_entry &entry) = 0;
};
} // namespace ltui

#endif
