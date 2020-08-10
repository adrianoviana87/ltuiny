#ifndef _LTUI_INPUT_H_
#define _LTUI_INPUT_H_

#include <iostream>
#include <optional>
#include <sstream>
#include <string>

namespace ltui::input {
template <class parsed_t>
std::optional<parsed_t> read(const std::string &prompt) {
  parsed_t tmp;
  do {
    std::cin.clear();
    std::cout << prompt;
    std::cin >> tmp;
  } while (!std::cin);

  return tmp;
}

template <> inline std::optional<std::string> read(const std::string &prompt) {
  std::cin.clear();
  constexpr auto bytes_to_ignore = 8;
  std::cin.ignore(bytes_to_ignore, '\n');

  std::cout << prompt;
  std::string s;
  std::getline(std::cin, s);

  if (s.empty()) {
    return std::nullopt;
  }

  return s;
}
} // namespace ltui

#endif
