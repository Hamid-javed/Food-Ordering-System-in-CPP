#include "admin.h"
#include <cstdlib> // for system("pause")
#include <iostream>
#include "utils.h"
#include "bill.h"

using namespace std;

admin::admin()
{
    id = "123";
    apass = "admin";
}

void admin::show()
{
    cout << "just for formality";
}

bool admin::login(const string &ai, const string &pa)
{
    return (ai == id && pa == apass);
}

void admin::control_panel()
{
    bill obj;
    while (true)
    {
        system("pause");
        cls();
        cout << "\n-------------------------------------------------------------\n";
        cout << "[1]: Edit stocks\n[2]: Check stocks\n[3]: Edit employee number\n[4]: Check total employees\n[5]: Total Bills\n";
        cout << "[6]: Check Feedbacks\n[7]: Exit\n\n";

        int v;
        cin >> v;

        switch (v)
        {
        case 1:
        {
            int tst;
            cout << "\nEnter the total stock amount to set: " << endl;
            cin >> tst;
            set_tstock(tst);
            get_tstock();
            break;
        }
        case 2:
            get_tstock();
            break;
        case 3:
        {
            int en;
            cout << "\nEnter updated employee count: " << endl;
            cin >> en;
            set_enumb(en);
            break;
        }
        case 4:
            cout << "\nCurrent employees: " << endl;
            get_enumb();
            break;
        case 5:
        {
            obj.showBills();
            break;
        }
        case 6:
            obj.showFeedback();
            break;
        case 7:
            cout << "Exiting control panel..." << endl;
            return;
        default:
            cout << "Invalid option. Select between 1 and 7! \n"
                 << endl;
        }
    }
}

void admin::set_tstock(int tst)
{
    totalstock += tst;
}

void admin::get_tstock()
{
    cout << "Total stock of the restaurant: " << totalstock << "\n";
}

void admin::set_enumb(int en)
{
    employees = en;
}

void admin::get_enumb()
{
    cout << "Total employees of the restaurant: " << employees << "\n";
}
