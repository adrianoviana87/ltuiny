#include "../inc/add_invoice_view.hpp"
#include "../inc/input.hpp"

#include "../../domain/inc/ledger_entry.hpp"

#include "../../extern/boolinq.h"

#include <iostream>
#include <vector>
#include <optional>
#include <iomanip>
#include <memory>

using namespace boolinq;

namespace ltui
{
  std::optional<std::string> read_account_with_existing(const std::vector<std::shared_ptr<ledger_entry>> &existing_entries)
  {
    auto accounts = from(existing_entries)
                        .selectMany([](auto &entry) { return entry->transactions; })
                        .select([](auto &trans) { return &trans->account; })
                        .distinct()
                        .toStdVector();

    auto i = 0;

    for (auto item : accounts)
    {
      std::cout << '(' << std::setfill(' ') << std::setw(2) << i;
      std::cout << ") - " << *item;
      ++i;
    }

  pickindex:
    auto choice = input::read<int>("choose account index: ");
    if (!choice)
      return std::nullopt;

    if (*choice < 0 || *choice > accounts.size() - 1)
      goto pickindex;
    else
      return accounts[*choice]->to_string();
  }

  add_invoice_view::add_invoice_view(
    std::shared_ptr<ledger_entry_service> service,
    std::shared_ptr<const app_settings> settings)
      : _service(std::move(service)),
      _settings(std::move(settings))
  {
  }

  std::optional<std::string> add_invoice_view::read_commodity()
  {
    std::cout << "commodity";
    if (!_settings->default_commodity.empty())
      std::cout << " = " << _settings->default_commodity;

    auto buff = input::read<std::string>(": ");

    if (!buff && !_settings->default_commodity.empty())
      return _settings->default_commodity;

    return buff;
  }

  std::optional<std::vector<entry_trans_dto>> add_invoice_view::read_transactions()
  {
    std::vector<entry_trans_dto> trans;
    std::optional<entry_trans_dto> buff;
    std::cout << "-- transactions --\n";

    while (buff = read_transaction())
    {
      trans.push_back(*buff);
    }

    if (trans.empty())
      return std::nullopt;

    return trans;
  }

  std::optional<entry_trans_dto> add_invoice_view::read_transaction()
  {
    std::cout << "- add transaction -\n";
    auto buff = read_account();
    if (!buff)
      return std::nullopt;

    entry_trans_dto dto;
    dto.account = *buff;

    dto.value = input::read<std::string>("value: ");

    if (dto.value)
      dto.commodity = read_commodity();

    return dto;
  }

  std::optional<std::string> add_invoice_view::read_account()
  {
    std::cout << "account:\n"
              << "(0) - Cancel\n"
              << "(1) - Enter whole new\n"
              << "(2) - List existing\n";
    auto choice = input::read<int>("> ");
    if (!choice)
      return std::nullopt;

    switch (*choice)
    {
    case 0:
      return std::nullopt;
    case 1:
      return input::read<std::string>("whole account: ");
    case 2:
      return read_account_with_existing(_service->get_entries());
    default:
      return read_account();
    }
  }

  std::optional<entry_dto> add_invoice_view::read_entry()
  {
    std::cout << "--- add entry ---\n";
    std::optional<std::string> buff = input::read<std::string>("date");
    if (!buff)
      return std::nullopt;

    entry_dto entry;
    entry.date = *buff;

    buff = input::read<std::string>("title");
    if (!buff)
      return std::nullopt;
    entry.title = *buff;

    auto trans = read_transactions();

    if (!trans)
      return std::nullopt;

    entry.transactions = std::move(*trans);
    return entry;
  }

  void add_invoice_view::on_show()
  {
    auto entry = read_entry();

    if (!entry)
      return;

    auto trans = from(entry->transactions).select([](auto& t) {
      ledger_account account(t.account);
      std::optional<ledger_amount> amount;
      if (t.value) {
        amount.emplace(*t.value, t.commodity.value());
      }

      return std::make_shared<ledger_transaction>(ledger_account(t.account), amount);
    }).toStdVector();

    auto entity = std::make_shared<ledger_entry>(
      entry->date,
      entry->title,
      trans);

    _service->save(entity);
  }

} // namespace ltui
