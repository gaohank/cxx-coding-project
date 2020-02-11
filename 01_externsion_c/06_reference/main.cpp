#include <iostream>

using namespace std;

// 引用本质是一个const的指针
// 引用时一种声明关系，声明的时候必须要初始化
// 引用不占用空间
// 一经申明，不可变更
// 可以建立引用的引用
// 指针有引用，不应该有引用的指针
// 不能定义引用的引用， int && a;非法
// 不能定义引用的指针， int & *p;非法
// 不能定义引用的数组， int& rp[];非法，rp为int & *类型。
// const对象的引用必须是const的

void test()
{
    int arr[] = {1,2,3,4,5};
    int (&rarr)[5] = arr;
    cout << rarr[1] << endl;
}

void swap(int& ra, int& rb)
{
    ra ^= rb;
    rb ^= ra;
    ra ^= rb;
}

void swap(char* & rpa, char* & rpb)
{
    char *t = rpa;
    rpa = rpb;
    rpb = t;
}

int main()
{
    int a = 200, b = 400; // 声明a
    int& ra = a;
    int& rra = ra;
    cout << sizeof(a) << sizeof(ra) << endl;
    cout << a << ra << rra << endl;
    swap(a, b);
    cout << a << b << endl;

    const char *c1 = "hello", *c2 = "world";
    swap(c1, c2);
    cout << c1 << endl << c2 << endl;

    test();

    return 0;
}
