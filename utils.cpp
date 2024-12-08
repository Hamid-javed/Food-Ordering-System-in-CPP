#include "utils.h"
#include <conio.h>
#include <limits>
#include <string>
#include <iostream>

using namespace std;

long int receipt()
{
    srand(time(NULL));
    return rand() % 1000 + 1;
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
}

void exit()
{
    exit(0);
}

void getPassword(string &password)
{
    char ch;
    password.clear();

    while ((ch = _getch()) != '\r')
    {
        if (ch == '\b')
        {
            if (!password.empty())
            {
                cout << "\b \b";
                password.pop_back();
            }
        }
        else
        {
            password.push_back(ch);
            cout << '*';
        }
    }
    cout << endl;
}

int getValidInput(int min, int max)
{
    int input;
    while (true)
    {
        cin >> input;
        if (cin.fail() || input < min || input > max)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again: ";
        }
        else
        {
            return input;
        }
    }
}
