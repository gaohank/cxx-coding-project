#include <iostream>

using namespace std;

// 指向类成员的指针
// 类 成员变量 成员函数
// <成员类型> 类名::* 指针名 = &类名::成员变量
// 函数返回类型 (类名::* 函数指针名)(参数列表) = &类名::成员函数
// .*
// ->*

class A {
public:
    A(int var1, int var2) : x(var1), y(var2){
        parr[0] = &A::a;
        parr[1] = &A::b;
        parr[2] = &A::c;
    }

    void select(int idx)
    {
        (this->*parr[idx])();
    }

    void display()
    {
        cout << x << endl;
        cout << y << endl;
    }

    void a() {cout << "test a func " << endl;}
    void b() {cout << "test b func " << endl;}
    void c() {cout << "test c func " << endl;}

public:
    int x;
    int y;
    void (A::*parr[3])();
};

int main()
{
    A a(10,20);
    int A:: *px = &A::x;
    int A:: *py = &A::y;
    void (A:: *pf)() = &A::display;


    cout << a.*px << endl;
    cout << a.*py << endl;
    (a.*pf)();

    A *pa = new A(100, 200);
    cout << pa->*px << endl;
    cout << pa->*py << endl;
    (pa->*pf)();

    cout << sizeof(A) << endl;

    a.select(1);

    return 0;
}
