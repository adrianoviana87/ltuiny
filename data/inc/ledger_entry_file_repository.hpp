#ifndef _LTUI_LEDGER_ENTRY_FILE_REPOSITORY_H_
#define _LTUI_LEDGER_ENTRY_FILE_REPOSITORY_H_

#include "../../domain/inc/ledger_entry_repository.hpp"

#include <string>

namespace ltui
{
  class ledger_entry_file_repository : public ledger_entry_repository
  {
    public:
      explicit ledger_entry_file_repository(std::string file_path);
      virtual void insert(const ledger_entry& entry) override;
    private:
      std::string _file_path;
  };
}

#endif
