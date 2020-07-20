#ifndef _LTUI_LEDGER_SERVICE_H_
#define _LTUI_LEDGER_SERVICE_H_

#include "./ledger_entry_repository.hpp"
#include <memory>

namespace ltui
{
  class ledger_entry;

  class ledger_entry_service
  {
    public:
      explicit ledger_entry_service(std::shared_ptr<ledger_entry_repository> repo);
      ledger_entry_service(const ledger_entry_service&) = default;
      ledger_entry_service(ledger_entry_service&&) = default;

      void save(const ledger_entry& entry);
    private:
      std::shared_ptr<ledger_entry_repository> _repo;
  };
}

#endif
