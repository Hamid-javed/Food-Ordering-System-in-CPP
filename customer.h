#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "restaurant.h"
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iostream>

using namespace std;

class customer : protected restaurant
{
protected:
    ofstream regdata;
    fstream cou;
    string email_id, emailid, emaiid;
    string pass, pw, password;
    string pass2;
    int select;
    string add;
    int n;
    string n1;

public:
    static const char *name;
    void menu();
    void show();
    void SignIn();
    void SignUp();
    void start(bool time = true);
};

#endif
