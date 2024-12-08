#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

using namespace std;

inline void cls()
{
    system("cls");
}

long int receipt();
void delay(unsigned int mseconds);
void exit();
void getPassword(string &password);
int getValidInput(int min, int max);
#endif
