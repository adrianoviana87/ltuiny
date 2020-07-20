#ifndef _LTUI_LEDGER_AMOUNT_H_
#define _LTUI_LEDGER_AMOUNT_H_

#include <string>
#include <iosfwd>

namespace ltui
{
  class ledger_amount
  {
    public:
      ledger_amount(std::string val, std::string commodity);
      ledger_amount(const ledger_amount&) = default;
      ledger_amount(ledger_amount&&) = default;
    private:
      std::string _val;
      std::string _commodity;
      friend std::ostream& operator<<(std::ostream& stream, const ledger_amount& instance);
  };
}

#endif

