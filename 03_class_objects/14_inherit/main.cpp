#include <iostream>

using namespace std;

class A {
public:
    A(int a = 1, int b = 2, int c = 3) :
        x(a), y(b), z(c)
    {

    }
    ~A()
    {}
    void dis() const
    {
        cout << "x" /*<< x*/ << endl;
    }
//    friend void getdis(const A& another);
private:
    int x;
    int y;
    int z;
};

class B : public A
{
public:
    B(int a, int b, int c, int tmp) :
        A(a,b,c), var(tmp)
    {

    }
    void dis() const
    {
        cout << "var" /*<< var*/ << endl;
    }

    friend void getdis(const A& another);
private:
    int var;
};

void getdis(const A& another)
{
    another.dis();
}

#include <iomanip>

int main()
{
    B tb(1,2,3,4);
    getdis(tb);
    tb.dis();

    double dd=123.4567;
    cout << setprecision(ios::scientific) << dd << endl;

    return 0;
}
