#include "../inc/app.hpp"

#include <iostream>

using namespace std;

enum class menu_action
{
  quit = 0,
  add_transaction
};

void display_menu();
menu_action get_choice();
void process_menu_action(menu_action choice);

namespace ltui
{
  app::app(shared_ptr<ledger_service> service)
    : _service(move(service))
  {
  }

  void app::run()
  {
    menu_action choice;

    while (true)
    {
      display_menu();
      choice = get_choice();
      if (choice != menu_action::quit)
        process_menu_action(this);
    }
  }

void display_menu()
{
  cout << "LTUI\n"
    << "--- MAIN MENU ---\n"
    << "(0) - quit\n"
    << "(1) - add transaction\n";
}

menu_action get_choice()
{
  cout << "choice: ";
  int choice = 0;
  cin >> choice;
  if (choice >= 0 && choice <= 1)
    return static_cast<menu_action>(choice);

  return get_choice();
}

void process_menu_action(menu_action choice)
{
  switch (choice)
  {
    case menu_action::add_transaction:
      add_transaction(app& app);
  }
}
