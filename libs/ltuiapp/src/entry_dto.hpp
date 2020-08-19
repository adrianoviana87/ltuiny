#ifndef LTUI_ENTRY_DTO_H
#define LTUI_ENTRY_DTO_H

#include <string>
#include <vector>

namespace ltui
{
  struct entry_trans_dto
  {
    std::string account;
    std::string value;
    std::string commodity;
    double numericValue;
  };

  struct entry_dto
  {
    std::string date;
    std::string title;
    std::vector<entry_trans_dto> transactions;
  };
} // namespace ltui

#endif
