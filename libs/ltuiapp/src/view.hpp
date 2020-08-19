#ifndef LTUI_VIEW_H
#define LTUI_VIEW_H

#include "crosscutting.hpp"
#include "ftxui/component/component.hpp"

#include <functional>

namespace ltui {
class view : public ftxui::Component {
public:
  view() = default;
  view(const view&) = default;
  view(view&&) NOEXCEPT = default;
  ~view() NOEXCEPT override = default;
  view& operator=(const view&) = default;
  view& operator=(view&&) NOEXCEPT = default;

  void initialize();
  void set_on_close(std::function<void()> val);
protected:
  void close();
  virtual void initialize_ui() = 0;
private:
  std::function<void()> on_close;
};
} // namespace ltui

#endif
