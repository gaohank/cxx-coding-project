#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

// destructor 用于对象销毁时的内存处理工作， 无参数， 无返回值

class stack
{
public:
    stack();            // constructor构造器，无返回，自动调用；
                        // 可有参数
                        // 没有构造器时，系统默认提供无参构造器
                        // 重载和默认不同时存在
    ~stack() {
        cout << "stack destructor" << endl;
    }
    void init();
    bool is_empty();
    bool is_full();
    char pop();
    void push(char c);

private:
    int top;
    char space[1024];
};

#endif // STACK_H
