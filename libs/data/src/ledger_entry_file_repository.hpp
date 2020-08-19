#ifndef LTUI_LEDGER_ENTRY_FILE_REPOSITORY_H
#define LTUI_LEDGER_ENTRY_FILE_REPOSITORY_H

#include "domain.hpp"

#include <string>

namespace ltui {
class ledger_entry_file_repository : public ledger_entry_repository {
public:
  explicit ledger_entry_file_repository(std::string file_path);
  void insert(const ledger_entry &entry) override;

private:
  std::string _file_path;
};
} // namespace ltui

#endif
