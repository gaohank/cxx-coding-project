#include <iostream>

using namespace std;

// 友元
// 1.全局友元、类成员函数友元、类友元
// 2.声明为A的友元，可通过A的对象（作为参数），访问A的私有成员。

class A {
public:
    A (int var1 = 0, int var2 = 0) :
        x(var1),y(var2)
    {

    }

    void display()
    {
        cout << x << "--" << y << endl;
    }

    friend A operator+(A& own, A& another);
    friend class B;

private:
    int x, y;
};

A operator+(A& own, A& another)
{
    A tmp;
    tmp.x = own.x + another.x;
    tmp.y = own.y + another.y;
    return tmp;
}

class B {
public:
    void show(A& a)
    {
        cout << a.x << "**" << a.y << endl;
    }
};

int main()
{
    A a(1,2), b(5,10), c;
    c = a + b;
    c.display();

    B test;
    test.show(a);
    test.show(b);
    test.show(c);

    return 0;
}
