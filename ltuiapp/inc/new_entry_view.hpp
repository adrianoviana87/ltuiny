#ifndef _LTUI_NEW_ENTRY_VIEW_H_
#define _LTUI_NEW_ENTRY_VIEW_H_

#include "../../domain/inc/ledger_entry_service.hpp"
#include "../inc/list.hpp"
#include "../inc/button.hpp"
#include "./app_settings.hpp"
#include "./entry_dto.hpp"
#include "./view.hpp"
#include "ftxui/component/checkbox.hpp"
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
      struct settings
      {
        bool usePreviousAccount;
        bool removeAccountLeaf;
      };

      new_entry_view(
          std::shared_ptr<ledger_entry_service> service,
          std::shared_ptr<app_settings> settings);

      ftxui::Element Render() override;
    protected:
      virtual void initialize_ui() override;

    private:
      ftxui::Element render_transactions();
      ftxui::Element render_header();
      ftxui::Element render_add_transaction();
      ftxui::Element render_settings();
      void save_transaction();
      void reset_transaction();
      void clear_transaction();
      void save_entry();
      void log(std::wstring message);
      void log(const std::string& message);

      std::shared_ptr<ledger_entry_service> _service;
      std::shared_ptr<app_settings> _settings;
      entry_dto _cur_entry;
      settings _formSettings;
      int _transaction_index;

      ftxui::Container c_container;
      ftxui::Input c_date;
      ftxui::Input c_title;
      ftxui::Input c_account;
      ftxui::Input c_value;
      ftxui::Button c_save_trans;
      ftxui::Button c_cancel_trans;
      ftxui::Button c_from_last_trans;
      ftxui::CheckBox c_usePreviousAccount;
      ftxui::CheckBox c_removeAccountLeaf;
      ftxui::List<entry_trans_dto> c_transactions;
      ftxui::Menu c_log;
      ftxui::Pixel c_space;
  };
}

#endif
