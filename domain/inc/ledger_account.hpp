#ifndef _LTUI_LEDGER_ACCOUNT_H_
#define _LTUI_LEDGER_ACCOUNT_H_

#include <string>
#include <iosfwd>

namespace ltui
{
  class ledger_account
  {
    public:
      explicit ledger_account(std::string val);
      ledger_account(const ledger_account&) = default;
      ledger_account(ledger_account&&) = default;
    private:
      std::string _val;
      friend std::ostream& operator<<(std::ostream& stream, const ledger_account& instance);
  };
}

#endif
