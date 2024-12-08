#include <iostream>
#include "restaurant.h"
#include "bill.h"
#include "customer.h"
#include <stdlib.h>
#include "utils.h"
#include <fstream>
using namespace std;

fstream regdata;

void edit(int i, string dish[], int price[])
{
    int pos;

    cout << "elect the item you want to delete:\t";
    cin >> pos;

    if (pos > i)
    {
        cout << "\n\nThis value is out of range: select again:\t";
        cin >> pos;
    }
    else
    {
        --pos;
        for (int k = pos; k < i; k++)
        {
            dish[k] = dish[k + 1];
            price[k] = price[k + 1];
        }
        cout << "\n\nNew items in your cart: ";
        for (int k = 0; k < i - 1; k++)
        {
            cout << "\n"
                 << dish[k] << "\t" << "Rs:" << price[k] << "\n\n";
        }
    }
}

void test(int t, int i, int a[], string dish[])
{
    bill b;
    b.displaybill(t, i, a, dish);
    system("pause");
    cls();
    b.rider(t);
    b.feedback();
}

restaurant::restaurant()
{
    totalstock = 50;
    employees = 50;
    stockcost = 15.76;
    totalcash = 1000.50;
}

void restaurant::set_totalcash(float cash)
{
    totalcash = cash;
}

void restaurant::get_totalcash()
{
    cout << "Total cash: " << totalcash << endl;
}

void restaurant::hamid()
{
    cls();
    cout << "Welcome to Kapital Kitchen.\nKindly select your desired option.\n[1]: EXCLUSIVE DESSERTS\n[2]: CAKES\n[3]: CUPCAKES\n[4]: Go Back\n";
    cin >> n;
    while (true)
    {

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 4.\n";
            continue;
        }

        if (n < 1 || n > 4)
        {
            cout << "Invalid option. Please try again.\n";
            break;
        }

        string desserts[] = {"Creme Brulee", "Nutella Sundae", "Red Velvet Sundae", "Summer Berry Grunt"};
        int dessertPrices[] = {300, 350, 450, 80};
        string cakes[] = {"Cadbury Dairy Milk", "Mousse Cake", "Maltesers", "Belgian Chocolate Cake", "Chocolate Heaven", "Kit Kat Cake"};
        int cakePrices[] = {1000, 1100, 1200, 1600, 2500, 1100};
        string cupcakes[] = {"Classic Chocolate", "Cream Cheese", "Original Malt", "Salted Caramel", "Belgian Malt"};
        int cupcakePrices[] = {120, 110, 120, 100, 150};

        if (n == 1)
        {
            cls();
            cout << "----------------------------------------------------------------------------------------------\n";
            cout << "                          EXCLUSIVE DESSERTS\n";
            cout << "----------------------------------------------------------------------------------------------\n";
            for (int i = 0; i < 4; ++i)
            {
                cout << "[" << i + 1 << "]: " << desserts[i] << "\nRS: " << dessertPrices[i] << "\n\n";
            }
            cout << "[5]: Go Back!" << endl;

            while (true)
            {
                cout << "TO SELECT YOUR DESIRED DEAL ENTER: ";
                cin >> n1;
                if (n1 >= 1 && n1 <= 4)
                {
                    break;
                }
                else if (n1 == 5)
                {
                    hamid();
                }
                else
                {
                    cout << "Invalid option. Please select a valid dessert.\n";
                }
            }

            price[i] = dessertPrices[n1 - 1];
            dish[i] = desserts[n1 - 1];
            t += price[i];
            i++;
        }
        else if (n == 2)
        {
            cls();
            cout << "----------------------------------------------------------------------------------------------\n";
            cout << "                            CAKES\n";
            cout << "----------------------------------------------------------------------------------------------\n";
            for (int i = 0; i < 6; ++i)
            {
                cout << "[" << i + 1 << "]: " << cakes[i] << "\nRS: " << cakePrices[i] << "\n\n";
            }
            cout << "[7]: Go Back!" << endl;

            while (true)
            {
                cout << "TO SELECT YOUR DESIRED DEAL ENTER: ";
                cin >> n1;
                if (n1 >= 1 && n1 <= 6)
                {
                    break;
                }
                else if (n1 == 7)
                {
                    hamid();
                }
                else
                {
                    cout << "Invalid option. Please select a valid cake.\n";
                }
            }

            price[i] = cakePrices[n1 - 1];
            dish[i] = cakes[n1 - 1];
            t += price[i];
            i++;
        }
        else if (n == 3)
        {
            cls();
            cout << "----------------------------------------------------------------------------------------------\n";
            cout << "                           CUPCAKES\n";
            cout << "----------------------------------------------------------------------------------------------\n";
            for (int i = 0; i < 5; ++i)
            {
                cout << "[" << i + 1 << "]: " << cupcakes[i] << "\nRS: " << cupcakePrices[i] << "\n\n";
            }
            cout << "[6]: Go Back!" << endl;

            while (true)
            {
                cout << "TO SELECT YOUR DESIRED DEAL ENTER: ";
                cin >> n1;
                if (n1 >= 1 && n1 <= 5)
                {
                    break;
                }
                else if (n1 == 6)
                {
                    hamid();
                }
                else
                {
                    cout << "Invalid option. Please select a valid cupcake.\n";
                }
            }

            price[i] = cupcakePrices[n1 - 1];
            dish[i] = cupcakes[n1 - 1];
            t += price[i];
            i++;
        }
        else if (n == 4)
        {
            customer obj;
            obj.menu();
        }

        while (true)
        {
            cls();
            cout << "Please Select the desired option:\n[1] Add More Item\n[2] Move To Bill\n[3] Display Your Items\n";

            // Validate user input
            if (!(cin >> q)) // Check if the input is valid (numeric)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "Invalid input. Please enter a number between 1 and 3: " << endl;
                continue;
            }

            if (q == 1)
            {
                hamid(); // Call the hamid function
                break;
            }
            else if (q == 2)
            {
                test(t, i, price, dish); // Process the bill
                break;
            }
            else if (q == 3)
            {
                char l;
                for (int j = 0; j < i; j++)
                {
                    cout << "\n\n[" << j + 1 << "] :" << dish[j] << "\nRs: " << price[j] << "\n\n";
                }
                cout << "Do you want to delete an item? (Y/N): ";
                cin >> l;
                while (l == 'y' || l == 'Y')
                {
                    edit(i, dish, price); // TO Edit items
                    i--;
                    cout << "Do you want to delete another item? (Y/N): ";
                    cin >> l;
                }

                cout << "Please Select the desired option again:\n[1] Add More Item\n[2] Move To Bill\n";
                if (!(cin >> q))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number between 1 and 2.\n";
                    continue;
                }

                if (q == 1)
                {
                    hamid();
                    break;
                }
                else if (q == 2)
                {
                    test(t, i, price, dish);
                    break;
                }
                else
                {
                    cout << "Invalid option. Please try again.\n";
                }
            }
            else
            {
                cout << "Invalid option. Please enter a number between 1 and 3.\n";
            }
        }
    }
}

