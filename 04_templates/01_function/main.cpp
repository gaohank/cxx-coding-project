#include <iostream>

using namespace std;

template <class T> void dis(T t) {
    cout << t << endl;
}

template <class T> void print(T& t) {
    cout << t << endl;
}

template <class T1, class T2> void fun(T1 a, T2 b) {
    cout << "template function" << endl;
}

// 全特化模板函数
// 函数模板没有偏特化
template <> void fun(int a, int b) {
    cout << "全特化" << endl;
}

int main() {
    dis(1);
    dis("hank");
    dis(1.2);

    int num = 100;
    int &n = num;
    print(n);

    fun(1, 2);
    fun(1, 'a');
    return 0;
}