#ifndef DESTRUCT_DEMO_H
#define DESTRUCT_DEMO_H

// 默认参数比默认构造函数更好
// 参数列表：函数声明之后，实现之前，由：开头

class destruct_demo
{
public:
    destruct_demo(int len = 100);

    ~destruct_demo();

private:
    int x;
    int y;
    int z;
    char *name;
};

#endif // DESTRUCT_DEMO_H
