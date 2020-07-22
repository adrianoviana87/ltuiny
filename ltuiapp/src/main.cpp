#include "../../data/inc/ledger_entry_file_repository.hpp"
#include "../../domain/inc/ledger_entry_service.hpp"
#include "../inc/home_view.hpp"
#include "../inc/new_entry_view.hpp"
#include "../inc/screen_service.hpp"
#include "../inc/router.hpp"
#include <any>
#include <memory>
#include "../inc/app_settings.hpp"

using namespace ltui;

int main()
{
    auto settings = std::make_shared<app_settings>();
    settings->default_commodity = "BRL";

    auto entry_repo = std::make_shared<ledger_entry_file_repository>("data.dat");
    auto entry_service = std::make_shared<ledger_entry_service>(entry_repo);

    auto screen_srv = std::make_shared<screen_service>();
    auto app_router = std::make_shared<router>(screen_srv);
    app_router->add_route(
        "",
        [&](auto _) { return std::make_shared<home_view>(app_router); })
    .add_route(
        "ledger_entry/new",
        [&](auto _) { return std::make_shared<new_entry_view>(entry_service, settings); });

    app_router->navigate("", std::any());

    return 0;
}
