#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    {
        stack destructor; // 测试析构函数
    }
    stack st;
    st.init();

    for (char c = 'a'; !st.is_full() && c != 'z'; c++) {
        st.push(c);
    }

    while (!st.is_empty()) {
        cout << st.pop() << endl;
    }
    return 0;
}