void restaurant::abdulRehman()
{
    cls();
    cout << "Welcome to Younas Bakers.\nKindly select your desired option.\n[1]: EXCLUSIVE DISCOUNT DEALS\n[2]: VEG DEALS \n[3]: BAR \n[4]: FAST FOOD\n[5]: GO Back!" << endl;

    while (true)
    {
        if (!(cin >> n))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 5: " << endl;
            continue;
        }

        if (n == 1)
        {
            cls();
            cout << "----------------------------------------------------------------------------------------------\n\tEXCLUSIVE DEALS\n----------------------------------------------------------------------------------------------";
            cout << "\n[1]: DEAL 1: Zinger with 250 ml softdrink\nRs:300\n\n[2]: DEAL 2: Zinger, chicken piece, fries and softdrink\nRs: 350\n\n[3]: DEAL 3: 2 Zinger, fries and 500ml softdrink\nRs 450\n\n[4]: Go Back!" << endl;
            cout << "TO SELECT YOUR DESIRED DEAL ENTER: ";

            // Input validation for deal selection (n1)
            while (true)
            {
                cin >> n1;

                if (n1 < 1 || n1 > 5)
                {
                    cin.clear(); // Clear the error flag
                    cout << "Invalid input. Please select a valid deal (1, 2, or 3): ";
                }
                else if (n1 == 4)
                {
                    abdulRehman();
                }
                else
                {
                    break; // Exit loop if valid input is entered
                }
            }

            int a[] = {300, 350, 1200, 450};
            if (n1 == 1)
            {
                price[i] = a[0];
                t += a[0];
                dish[i] = "Deal1";
                i += 1;
            }
            else if (n1 == 2)
            {
                price[i] = a[1];
                t += a[1];
                dish[i] = "Deal2";
                i += 1;
            }
            else if (n1 == 3)
            {
                price[i] = a[2];
                t += a[2];
                dish[i] = "Deal3";
                i += 1;
            }
        }
        else if (n == 2)
        {
            cls();
            cout << "----------------------------------------------------------------------------------------------\n\tBREAKFAST DEALS\n----------------------------------------------------------------------------------------------";
            cout << "\n[1]: Egg Sandwich with Spread Cheese with coffee\t\nRs: 60\n\n[2]: Chicken Mayo Garlic Wrap With Coffee\nRs: 110\n\n[3]: Falafel Wrap With Coffee\nRS: 100\n\n[4]: Chicken Strip Wrap With Coffee\nRS: 400\n\n[5]: Chicken Kabab Wrap With Coffee\nRS 250\n\n[6]: Go Back" << endl;
            cout << "TO SELECT YOUR DESIRED DEAL ENTER THE KEY: " << endl;

            // Input validation for deal selection (n1)
            while (true)
            {
                cin >> n1;

                if (n1 < 1 || n1 > 6)
                {
                    cin.clear(); // Clear the error flag
                    cout << "Invalid input. Please select a valid deal (1 to 5): ";
                }
                else if (n1 == 6)
                {
                    abdulRehman();
                }
                else
                {
                    break; // Exit loop if valid input is entered
                }
            }

            int a[] = {60, 110, 100, 500, 250};
            if (n1 == 1)
            {
                price[i] = a[0];
                t += a[0];
                dish[i] = "EggSandwich";
                i += 1;
            }
            else if (n1 == 2)
            {
                price[i] = a[1];
                t += a[1];
                dish[i] = "CickenMayoGarlicWrap";
                i += 1;
            }
            else if (n1 == 3)
            {
                price[i] = a[2];
                t += a[2];
                dish[i] = "FalafelWrap";
                i += 1;
            }
            else if (n1 == 4)
            {
                price[i] = a[3];
                t += a[3];
                dish[i] = "Chickenstripwrap";
                i += 1;
            }
            else if (n1 == 5)
            {
                price[i] = a[4];
                t += a[4];
                dish[i] = "ChickenKababWrap";
                i += 1;
            }
        }
        else if (n == 3)
        {
            cls();
            cout << "----------------------------------------------------------------------------------------------\n\tBARBEQUE DEALS\n----------------------------------------------------------------------------------------------";
            cout << "\n[1]: Malai Tikka\t\nRs: 160\n\n[2]: Beef Seekh Kabab\nRs: 110\n\n[3]: Chicken Seekh Kabba\nRS: 100\n\n[4]: Grilled Chicken With 300 ml pepsi\nRS: 400\n\n[5]: Chicken Tikka With 300 ml pepsi\nRS 250\n\n[6]: Go Back!";
            cout << "\n\nTO SELECT YOUR DESIRED DEAL ENTER THE KEY: " << endl;

            // Input validation for deal selection (n1)
            while (true)
            {
                cin >> n1;

                if (n1 < 1 || n1 > 6)
                {
                    cin.clear(); // Clear the error flag
                    cout << "Invalid input. Please select a valid deal (1 to 5): ";
                }
                else if (n1 == 6)
                {
                    abdulRehman();
                }
                else
                {
                    break; // Exit loop if valid input is entered
                }
            }

            int a[] = {160, 110, 100, 400, 250};
            if (n1 == 1)
            {
                price[i] = a[0];
                t += a[0];
                dish[i] = "MalaiTikka";
                i += 1;
            }
            else if (n1 == 2)
            {
                price[i] = a[1];
                t += a[1];
                dish[i] = "BeefSeekhKebab";
                i += 1;
            }
            else if (n1 == 3)
            {
                price[i] = a[2];
                t += a[2];
                dish[i] = "ChickenSeekhKebab";
                i += 1;
            }
            else if (n1 == 4)
            {
                price[i] = a[3];
                t += a[3];
                dish[i] = "GrilledChicken";
                i += 1;
            }
            else if (n1 == 5)
            {
                price[i] = a[4];
                t += a[4];
                dish[i] = "ChickenTikka";
                i += 1;
            }
        }
        else if (n == 4)
        {
            cls();
            cout << "----------------------------------------------------------------------------------------------\n\tFASTFOOD DEALS\n----------------------------------------------------------------------------------------------";
            cout << "\n[1]: 4 Zing burgers, 4 regular fries & 1.5 litre soft drink\nRs: 600\n\n[2]: 4 GMC burgers, 4 regular fries & 1.5 litre soft drink\nRs: 510\n\n[3]: 3 Breast Pieces with regular fries & hot garlic mayo sauce\nRS: 100\n\n[4]: Beef Zinger Burger With 300 ml pepsi\nRS: 400\n\n[5]: Grilled Chicken Burger With 300 ml pepsi\nRS 250\n\n[6]: Go Back";
            cout << "\n\nTO SELECT YOUR DESIRED DEAL ENTER THE KEY: ";

            // Input validation for deal selection (n1)
            while (true)
            {
                cin >> n1;

                if (n1 < 1 || n1 > 6)
                {
                    cin.clear(); // Clear the error flag
                    cout << "Invalid input. Please select a valid deal (1 to 5): ";
                }
                else if (n1 == 6)
                {
                    abdulRehman();
                }
                else
                {
                    break; // Exit loop if valid input is entered
                }
            }

            int a[] = {600, 510, 100, 400, 250};
            if (n1 == 1)
            {
                price[i] = a[0];
                t += a[0];
                dish[i] = "4ZingburgersDeal";
                i += 1;
            }
            else if (n1 == 2)
            {
                price[i] = a[1];
                t += a[1];
                dish[i] = "4GMCBurgerDeal";
                i += 1;
            }
            else if (n1 == 3)
            {
                price[i] = a[2];
                t += a[2];
                dish[i] = "3BreastPiecesDeal";
                i += 1;
            }
            else if (n1 == 4)
            {
                price[i] = a[3];
                t += a[3];
                dish[i] = "BeefZinger";
                i += 1;
            }
            else if (n1 == 5)
            {
                price[i] = a[4];
                t += a[4];
                dish[i] = "GrilledChickenBurger";
                i += 1;
            }
        }
        else if (n == 5)
        {
            customer obj;
            obj.menu();
        }

        while (true)
        {
            cls();
            cout << "Please Select the desired option:\n[1] Add More Item\n[2] Move To Bill\n[3] Display Your Items\n";

            if (!(cin >> q))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number between 1 and 3.\n";
                continue;
            }

            if (q == 1)
            {
                abdulRehman();
                break;
            }
            else if (q == 2)
            {
                test(t, i, price, dish);
                break;
            }
            else if (q == 3)
            {
                char l;
                for (int j = 0; j < i; j++)
                {
                    cout << "\n\n[" << j + 1 << "] :" << dish[j] << "\nRs: " << price[j] << "\n\n";
                }
                cout << "Do you want to delete an item? (Y/N): ";
                cin >> l;
                while (l == 'y' || l == 'Y')
                {
                    edit(i, dish, price); // Edit items
                    i--;
                    cout << "Do you want to delete another item? (Y/N): ";
                    cin >> l;
                }

                // Prompt user again after displaying or editing items
                cout << "Please Select the desired option again:\n[1] Add More Item\n[2] Move To Bill\n";
                if (!(cin >> q))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number between 1 and 2.\n";
                    continue;
                }

                if (q == 1)
                {
                    hamid();
                    break;
                }
                else if (q == 2)
                {
                    test(t, i, price, dish);
                    break;
                }
                else
                {
                    cout << "Invalid option. Please try again.\n";
                }
            }
            else
            {
                cout << "Invalid option. Please enter a number between 1 and 3.\n";
            }
        }
    }
}

