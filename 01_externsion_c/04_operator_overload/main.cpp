#include <iostream>

using namespace std;

// C++重载操作符

struct company {
    int num;
    int pay;
};

company operator+(company a, company b)
{
    company c;
    c.num = a.num + b.num;
    c.pay = a.pay + b.pay;
    return c;
}

int main()
{
    company test1 = {1,2}, test2 = {3,4};

    company test3 = test1 + test2;
    cout << test3.num << test3.pay << endl;

    return 0;
}
