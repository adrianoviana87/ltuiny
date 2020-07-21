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
            std::cout << prompt;
            parsed_t tmp;
            std::cin >> tmp;

            return tmp;
        }

        template<>
        std::optional<std::string> read(const std::string& prompt)
        {
            std::cout << prompt;
            std::string s;
            std::getline(std::cin, s);

            return s;
        }
    }
}

#endif
