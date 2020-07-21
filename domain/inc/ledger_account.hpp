#ifndef _LTUI_LEDGER_ACCOUNT_H_
#define _LTUI_LEDGER_ACCOUNT_H_

#include <string>
#include "./domain_operator_overloading.hpp"

namespace ltui
{
  class ledger_account
  {
    public:
      explicit ledger_account(std::string val);
      ledger_account(const ledger_account&) = default;
      ledger_account(ledger_account&&) = default;
      std::string to_string() const;
    private:
      std::string _val;
      friend std::ostream& ::operator<<(std::ostream& stream, const ledger_account& instance);
      friend bool ::operator<(const ledger_account& lhs, const ledger_account& rhs);
      friend bool ::operator==(const ledger_account& lhs, const ledger_account& rhs);
      friend bool ::operator!=(const ledger_account& lhs, const ledger_account& rhs);
  };
}

#endif
