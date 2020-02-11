#include <iostream>

using namespace std;

void const_test(int &var)
{
    var = 500;
    cout << var << endl;
}


int main()
{
    const int num = 200;
    const_test(const_cast<int &>(num));

    cout << num << endl;
    return 0;
}
