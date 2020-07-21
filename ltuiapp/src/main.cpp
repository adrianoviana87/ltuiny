#include "../../data/inc/ledger_entry_file_repository.hpp"
#include "../../domain/inc/ledger_entry_service.hpp"
#include "../inc/add_invoice_view.hpp"
#include "../inc/home_view.hpp"
#include "../inc/router.hpp"
#include <any>
#include <memory>

using namespace ltui;

int main()
{
    auto entry_repo = std::make_shared<ledger_entry_file_repository>("data.dat");
    auto entry_service = std::make_shared<ledger_entry_service>(entry_repo);

    auto app_router = std::make_shared<router>();
    app_router->add_route(
        "",
        [&](auto _) { return std::make_shared<home_view>(app_router); })
    .add_route(
        "ledger_entry/new",
        [&](auto _) { return std::make_shared<add_invoice_view>(entry_service); });

    app_router->navigate("", std::any());

    return 0;
}