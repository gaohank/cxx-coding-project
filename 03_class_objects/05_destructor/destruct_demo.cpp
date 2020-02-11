#include "destruct_demo.h"
#include <iostream>

using namespace std;

destruct_demo::destruct_demo(int len) : x(len),y(len),z(len)
{
    name = new char[len];
    cout << x << y << z << endl;
}

destruct_demo::~destruct_demo()
{
    cout << "call ~destruct_demo" << endl;
    delete[] name;
}
