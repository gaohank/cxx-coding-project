#include <iostream>

using namespace std;

// ::作用域运算符 前面为命名空间
// 全局无命名空间

void func()
{
    cout << "hello world" << endl;
}

int main()
{
    ::func();
    return 0;
}
