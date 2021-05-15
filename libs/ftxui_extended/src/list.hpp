#ifndef LTUI_LIST_H
#define LTUI_LIST_H

#include <algorithm>
#include <ftxui/component/event.hpp>
#include <memory>
#include "crosscutting.hpp"
#include "ftxui/component/component.hpp"

namespace ftxui {
template <class t_item>
class List : public ComponentBase {
 public:
  List() = default;
  List(const List &) = default;
  List(List &&) NOEXCEPT = default;
  ~List() override = default;

  List &operator=(const List &) = default;
  List &operator=(List &&) NOEXCEPT = default;

  [[nodiscard]] int get_selected_index() const { return selected; }

  void set_style(Decorator val) { normal_style = std::move(val); }

  void set_items(std::vector<t_item> *val) { items = val; }

  void set_on_enter(std::function<void(const t_item &item)> val) {
    on_enter = std::move(val);
  }

  void set_render_item(std::function<Element(const t_item &)> val) {
    render_item = std::move(val);
  }

  // Component implementation.
  Element Render() override {
    if (items == nullptr) {
      return text(L"No items");
    }

    std::vector<Element> elements;

    bool is_focused = Focused();
    for (size_t i = 0; i < items->size(); ++i) {
      auto style = (selected != int(i))
                       ? normal_style
                       : is_focused ? focused_style : selected_style;
      auto focused =
          (selected != int(i)) ? nothing : is_focused ? focus : select;
      elements.push_back(render_item(items->at(i)) | style | focused);
    }

    return vbox(std::move(elements));
  }

  bool OnEvent(Event event) override {
    if (!Focused()) {
      return false;
    }

    int old_selected = selected;
    if (event == Event::ArrowUp || event == Event::Character('k')) {
      selected--;
    }

    if (event == Event::ArrowDown || event == Event::Character('j')) {
      selected++;
    }

    if (event == Event::Tab && items->size()) {
      selected = (selected + 1) % items->size();
    }

    if (event == Event::TabReverse && items->size()) {
      selected = (selected + items->size() - 1) % items->size();
    }

    selected = std::max(0, std::min(int(items->size()) - 1, selected));

    if (event == Event::Return && selected >= 0) {
      on_enter(items->at(selected));
      return true;
    }

    return false;
  }

private:
  // State.
  int selected = 0;
  std::vector<t_item> *items;
  std::function<Element(const t_item &)> render_item =
      [](const t_item & /*item*/) { return text(L"Item"); };

  Decorator focused_style = inverted;
  Decorator selected_style = bold;
  Decorator normal_style = nothing;

  // State update callback.
  std::function<void(const t_item &)> on_enter = [](const t_item &item) {};
};
} // namespace ftxui

#endif
