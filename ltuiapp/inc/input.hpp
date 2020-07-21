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
            std::stringstream ss;
            std::string s;
            std::getline(std::cin, s);

            parsed_t inst;
            ss >> inst;

            return inst;
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