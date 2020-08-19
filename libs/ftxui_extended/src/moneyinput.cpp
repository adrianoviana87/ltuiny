#include "./moneyinput.hpp"
#include <locale>

namespace ftxui {
bool MoneyInput::on_char_typed(wchar_t ch) {
  std::locale loc;

  if (!isdigit(ch, loc) && ch != '.') {
    return false;
  }

  add_char(ch);
  return true;
}
} // namespace ftxui
