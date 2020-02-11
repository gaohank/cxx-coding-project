#include <iostream>
#include "mystring.h"

using namespace std;

int main()
{
    mystring a("gao"),b("songling"),c;
    c = a + b;
    a.display();
    b.display();
    c.display();
    c[1] = 'd';
    cout << c.c_ptr() << endl;

    if (c > a) cout << "c > a" << endl;
    return 0;
}
