#ifndef _LTUI_ADD_INVOICE_VIEW_H_
#define _LTUI_ADD_INVOICE_VIEW_H_

#include "./view.hpp"
#include "./entry_dto.hpp"
#include "../../domain/inc/ledger_entry_service.hpp"
#include "./app_settings.hpp"
#include <memory>
#include <optional>
#include <string>

namespace ltui
{
    struct add_invoice_view : public view
    {
        virtual void on_show() override;
        add_invoice_view(
            std::shared_ptr<ledger_entry_service> service,
            std::shared_ptr<const app_settings> settings);

    private:
        std::optional<entry_dto> read_entry();
        std::optional<std::vector<entry_trans_dto>> read_transactions();
        std::optional<entry_trans_dto> read_transaction();
        std::optional<std::string> read_account();
        std::optional<std::string> read_commodity();
        std::shared_ptr<ledger_entry_service> _service;
        std::shared_ptr<const app_settings> _settings;
    };
} // namespace ltui

#endif