void restaurant::zahid()
{
    cls();
    cout << "welcome to Zahid's Kabab House.\nKindly select your desired option.\n[1]: KARHAI SPECIALITIES\n[2]: BBQ DISHES \n[3]: KATAKAT SPECIALITES \n[4]: BEVERAGES\n[5]: Go Back" << endl;
    while (true)
    {
        if (!(cin >> n))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 5: " << endl;
            continue;
        }
        if (n == 1)
        {
            cls();
            cout << "----------------------------------------------------------------------------------------------\n                           \tKARHAI  SPECIALS\n----------------------------------------------------------------------------------------------";
            cout << "\n[1]: Peshawari Karhai\nRs: 600\n\n[2]: Red Karhai\nRs: 510\n\n[3]: 3White Karhain\nRS: 100\n\n[4]: Beef Karahi\nRS: 500\n\n[5]: Chicken Karhai\nRS 250\n\n[6]: Go Back";
            cout << "\n\nTO SELECT YOUR DESIRED DEAL ENTER THE KEY ";

            while (true)
            {
                cin >> n1;
                if (n1 < 1 || n1 > 6)
                {
                    cin.clear(); // Clear the error flag
                    cout << "Invalid input. Please select a valid option between 1 and 6: ";
                }
                else if (n1 == 6)
                {
                    zahid();
                }
                else
                {
                    break; // Exit loop if valid input is entered
                }
            }

            int a[] = {600, 510, 1000, 500, 250};
            if (n1 == 1)
            {
                price[i] = a[0];
                t += a[0];
                dish[i] = "PeshawariKarhai";
                i += 1;
            }
            else if (n1 == 2)
            {
                price[i] = a[1];
                t += a[1];
                dish[i] = "RedKarhai";
                i += 1;
            }
            else if (n1 == 3)
            {
                price[i] = a[2];
                t += a[2];
                dish[i] = "WhiteKarhai";
                i += 1;
            }
            else if (n1 == 4)
            {
                price[i] = a[3];
                t += a[3];
                dish[i] = "BeefKarahai";
                i += 1;
            }
            else if (n1 == 5)
            {
                price[i] = a[4];
                t += a[4];
                dish[i] = "ChickenKarahai";
                i += 1;
            }
        }
        if (n == 2)
        {
            cls();
            cout << "----------------------------------------------------------------------------------------------\n                           \tKARHAI SPECIALITIES\n----------------------------------------------------------------------------------------------";
            cout << "\n[1]: KATAT MIX PLATE\nRS:2300\n\n[2]: BRAIN MASALA\nRS: 1350\n\n[3]: KIDNEY MASALA\nRS 450\n\n[4]: KAPOORA MASALA\nRS:1350 \n\n[5]: KAPOORA MASALA WITH BUTTER \nRS: 1900\n\n[6]: Go Back";
            cout << "\n\nTO SELECT YOUR DESIRED DEAL ENTER ";

            while (true)
            {
                cin >> n1;
                if (n1 < 1 || n1 > 6)
                {
                    cin.clear(); // Clear the error flag
                    cout << "Invalid input. Please select a valid option between 1 and 6: ";
                }
                else if (n1 == 6)
                {
                    zahid();
                }
                else
                {
                    break; // Exit loop if valid input is entered
                }
            }

            int a[] = {2300, 1350, 450, 1350, 1900};
            if (n1 == 1)
            {
                price[i] = a[0];
                t += a[0];

                dish[i] = "KatakatMixPlate";
                i += 1;
            }
            else if (n1 == 2)
            {
                price[i] = a[1];
                t += a[1];
                dish[i] = "BrainMasala";
                i += 1;
            }
            else if (n1 == 3)
            {
                price[i] = a[2];
                t += a[2];
                dish[i] = "KidneyMasala";
                i += 1;
            }
            else if (n1 == 4)
            {
                price[i] = a[3];
                t += a[3];
                dish[i] = "KapooraMasala";
                i += 1;
            }
            else if (n1 == 5)
            {
                price[i] = a[4];
                t += a[4];
                dish[i] = "KapooraMasalaWithButter";
                i += 1;
            }
        }
        if (n == 3)
        {
            cls();
            cout << "----------------------------------------------------------------------------------------------\n                           \tBBQ DISHES\n----------------------------------------------------------------------------------------------";
            cout << "\n[1]:Zahid SPECIAL KABAB BEEF\t\nRs: 260\n\n[2]: MALAI TIKKA\nRs: 120\n\n[3]: CHICKEN MALAI BOTI\nRS: 180\n\n[4]: MUTTON CHOPS\nRS: 400\n\n[5]: Chicken Kabab Wrap \nRS 250/\n\n[6]: Go Back";
            cout << "\n\nTO SELECT YOUR DESIRED DEAL ENTER THE KEY";

            while (true)
            {
                cin >> n1;
                if (n1 < 1 || n1 > 6)
                {
                    cin.clear(); // Clear the error flag
                    cout << "Invalid input. Please select a valid option between 1 and 6: ";
                }
                else if (n1 == 6)
                {
                    zahid();
                }
                else
                {
                    break; // Exit loop if valid input is entered
                }
            }

            int a[] = {260, 120, 180, 400, 250};
            if (n1 == 1)
            {
                price[i] = a[0];
                t += a[0];
                dish[i] = "Zahid Special";
                i += 1;
            }
            else if (n1 == 2)
            {
                price[i] = a[1];
                t += a[1];
                dish[i] = "MalaiTikka";
                i += 1;
            }
            else if (n1 == 3)
            {
                price[i] = a[2];
                t += a[2];
                dish[i] = "ChickenMalaiBoti";
                i += 1;
            }
            else if (n1 == 4)
            {
                price[i] = a[3];
                t += a[3];
                dish[i] = "MuttonChops";
                i += 1;
            }
            else if (n1 == 5)
            {
                price[i] = a[4];
                t += a[4];
                dish[i] = "KebabWrap";
                i += 1;
            }
        }
        if (n == 4)
        {
            cls();
            cout << "----------------------------------------------------------------------------------------------\n                           BEVERAGESS \n----------------------------------------------------------------------------------------------";
            cout << "\n[1]: Pepsi\t\nRs: 60\n\n[2]: Marinda\nRs: 60\n\n[3]: 7up\nRS: 60\n\n[4]: 7up diet\nRS: 60\n\n[5]: Mineral water\nRS 250\n\n[6]: Go Back";
            cout << "\n\nTO SELECT YOUR DESIRED DEAL ENTER THE KEY";

            while (true)
            {
                cin >> n1;
                if (n1 < 1 || n1 > 6)
                {
                    cin.clear(); // Clear the error flag
                    cout << "Invalid input. Please select a valid option between 1 and 6: ";
                }
                else if (n1 == 6)
                {
                    zahid();
                }
                else
                {
                    break; // Exit loop if valid input is entered
                }
            }

            int a[] = {60, 60, 60, 60, 250};
            if (n1 == 1)
            {
                price[i] = a[0];
                t += a[0];
                dish[i] = "Pepsi";
                i += 1;
            }
            else if (n1 == 2)
            {
                price[i] = a[1];
                t += a[1];
                dish[i] = "Miranda";
                i += 1;
            }
            else if (n1 == 3)
            {
                price[i] = a[2];
                t += a[2];
                dish[i] = "7up";
                i += 1;
            }
            else if (n1 == 4)
            {
                price[i] = a[3];
                t += a[3];
                dish[i] = "7upDiet";
                i += 1;
            }
            else if (n1 == 5)
            {
                price[i] = a[4];
                t += a[4];
                dish[i] = "MineralWater";
                i += 1;
            }
        }
        if (n == 5)
        {
            customer obj;
            obj.menu();
        }
        while (true)
        {
            cls();
            cout << "Please Select the desired option:\n[1] Add More Item\n[2] Move To Bill\n[3] Display Your Items\n";

            if (!(cin >> q))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number between 1 and 3.\n";
                continue;
            }

            if (q == 1)
            {
                zahid();
                break;
            }
            else if (q == 2)
            {
                test(t, i, price, dish);
                break;
            }
            else if (q == 3)
            {
                char l;
                for (int j = 0; j < i; j++)
                {
                    cout << "\n\n[" << j + 1 << "] :" << dish[j] << "\nRs: " << price[j] << "\n\n";
                }
                cout << "Do you want to delete an item? (Y/N): ";
                cin >> l;
                while (l == 'y' || l == 'Y')
                {
                    edit(i, dish, price);
                    i--;
                    cout << "Do you want to delete another item? (Y/N): ";
                    cin >> l;
                }

                cout << "Please Select the desired option again:\n[1] Add More Item\n[2] Move To Bill\n";
                if (!(cin >> q))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number between 1 and 2.\n";
                    continue;
                }

                if (q == 1)
                {
                    hamid();
                    break;
                }
                else if (q == 2)
                {
                    test(t, i, price, dish);
                    break;
                }
                else
                {
                    cout << "Invalid option. Please try again.\n";
                }
            }
            else
            {
                cout << "Invalid option. Please enter a number between 1 and 3.\n";
            }
        }
    }
}
