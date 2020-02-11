#include <iostream>
#include "destruct_demo.h"

using namespace std;

int main()
{
    destruct_demo *p = new destruct_demo;
    destruct_demo demo;
    delete p;
    cout << "call delete p" << endl;
    return 0;
}
