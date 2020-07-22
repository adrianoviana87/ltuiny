#ifndef _LTUI_NEW_ENTRY_VIEW_H_
#define _LTUI_NEW_ENTRY_VIEW_H_

#include "../../domain/inc/ledger_entry_service.hpp"
#include "./entry_dto.hpp"
#include "./app_settings.hpp"
#include "./view.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/container.hpp"
#include "ftxui/component/input.hpp"
#include <ftxui/component/menu.hpp>
#include <memory>
#include <vector>

namespace ltui
{
  class new_entry_view : public view
  {
    public:
      new_entry_view(
          std::shared_ptr<ledger_entry_service> service,
          std::shared_ptr<app_settings> settings);

      ftxui::Element Render() override;
      ftxui::Element RenderTransactions();
    protected:
      virtual void initialize_ui() override;

    private:
      void save_transaction();
      std::shared_ptr<ledger_entry_service> _service;
      std::shared_ptr<app_settings> _settings;
      entry_dto _cur_entry;

      ftxui::Container c_container;
      ftxui::Input c_date;
      ftxui::Input c_title;
      ftxui::Input c_account;
      ftxui::Input c_value;
      ftxui::Menu c_save_trans;
  };
}

#endif
