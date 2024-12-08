#include "customer.h"
#include "utils.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include "choice.h"

using namespace std;

void customer::menu()
{
    // cls();
    // cout << "Enter area you wish to have food delivered to:\n";
    // cin >> add;
    cout << "Redirecting...\n";
    delay(400);
    cls();
    cout << "Please wait while we locate restaurants in your area!" << endl;
    delay(500);
    cls();
    cout << "\nLoading...\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "\xdb";
        delay(400);
    }
    cls();
    cout << "Restaurants found in " << add << "! Choose your desired restaurant to view the menu:\n";
    cout << "[1] Kapita Kitchen\n[2] Younas Bakers\n[3] Zahid Kebab House\n";

    while (true)
    {
        cin >> n;

        // Check if input is invalid (not 1, 2, 3, or 4)
        if (n < 1 || n > 3)
        {
            cin.clear();
            cout << "Invalid input. Please choose a restaurant between 1 and 4: \n";
        }
        else
        {
            break; // Exit the loop if a valid select is entered
        }
    }

    if (n == 1)
    {
        cls();
        cout << "Redirecting you to Kapital Kitchen... Please wait.\n";
        delay(1000);
        cls();
        restaurant::hamid();
    }
    else if (n == 2)
    {
        cls();
        cout << "Redirecting you to Younas Bakers... Please wait.\n";
        delay(1000);
        cls();
        restaurant::abdulRehman();
    }
    else if (n == 3)
    {
        cls();
        cout << "Redirecting you to Zahid Kebab House... Please wait.\n";
        delay(1000);
        cls();
        restaurant::zahid();
    }
}

void customer::show() { cout << "same"; }
void customer::SignIn()
{
    cls();
    cout << "Enter username or email address:\n";
    cin >> email_id;
    cout << "Enter password:\n";
    getPassword(pass);

    ifstream regdata("registration_data.txt");
    bool found = false;

    if (regdata.is_open())
    {
        while (getline(regdata, emaiid) && getline(regdata, pw))
        {
            if (email_id == emaiid && pass == pw)
            {
                found = true;
                break;
            }
        }
        regdata.close();
    }

    if (found)
    {
        cout << "Login successful! Redirecting to menu...\n";
        delay(1000);
        cls();
        menu();
    }
    else
    {
        cout << "\nAccess Denied! Try again?\n[1] Yes\n[2] No\n[3] Go Back" << endl;
        cin >> select;
        if (select == 1)
        {
            cls();
            SignIn();
        }
        if (select == 2)
        {
            cls();
            start();
        }
        if (select == 3)
        {
            start(false);
        }
    }
}

void customer::SignUp()
{
    cls();
    int ph;
    cout << "Enter your email address:\n";
    cin >> emailid;
    cout << "Enter phone number:\n";
    cin >> ph;
    cout << "Enter a strong password:\n";
    getPassword(password);
    cout << "Re-enter password:\n";
    getPassword(pass2);

    if (password == pass2)
    {
        ofstream regdata("registration_data.txt", ios::app);
        regdata << emailid << "\n"
                << password << "\n";
        regdata.close();
        cout << "Sign Up successful! Notifications with weekly deals will be sent.\n";
        cout << "Place an order? Press 1.\n";
        int A;
        cin >> A;
        if (A == 1)
        {
            SignIn();
        }
    }
    else
    {
        cout << "Passwords do not match! Please try again.\n";
        SignUp();
    }
}

void customer::start(bool time)
{
    char n[20];
    cls();
    if (time == true)
    {
        cout << "\nWelcome to GetEatEnjoy!\n";
        cout << "Please enter your name for referencing purposes: \n";
        cin >> n;
    }

    cls();
    cout << "Thank You " << n << " for choosing GetEatEnjoy!\n";
    cout << "Choose the appropriate option: \n [1]: Sign Up\n [2]: Sign In\n [3]: Go Back" << endl;

    while (true)
    {
        cin >> select;

        if (select < 1 && select > 3)
        {
            cin.clear();
            cout << "Invalid input. Please enter 1 for Sign Up or 2 for Sign In: \n";
        }
        else
        {
            break;
        }
    }

    if (select == 1)
    {
        customer::SignUp();
    }
    else if (select == 2)
    {
        customer::SignIn();
    }
    else if (select == 3)
    {
        choice obj(false);
    }
}
