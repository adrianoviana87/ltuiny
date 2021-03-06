#ifndef LTUI_STRING_UTILS_H
#define LTUI_STRING_UTILS_H

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

namespace ltui {
std::wstring to_wstr(const std::string &str);
std::string to_str(const std::wstring &wstr);

std::vector<std::string> split_str(const std::string &s, char delimiter);

template <class t_iter> std::string join_str(t_iter beg, t_iter end, char ch) {
  std::string buff;
  if (beg == end) {
    return *beg;
  }

  for (auto p = beg; p != end; ++p) {
    buff += *p;
    if (p != end - 1) {
      buff += ch;
    }
  }

  return buff;
}

template<typename t>
bool str_parse(const std::string& str, t& instance) {
  std::stringstream ss { str };
  ss >> instance;
  return true;
}
} // namespace ltui

#endif
