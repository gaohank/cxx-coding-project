#include <iostream>

using namespace std;

// C 语言将数据放到struct，将数据以指针或者引用传给行为
// 没有权限

struct data {
    int year;
    int month;
    int day;
};

int main()
{
    data d{1,2,3};
    cout << d.year << d.month << d.day << endl;
    return 0;
}
