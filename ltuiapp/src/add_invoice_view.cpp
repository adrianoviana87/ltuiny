#include "../inc/add_invoice_view.hpp"

#include <iostream>

namespace ltui
{

    add_invoice_view::add_invoice_view(std::shared_ptr<ledger_entry_service> service)
        : _service(std::move(service))
    {
    }

    void add_invoice_view::on_show()
    {
        std::cout << "this is an add invoice view";
    }


}