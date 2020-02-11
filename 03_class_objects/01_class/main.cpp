#include <iostream>
#include "structor_test.h"

using namespace std;

// 数据和行为在一起

class date {
private:    // 默认是私有变量
    int year;
protected:
    int month;
public:
    int day;

public:
    void init()
    {
        cin >> year;
        cin >> month;
        cin >> day;
    }
    void print()
    {
        cout << year << endl;
        cout << month << endl;
        cout << day << endl;
    }
};

int main()
{
    date d{};
    d.init();
    d.print();

    structor_test st;

    return 0;
}
