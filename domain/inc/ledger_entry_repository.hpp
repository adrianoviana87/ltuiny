#ifndef _LTUI_LEDGER_REPOSITORY_H_
#define _LTUI_LEDGER_REPOSITORY_H_

namespace ltui
{
  class ledger_entry;

  struct ledger_entry_repository
  {
    virtual void insert(const ledger_entry& entry) = 0;
    virtual ~ledger_entry_repository() = default;
  };
}

#endif
