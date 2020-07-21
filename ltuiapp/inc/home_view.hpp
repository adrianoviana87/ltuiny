#ifndef _LTUI_HOME_VIEW_H_
#define _LTUI_HOME_VIEW_H_

#include "./view.hpp"
#include "./router.hpp"

#include <memory>

namespace ltui
{
  struct home_view : public view
  {
    explicit home_view(std::shared_ptr<router> router);
    virtual void on_show() override;
    private:
      std::shared_ptr<router> _router;
  };
}

#endif
