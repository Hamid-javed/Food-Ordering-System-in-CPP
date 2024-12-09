#include "bill.h"
#include "utils.h"
#include <cstdlib>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

void bill::show()
{
    cout << "Bill management." << endl;
}

bill::bill() {}

void bill::displaybill(int t, int i, int price[], string dish[])
{
    cls();
    receiptId = receipt();
    cout << "\n\t\t\t------------------------------------------------";
    cout << "\n\t\t\t------------------GetEatEnjoy------------------";
    cout << "\n\t\t\t--------------Customer Receipt:" << receipt() << "----------------";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nEnter your name: ";
    getline(cin, userName);
    cout << endl;
    cout << "Enter the address where you want food to be delivered: ";
    getline(cin, area);
    cout << endl
         << endl;

    cout << "\n--------------------------------------------------";
    cout << endl
         << "NAME: \t\t\t\t" << userName << endl;
    cout << "ADDRESS:\t\t\t" << area << endl;
    for (int j = 0; j < i; j++)
    {
        cout << endl
             << "ITEM: " << j + 1 << ": " << dish[j] << "\t\t" << price[j];
        total = total + price[j];
    }
    cout << endl;
    cout << endl
         << "QUANTITY: \t\t\t\t" << i << endl;
    cout << endl
         << "TOTAL:\t\t\t\t" << t << endl;
    billRep.open(userRep, ios::out | ios::app);
    cout << "\n--------------------------------------------------";
    cout << endl;
    billRep << "Receipt ID:\t" << receiptId << "\n";
    billRep << "----------------------------------------------------------\n";

    billRep << "ITEMS PURCHASED:\n";
    for (int j = 0; j < i; j++)
    {
        billRep << "\t\t" << j + 1 << ". " << dish[j] << "\t Rs. " << price[j] << "\n";
    }
    cout << endl;
    billRep << "CUSTOMER DETAILS:\n";
    billRep << "\t\tName: \t" << userName << endl;
    billRep << "\t\tAddress: \t" << area << endl;
    billRep << "----------------------------------------------------------\n";

    billRep << "SUMMARY:\n";
    billRep << "\t\tItems: \t" << i << endl;
    billRep << "\t\tTotal purchase value: \t" << t << endl;
    billRep << "----------------------------------------------------------\n\n\n";
    billRep.close();
}

void bill::showBills()
{
    ifstream billFile("bill_file.txt");

    if (!billFile)
    {
        cout << "Error: Unable to open the file!" << endl;
        return;
    }

    string line;
    cout << "\n\t\t***************************************************************\n";
    cout << R"(
                   ____ ___ _     _       ____  _____ _____  _    ___ _     ____  
                  | __ )_ _| |   | |     |  _ \| ____|_   _|/ \  |_ _| |   / ___| 
                  |  _ \| || |   | |     | | | |  _|   | | / _ \  | || |   \___ \ 
                  | |_) | || |___| |___  | |_| | |___  | |/ ___ \ | || |___ ___) |
                  |____/___|_____|_____| |____/|_____| |_/_/   \_\___|_____|____/ 
                                                                 )"
         << endl;
    cout << "\t\t***************************************************************\n\n\n";

    while (getline(billFile, line))
    {
        cout << line << endl;
    }

    cout << "**********************************************************\n";
    billFile.close();
}

void bill::rider(int t)
{
    srand(time(NULL));
    string guy[] = {"Arkam", "Hassan", "Umer", "Haris", "Wahab", "Ali", "Tariq", "Bilal", "Hamza"};
    int index = rand() % 7;
    cout << "\n\t\t\t\tThank you for choosing GetEatEnjoy!\n";
    cout << "\n\t\t\t\tPlease take notes the details provided below: \n";
    cout << "\n\t\t\t\tReciept Number: " << receipt() << endl;
    cout << "\n\t\t\t\tRider Name: " << guy[index] << endl;
    cout << "\n\t\t\t\tRider Contact: +9250078601" << endl;
    cout << "\n\t\t\t\tTotal Amount: " << t << endl;
    cout << "\n\t\t\t\tPlace: " << area << endl;
    cout << "\n\t\t\t\tMode Of Payment: Cash On Delivery" << endl;
    cout << "\n\t\t\t\tDelivery Time: 60 minutes" << endl;
}

void bill::feedback()
{
    int d;
    string str;
    system("pause");
    cls();
    cout << "Do you wish to provide feedback: \n[1]: Yes\n[2]: No\n";
    cin >> d;
    if (d == 2)
    {
        cout << "GetEatEnjoy wishes you a happy food! Thank You!\n";
        exit();
    }
    else if (d == 1)
    {
        regdata.open(userFeedback, ios::out | ios::app);
        cout << "Team GetEatEnjoy will not take much of your time. Please answer the following questionnaire: \n";
        regdata << "Receipt ID: " << receiptId << "\n";
        regdata << "----------------------------------------------------------\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nWas GetEatEnjoy website user-friendly enough? If no, please explain.\n";
        getline(cin, str);
        regdata << "1. Was the website user-friendly? \nAnswer: " << str << "\n\n";

        cout << "Was the customer service helpful? If no, please explain.\n";
        getline(cin, str);
        regdata << "3. Was the customer service helpful? \nAnswer: " << str << "\n\n";

        cout << "Would you choose GetEatEnjoy again for ordering food? If no, please explain.\n";
        getline(cin, str);
        regdata << "5. Would you choose GetEatEnjoy again? \nAnswer: " << str << "\n\n";

        cout << "Please add further comments or suggestions: \n";
        getline(cin, str);
        regdata << "6. Additional Comments or Suggestions: \nAnswer: " << str << "\n\n";

        cout << "Thank you for providing us with feedback. It is now stored in the GetEatEnjoy database for future consideration.\n\n\n";
        cout << R"(  
                     _   _                           _____      _   _             _ 
                    | | | | __ _ _ __  _ __  _   _  | ____|__ _| |_(_)_ __   __ _| |
                    | |_| |/ _` | '_ \| '_ \| | | | |  _| / _` | __| | '_ \ / _` | |
                    |  _  | (_| | |_) | |_) | |_| | | |__| (_| | |_| | | | | (_| |_|
                    |_| |_|\__,_| .__/| .__/ \__, | |_____\__,_|\__|_|_| |_|\__, (_)
                              |_|   |_|      |___/                          |___/   )";

        regdata
            << "==========================================================\n\n\n";
        regdata.close();

        exit();
    }
}

void bill::showFeedback()
{
    ifstream regdata("feedback.txt");
    if (!regdata)
    {
        cerr << "Error opening file! Ensure feedback has been recorded first." << endl;
        return;
    }

    string line;
    cout << "\nFeedbacks from GetEatEnjoy Database:\n";
    cout << "=====================================\n";

    while (getline(regdata, line))
    {
        cout << line << endl;
    }

    regdata.close();
}

int bill::operator+(int z)
{
    return this->total + z;
}
