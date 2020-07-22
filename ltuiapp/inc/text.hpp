#ifndef _LTUI_TEXT_H_
#define _LTUI_TEXT_H_
#include <string>

namespace ltui
{
  std::wstring to_wstr(const std::string& str);
  std::string to_str(const std::wstring& wstr);
}

#endif
