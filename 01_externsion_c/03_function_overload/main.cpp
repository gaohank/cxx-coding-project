#include <iostream>
#include <stdio.h>

using namespace std;

// 函数参数个数、类型、顺序不同，构成函数重载
// 返回值不构成重载条件
// 底层实现通过name mangling命名倾轧

int func(int a)
{
    printf("func - int a = %d\n", a);
    return 0;
}

int func(long a)
{
    printf("func - long a = %ld\n", a);
    return 0;
}

int func(char b)
{
    printf("func - char b = %c\n", b);
    return 0;
}

int func(int a, char b)
{
    printf("func int a = %d - char b = %c = %c\n", a, b);
    return 0;
}

int func(float f)
{
    printf("func - float f = %f\n", f);
    return 0;
}

int func(double db)
{
    printf("func - double db = %f\n", db);
    return 0;
}

int func(char b, int a)
{
    return 0;
}

int myabs(int data)
{
    return data > 0 ? data : -data;
}

float myabs(float data)
{
    return data > 0 ? data : -data;
}

int main()
{
    int a = 0;
    char b = 'w';
    func(a);
    func(b);

    float f = myabs(5.67f);
    cout << f << endl;

    func(1);
    func(3.14);
    func(3.14f);

    return 0;
}
