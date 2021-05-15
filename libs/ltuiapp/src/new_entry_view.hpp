#ifndef LTUI_NEW_ENTRY_VIEW_H
#define LTUI_NEW_ENTRY_VIEW_H

#include <ftxui/component/menu.hpp>
#include <memory>
#include <vector>
#include "./app_settings.hpp"
#include "./entry_dto.hpp"
#include "./view.hpp"
#include "domain.hpp"
#include "ftxui-extended.hpp"
#include "ftxui/component/button.hpp"
#include "ftxui/component/checkbox.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/container.hpp"
#include "ftxui/component/input.hpp"

namespace ltui {
using namespace ftxui;
class new_entry_view : public view {
public:
  new_entry_view(std::shared_ptr<ledger_entry_service> service,
                 std::shared_ptr<app_settings> settings);

  ftxui::Element Render() override;

protected:
  void initialize_ui() override;

private:
  ftxui::Element render_transactions();
  ftxui::Element render_header();
  ftxui::Element render_add_transaction();
  ftxui::Element render_settings();
  ftxui::Element render_toolbar();

  bool save_transaction();
  void reset_transaction();
  void clear_transaction();
  void save_entry();
  void clear_form();

  std::shared_ptr<ledger_entry_service> _service;
  std::shared_ptr<app_settings> _settings;
  std::vector<entry_trans_dto> _transactions;
  int _transaction_index;

  std::shared_ptr<ButtonExt> c_save_entry = Make<ButtonExt>();
  std::shared_ptr<ButtonExt> c_clear_form = Make<ButtonExt>();
  std::shared_ptr<ButtonExt> c_quit = Make<ButtonExt>();
  std::shared_ptr<DateInput> c_date = Make<DateInput>();

  std::wstring c_title_content;
  Component c_title = Input(&c_title_content, "title");

  std::wstring c_account_content;
  Component c_account = Input(&c_account_content, "account");

  std::shared_ptr<MoneyInput> c_value = Make<MoneyInput>();

  std::wstring c_commodity_content;
  Component c_commodity= Input(&c_commodity_content, "commodity");

  std::shared_ptr<ButtonExt> c_save_trans = Make<ButtonExt>();
  std::shared_ptr<ButtonExt> c_cancel_trans = Make<ButtonExt>();
  std::shared_ptr<ButtonExt> c_from_last_trans = Make<ButtonExt>();

  bool c_usePreviousAccountState = true;
  Component c_usePreviousAccount =
      Checkbox("Use Previous Account", &c_usePreviousAccountState);

  bool c_removeAccountLeafState = true;
  Component c_removeAccountLeaf =
      Checkbox("Remove Account leaf", &c_removeAccountLeafState);

  std::shared_ptr<List<entry_trans_dto>> c_transactions =
      Make<List<entry_trans_dto>>();
  Pixel c_space;
};
} // namespace ltui

#endif
