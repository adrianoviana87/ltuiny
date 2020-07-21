#ifndef _LTUI_ADD_INVOICE_VIEW_H_
#define _LTUI_ADD_INVOICE_VIEW_H_

#include "./view.hpp"

#include "../../domain/inc/ledger_entry_service.hpp"

#include <memory>

namespace ltui
{
   struct add_invoice_view : public view
   {
       virtual void on_show() override;
       explicit add_invoice_view(
           std::shared_ptr<ledger_entry_service> service);
       private:
           std::shared_ptr<ledger_entry_service> _service;
   };
}

#endif
