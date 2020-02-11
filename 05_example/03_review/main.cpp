#include <iostream>

using namespace std;

// 1.运算符重载    全局函数   成员函数

// 能返回引用就返回引用
// 能返回const就返回const

class A {
public:
    A()
    {
        cout << "A()" << endl;
    }
    ~A()
    {
        cout << "~A()" << endl;
    }

    void display()
    {
        cout << "display" << endl;
    }

private:
    int x ,y;
};

class smt {
public:
    smt(A* p)
    {
        ptr = p;
    }
    ~smt()
    {
        delete ptr;
    }

    A *operator->()
    {
        return ptr;
    }

private:
    A *ptr;
};

int main()
{
    smt s(new A);
    s.operator->()->display();
    return 0;
}
