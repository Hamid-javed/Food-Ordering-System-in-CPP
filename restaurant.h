#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <limits>

using namespace std;

class restaurant
{
protected:
    int totalstock;
    int employees;
    float stockcost;
    float totalcash;

public:
    int n, n1, b, q;
    int price[20];
    string dish[40];
    int i = 0;
    int t = 0;
    restaurant();

    virtual void show() = 0;
    void hamid();
    void abdulRehman();
    void zahid();
    void set_totalcash(float cash);
    void get_totalcash();
};

#endif