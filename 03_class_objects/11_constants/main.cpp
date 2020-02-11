#include <iostream>

using namespace std;

// 1.const修饰成员变量，只能在参数列表中，不能被修改；
// 2.const修饰成员函数，在函数声明后，函数体之前；声明和定义处都要有；
// 3.const修饰成员函数，不会修改成员变量；
// 4.const修饰成员函数，只能访问const的成员函数。
// 5.const修饰成员函数，可以构成重载；
// 6.const修饰对象，从对象的层面不修改成员变量，只能调用const成员函数。

class A {
private:
    const int wtb_len = 1024;
    const int mvb_len;
public:
    A(int num);
    void c_ptr() const {}
    void display() const {
        cout << wtb_len << endl;
        cout << mvb_len << endl;
    }
};

A::A(int num): mvb_len(num) {}

int main()
{
    A a(100);
    a.display();
    return 0;
}
