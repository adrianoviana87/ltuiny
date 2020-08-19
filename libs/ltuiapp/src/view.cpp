#include "./view.hpp"
#include "ftxui/dom/elements.hpp"
#include <memory>

namespace ltui {
using namespace ftxui;

void view::initialize() { this->initialize_ui(); }

void view::close() { on_close(); }
void view::set_on_close(std::function<void()> val) {
  on_close = std::move(val);
}
} // namespace ltui
