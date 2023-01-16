#include <iostream>
using namespace std;

#include "IniFile.h"

int main()
{
    // Value v1(true);
    // Value v2(1111);
    // Value v3(1.11);
    // Value v4("c++");

    // Value v1;
    // v1 = true;

    // Value v2;
    // v2 = 1111;

    // Value v3;
    // v3 = 1.11;

    // Value v4;
    // v4 = "c++";

    // Value v1(true);
    // bool a = v1;

    // Value v2(1111);
    // int b = v2;

    // Value v3(1.11);
    // double c = v3;

    // Value v4("c++");
    // const string &d = v4;

    IniFile ini;
    ini.load("test.ini");

    return 0;
}