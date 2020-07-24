#include "../inc/string-utils.hpp"

#include <locale>
#include <codecvt>

namespace ltui
{
  std::wstring to_wstr(const std::string& str)
  {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring wide = converter.from_bytes(str);
    return wide;
  }

  std::string to_str(const std::wstring& wstr)
  {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::string narrow = converter.to_bytes(wstr);
    return narrow;
  }

  std::vector<std::string> split_str(const std::string& s, char delimiter)
  {
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
      tokens.push_back(token);
    }

    return tokens;
  }
}

