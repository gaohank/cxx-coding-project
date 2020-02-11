#include <iostream>

using namespace std;

// 宏函数，避免压栈，易产生歧义，易使代码膨胀，不进行类型检查
#define SQR(i) ((i)*(i))

inline int sqr(int i)
{
    return (i)*(i);
}

int main()
{
    int i = 5;
    cout << SQR(i ++) << endl;
    cout << sqr(i ++) << endl;
    return 0;
}
