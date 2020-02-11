#include <iostream>

using namespace std;

class A {
public:
    A(int x = 0, int y = 0) : a(x), b(y)
    {}
    void print()
    {
        cout << a << endl;
        cout << b << endl;
    }
private:
    int a;
    int b;
};

class B {
public:
    B(int len = 100) : size(len) {
        p = new char[len];
    }
    B(const B &another) {
        size = another.size;
        p = new char[size];
        cout << "copy constructor" << endl;
    }
    ~B() {
        delete []p;
    }

    void dis() {
        cout << "size = " << size << endl;
    }
private:
    int size;
    char *p;
};

int main()
{
    A temp(4,5);
    temp.print();

    A text(temp);
    text.print();

    B b1(1024);
    B b2(b1);
    B b3 = b2;  // = 也是拷贝构造函数
    B b4;
    b4 = b3;    // 赋值运算符重载，系统默认

    b4.dis();
    return 0;
}
