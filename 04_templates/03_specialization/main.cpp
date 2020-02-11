#include <iostream>
using namespace std;

template<class T1,class T2>
class Test{
public:
    Test(T1 i,T2 j):a(i),b(j){cout<<"模板类"<<endl;}
private:
    T1 a;
    T2 b;
};

template<>   //全特化，由于是全特化，参数都指定了，参数列表故为空。
class Test<int ,char>{
public:
    Test(int i,char j):a(i),b(j){cout<<"全特化"<<endl;}
private:
    int a;
    int b;
};

template<class T2> //由于只指定了一部分参数，剩下的未指定的需在参数列表中，否则报错。
class Test<char,T2>{
public:
    Test(char i,T2 j):a(j),b(j){cout<<"个数偏特化"<<endl;}
private:
    char a;
    T2 b;
};

template<class T1,class T2> //这是范围上的偏特化
class Test<T1*,T2*>{
public:
    Test(T1* i,T2* j):a(i),b(j){cout<<"指针偏特化"<<endl;}
private:
    T1* a;
    T2* b;
};

template<class T1,class T2>//同理这也是范围上的偏特化
class Test<T1 const,T2 const>{
public:
    Test(T1 i,T2 j):a(i),b(j){cout<<"const偏特化"<<endl;}
private:
    T1 a;
    T2 b;
};

int main()
{
    int a;
    Test<double,double> t1(0.1,0.2);
    Test<int,char> t2(1,'A');
    Test<char,bool> t3('A',true);
    Test<int*,int*> t4(&a,&a);
    Test<const int,const int> t5(1,2);
    return 0;
}