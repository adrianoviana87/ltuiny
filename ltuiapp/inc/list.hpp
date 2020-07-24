#ifndef _LTUI_FTXUI_LIST_H_
#define _LTUI_FTXUI_LIST_H_

#include <algorithm>

#include "ftxui/component/component.hpp"

namespace ftxui {
template<class t_item>
class List : public Component
{
public:
  // Constructor.
  List() = default;
  ~List() override = default;

  // State.
  int selected = 0;
  std::vector<t_item> *items;
  std::function<Element(const t_item &)> render_item = [](const t_item &item) { return text(L"Item"); };

  Decorator focused_style = inverted;
  Decorator selected_style = bold;
  Decorator normal_style = nothing;

  // State update callback.
  std::function<void()> on_change = []() {};
  std::function<void(const t_item &)> on_enter = [](const t_item &item) {};

  // Component implementation.
  Element Render() override
  {
    if (items == nullptr) {
      return text(L"No items");
    }

    std::vector<Element> elements;

    bool is_focused = Focused();
    for (size_t i = 0; i < items->size(); ++i) {
      auto style = (selected != int(i))
                     ? normal_style
                     : is_focused ? focused_style : selected_style;
      auto focused = (selected != int(i)) ? nothing : is_focused ? focus : select;
      elements.push_back(render_item(items->at(i)) | style | focused);
    }
    return vbox(std::move(elements));
  }

  bool OnEvent(Event event) override
  {
    if (!Focused())
      return false;

    int old_selected = selected;
    if (event == Event::ArrowUp || event == Event::Character('k'))
      selected--;
    if (event == Event::ArrowDown || event == Event::Character('j'))
      selected++;
    if (event == Event::Tab && items->size())
      selected = (selected + 1) % items->size();
    if (event == Event::TabReverse && items->size())
      selected = (selected + items->size() - 1) % items->size();

    selected = std::max(0, std::min(int(items->size()) - 1, selected));

    if (selected != old_selected) {
      on_change();
      return true;
    }

    if (event == Event::Return && selected >= 0) {
      on_enter(items->at(selected));
      return true;
    }

    return false;
  }
};
}// namespace ftxui

#endif