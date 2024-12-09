#ifndef BILL_H
#define BILL_H

#include "restaurant.h"
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

class bill : public restaurant
{
    int receiptId;
    int j;
    int total;
    string area;
    string userName;
    ofstream billRep;
    ofstream regdata;
    string userRep = "bill_file.txt";
    string userFeedback = "feedback.txt";

public:
    bill();
    void showBills();
    void show() override;
    int operator+(int z);
    void displaybill(int t, int i, int price[], string dish[]);
    void rider(int t);
    void feedback();
    void showFeedback();
};

#endif
