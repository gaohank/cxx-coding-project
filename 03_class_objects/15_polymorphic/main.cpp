#include <iostream>
using namespace std;

// 虚函数是在基类中使用关键字 virtual 声明的函数。在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到该函数。
// 我们想要的是在程序中任意点可以根据所调用的对象类型来选择调用的函数，这种操作被称为动态链接，或后期绑定

class Shape {
protected:
    int width, height;
public:
    explicit Shape( int a=0, int b=0)
    {
        width = a;
        height = b;
    }

    virtual int area()
    {
        cout << "Parent class area :" <<endl;
        return 0;
    }
};
class Rectangle: public Shape{
public:
    explicit Rectangle( int a=0, int b=0):Shape(a, b) { }
    int area() override
    {
        cout << "Rectangle class area :" <<endl;
        return (width * height);
    }
};
class Triangle: public Shape{
public:
    explicit Triangle(int a=0, int b=0):Shape(a, b) { }
    int area() override
    {
        cout << "Triangle class area :" <<endl;
        return (width * height / 2);
    }
};
// 程序的主函数
int main( )
{
    Shape *shape;
    Rectangle rec(10,7);
    Triangle  tri(10,5);

    // 存储矩形的地址
    shape = &rec;
    // 调用矩形的求面积函数 area
    shape->area();

    // 存储三角形的地址
    shape = &tri;
    // 调用三角形的求面积函数 area
    shape->area();

    return 0;
}