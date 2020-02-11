#include <iostream>

using namespace std;

// 强转
// static_cast 对应隐式类型转化
// dynamic_cast
// reinterpret_cast 隐式类型不能转化的
// const_cast 脱常 只能应用于指针和引用

void func(int &a)
{
    cout << a << endl;
}

int main()
{
    int a;
    float b = 3.14;

    a = static_cast<int>(b);
    b = static_cast<float>(a);

    cout << a << endl;
    cout << b << endl;

    int var1 = 10, var2 = 3;
    float var3 = static_cast<float>(var1)/var2;

    cout << var3 << endl;

    const int i = 100;
    func(const_cast<int &>(i));

    return 0;
}
