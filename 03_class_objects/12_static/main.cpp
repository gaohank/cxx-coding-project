#include <iostream>

using namespace std;

// 在类内部的表现用来实现簇类对象间的数据共享。.data段中
// static修饰成员函数，用来操作static成员变量，属于类，也属于对象，总归属于类。

class A {
public:
    int a;
    int b;
    static int c;

    void display()
    {
        cout << c << endl;
    }

    void modify(int var)
    {
        c = var;
    }

    static int& getc()
    {
        return c;
    }

    static string& getstr()
    {
        return str;
    }

    static int& getval()
    {
        return d;
    }
private:
    static string str;
    static int d;
    static const int e = 11;
};

int A::c = 0; // 必须进行初始化

string A::str = "";
int A::d =10000;     // 初始化类变量

int main()
{
    A a,b,c;
    cout << sizeof(a);
    cout << sizeof(b);
    a.display();
    a.modify(200);
    b.display();
    c.display();
    a.getc() = 100;
    cout << a.getc() << endl;

    a.getval() = 1000;
    return 0;
}
