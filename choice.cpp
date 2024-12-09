#include "choice.h"
#include "utils.h"
#include "admin.h"
#include "customer.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
using namespace std;

choice::choice(bool pause) : shouldPause(pause)
{
    cls();
    admin ad;
    int acc;

    if (shouldPause)
    {
        time_t t = time(NULL);
        tm *timePtr = localtime(&t);
        cout <<
            R"(

 __      __       .__                                      __          
/  \    /  \ ____ |  |   ____  ____   _____   ____       _/  |_  ____  
\   \/\/   // __ \|  | _/ ___\/  _ \ /     \_/ __ \      \   __\/  _ \ 
 \        /\  ___/|  |_\  \__(  <_> )  Y Y  \  ___/       |  | (  <_> )
  \__/\  /  \___  >____/\___  >____/|__|_|  /\___  >      |__|  \____/ 
       \/       \/          \/            \/     \/                    

)" << endl;
        cout << R"(

                      ________        __ ___________       __ ___________           __              
                     /  _____/  _____/  |\_   _____/____ _/  |\_   _____/ ____     |__| ____ ___.__.
                    /   \  ____/ __ \   __\    __)_\__  \\   __\    __)_ /    \    |  |/  _ <   |  |
                    \    \_\  \  ___/|  | |        \/ __ \|  | |        \   |  \   |  (  <_> )___  |
                     \______  /\___  >__|/_______  (____  /__|/_______  /___|  /\__|  |\____// ____|
                            \/     \/            \/     \/            \/     \/\______|      \/     

)" << endl;
        cout << "\n\n"
             << endl;
        system("pause");
        cls();
        cout << R"(
         _____                                                                                 _____ 
       ( ___ )-------------------------------------------------------------------------------( ___ )
        |   |                                                                                 |   | 
        |   |    _____ ___   ___  ____       ____  _____ _     _____     _______ ______   __  |   | 
        |   |   |  ___/ _ \ / _ \|  _ \     |  _ \| ____| |   |_ _\ \   / / ____|  _ \ \ / /  |   | 
        |   |   | |_ | | | | | | | | | |    | | | |  _| | |    | | \ \ / /|  _| | |_) \ V /   |   | 
        |   |   |  _|| |_| | |_| | |_| |    | |_| | |___| |___ | |  \ V / | |___|  _ < | |    |   | 
        |   |   |_|   \___/ \___/|____/     |____/|_____|_____|___|  \_/  |_____|_| \_\|_|    |   | 
        |   |                                                                                 |   | 
        |   |    ______   ______ _____ _____ __  __                                           |   | 
        |   |   / ___\ \ / / ___|_   _| ____|  \/  |                                          |   | 
        |   |   \___ \\ V /\___ \ | | |  _| | |\/| |                                          |   | 
        |   |    ___) || |  ___) || | | |___| |  | |                                          |   | 
        |   |   |____/ |_| |____/ |_| |_____|_|  |_|                                          |   | 
        |   |                                                                                 |   | 
        |___|                                                                                 |___| 
       (_____)-------------------------------------------------------------------------------(_____))"
             << endl;
        cout << "\n\n\t\t\t\tCURRENT TIME:\n";
        cout << "\t\t\t\t\t\t" << timePtr->tm_hour << ":" << timePtr->tm_min << ":" << timePtr->tm_sec << endl;
        cout << "\t\t\t\tToday's Date: " << endl;
        cout << "\t\t\t\t\t\t" << timePtr->tm_mday << "/" << timePtr->tm_mon + 1 << "/" << timePtr->tm_year + 1900 << endl
             << endl;
        cout << "\n\t\t\t\tPRESENTED BY:\n\t\t\t\t\t\tHamid Javed (SWEN231101005)\n\t\t\t\t\t\tAbdul Rehman (SWEN231101021)\n\t\t\t\t\t\tZahid Ali (SWEN231101050)\n\n\n";
        delay(400);
        system("pause");
        cout << "\n\tLoading...\n";
        cout << "\t\t";
        for (int i = 0; i < 16; i++)
        {
            cout << "\xdb";
            delay(300);
        }
    }
    cls();

    while (true)
    {
        cout << R"(
   ____      _    __   __                 _____               _   _ 
  / ___| ___| |_  \ \ / /__  _   _ _ __  |  ___|__   ___   __| | | |
 | |  _ / _ \ __|  \ V / _ \| | | | '__| | |_ / _ \ / _ \ / _` | | |
 | |_| |  __/ |_    | | (_) | |_| | |    |  _| (_) | (_) | (_| | |_|
  \____|\___|\__|   |_|\___/ \__,_|_|    |_|  \___/ \___/ \__,_| (_)
                                                                    )"
             << endl
             << endl;
        cout << "\t\t\t\tEnter your choice" << endl;
        cout << "\t\t\t\t1: Customer Access" << endl;
        cout << "\t\t\t\t2: Admin access" << endl;
        cout << "\t\t\t\t3: Return back" << endl
             << endl;

        cin >> acc;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid option (1, 2, or 3).\n";
            continue;
        }

        switch (acc)
        {
        case 1:
        {
            customer obj;
            obj.start();
        }
        break;

        case 2:
        {
            string id, pass;
            cout << "\n\t\t\t\tEnter ID:\n\t\t\t\t";
            cin >> id;
            std::cin.ignore();
            cout << "\n\t\t\t\tPASSWORD:\n\t\t\t\t";
            getPassword(pass);

            if (ad.login(id, pass) == 1)
            {
                cls();
                cout << "Login successful!" << endl;
                ad.control_panel();
            }
            else
            {
                cout << "ERROR - Authorization Required\n\n";
                cout << "Try again? Enter 1 for YES, 0 for NO: ";
                int lo;
                cin >> lo;
                if (lo == 0)
                {
                    cout << "Thanks for visiting GetSetEat page.\n";
                    return;
                }
            }
        }
        break;

        case 3:
            cout << R"(
  _____ _                 _           __                    _     _ _   _             
 |_   _| |__   __ _ _ __ | | _____   / _| ___  _ __  __   _(_)___(_) |_(_)_ __   __ _ 
   | | | '_ \ / _` | '_ \| |/ / __| | |_ / _ \| '__| \ \ / / / __| | __| | '_ \ / _` |
   | | | | | | (_| | | | |   <\__ \ |  _| (_) | |     \ V /| \__ \ | |_| | | | | (_| |
   |_| |_| |_|\__,_|_| |_|_|\_\___/ |_|  \___/|_|      \_/ |_|___/_|\__|_|_| |_|\__, |
   ____      _   ____       _   _____        _                                  |___/ 
  / ___| ___| |_/ ___|  ___| |_| ____|_ __  (_) ___  _   _   _ __   __ _  __ _  ___   
 | |  _ / _ \ __\___ \ / _ \ __|  _| | '_ \ | |/ _ \| | | | | '_ \ / _` |/ _` |/ _ \  
 | |_| |  __/ |_ ___) |  __/ |_| |___| | | || | (_) | |_| | | |_) | (_| | (_| |  __/_ 
  \____|\___|\__|____/ \___|\__|_____|_| |_|/ |\___/ \__, | | .__/ \__,_|\__, |\___(_)
                                          |__/       |___/  |_|          |___/                                       
)";
            return;

        default:
            cout << "Invalid option. Please select a valid option (1, 2, or 3).\n";
            break;
        }
    }
}
