#ifndef _LTUI_ENTRY_DTO_H_
#define _LTUI_ENTRY_DTO_H_

#include <string>
#include <optional>
#include <vector>

namespace ltui
{
  struct entry_trans_dto
  {
    std::string account;
    std::string value;
    std::string commodity;
  };

  struct entry_dto
  {
    std::string date;
    std::string title;
    std::vector<entry_trans_dto> transactions;
  };
} // namespace ltui

#endif
