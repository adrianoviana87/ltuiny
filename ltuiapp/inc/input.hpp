#ifndef _LTUI_INPUT_H_
#define _LTUI_INPUT_H_

#include <string>
#include <optional>
#include <sstream>
#include <iostream>

namespace ltui
{
  namespace input
  {
    template<class parsed_t>
      std::optional<parsed_t> read(const std::string& prompt)
      {
        parsed_t tmp;
        do {
          std::cin.clear();
          std::cout << prompt;
          std::cin >> tmp;
        } while (!std::cin);

        return tmp;
      }

    template<>
      std::optional<std::string> read(const std::string& prompt)
      {
        std::cin.clear();
        std::cin.ignore(8, '\n');

        std::cout << prompt;
        std::string s;
        std::getline(std::cin, s);

        if (s.empty())
          return std::nullopt;
        return s;
      }
  }
}

#endif
