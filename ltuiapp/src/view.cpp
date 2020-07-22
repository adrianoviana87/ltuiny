#include "../inc/view.hpp"
#include "ftxui/dom/elements.hpp"

namespace ltui
{
  using namespace ftxui;

  view::view()
  {
  }

  void view::initialize()
  {
    this->initialize_ui();
  }

  void view::close()
  {
    closed();
  }
}
