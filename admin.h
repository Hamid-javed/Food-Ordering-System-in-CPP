#ifndef ADMIN_H
#define ADMIN_H

#include "restaurant.h"
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class admin : public restaurant
{
private:
    string id;
    string apass;

public:
    admin();
    void show() override;
    void showTotalBills();
    bool login(const string &ai, const string &pa);
    void control_panel();
    void set_tstock(int tst);
    void get_tstock();
    void set_enumb(int en);
    void get_enumb();
};

#endif
