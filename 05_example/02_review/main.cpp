#include <iostream>

using namespace std;

// const
// 1.const 成员变量、成员函数、类对象，只能在构造器参数列表中初始化。
// 2.const 成员函数可以访问const和非const的变量，只能调用const成员函数
// 3.const 类对象可以访问const和非const的变量，只能调用const成员函数

// static
// 1.簇内数据共享
// 2.不占用对象空间，在类外初始化
// 3.只能调用static数据和成员函数

// */->*
// 类内的变量的偏移和函数的地址，需要和对象配合使用

// 友元
// 1.全局友元、类成员函数友元、类友元
// 2.声明为A的友元，可通过A的对象（作为参数），访问A的私有成员。

class A {
public:
    int a;
    void display()
    {
        cout << "display" << endl;
    }
    void func()
    {
        cout << "func test" << endl;
    }
};

int main()
{
    int A:: *pa = &A::a;
    void (A::* pf)() = &A::display;
    void (A::* pf2)() = &A::func;
    A a;
    a.a = 100;
    cout << a.*pa << endl;
    cout << pa << endl;
    (a.*pf)();
    (a.*pf2)();

    cout << pf << endl;
    cout << pf2 << endl;

    return 0;
}
