#include "../inc/dateinput.hpp"
#include <locale>

namespace ftxui {
bool DateInput::on_char_typed(wchar_t ch) {
  std::locale loc;

  if (!isdigit(ch, loc)) {
    return false;
  }

  const auto& content = get_content();
  constexpr auto max_size = 10;
  if (content.size() == max_size) {
    return false;
  }

  constexpr auto first_part_length = 3;
  if (content.size() < first_part_length) {
    add_char(ch);
    return true;
  }

  if (content.size() == first_part_length) {
    add_char(ch);
    add_char('-');
    return true;
  }

  constexpr auto second_part_length = 6;
  if (content.size() < second_part_length) {
    add_char(ch);
    return true;
  }

  if (content.size() == second_part_length) {
    add_char(ch);
    add_char('-');
    return true;
  }

  add_char(ch);
  return true;
}
}
