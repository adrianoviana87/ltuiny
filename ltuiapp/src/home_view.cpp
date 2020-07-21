#include "../inc/home_view.hpp"
#include <iostream>
#include <memory>

using namespace std;

namespace ltui
{
    void show_menu()
    {
        cout << "--- LTUI ---\n"
        << "0 - Quit\n"
        << "1 - Add new transaction\n";
    }

    int read_choice()
    {
        cout << "> ";
        int choice = 0;
        cin >> choice;
        if (choice < 0 || choice > 1)
            return read_choice();

        return choice;
    }

    home_view::home_view(std::shared_ptr<router> router)
        : _router(std::move(router))
    {
    }

    void home_view::on_show()
    {
        int choice = -1;
        while (true)
        {
            show_menu();
            int choice = read_choice();
            switch (choice)
            {
            case 0:
                return;
            case 1:
                _router->navigate("ledger_entry/new", std::any());
                break;
                // TODO: dispatch
            }
        }
    }
}
