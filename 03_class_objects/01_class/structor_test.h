#ifndef STRUCTOR_TEST_H
#define STRUCTOR_TEST_H

#include <iostream>
using namespace std;

class structor_test
{
public:
    // 显示构造函数，避免隐式转换
    explicit structor_test(int var = 100)
    {
        cout << var << endl;
    }
};

#endif // STRUCTOR_TEST_H
