#ifndef _LTUI_APP_SERVICE_H_
#define _LTUI_APP_SERVICE_H_

#include <string>
#include <memory>
#include "../../domain/inc/ledger_service.hpp"

namespace ltui
{
  class app
  {
    public:
      explicit app(std::shared_ptr<ledger_service> service);
      void run();
    private:
      std::shared_ptr<ledger_service> _service;
  };
}

#endif
