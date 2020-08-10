#include "../inc/input.hpp"
#include <cassert>
#include <string>

int main() {
  auto integer = ltui::input::read<int>("integer: ");
  auto str = ltui::input::read<std::string>("str: ");

  assert(integer.has_value());
  assert(integer.value() == 10);

  assert(str.has_value());
  assert(str.value() == "adriano");

  std::cout << "integer: " << *integer << '\n' << "str: " << *str << '\n';

  return 0;
}
