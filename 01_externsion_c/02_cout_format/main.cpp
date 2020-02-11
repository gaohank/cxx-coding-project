#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main()
{
    float a = 12345.678;
    printf("%.2f\n", a);
    cout << a << endl;
    cout << setw(10) << a << endl; // 设置输出长度
    cout << setfill('a') << setw(10) << a << endl; // 填充字符
    cout << setprecision(3) << setiosflags(ios::fixed) << a << endl; // 小数点三位
    cout << setiosflags(ios::left) << setw(8) << a << endl; // 左对齐
    cout << setfill('b') << setiosflags(ios::left) << setw(10) << a << endl;

    int num = 12345;
    cout << num << endl;
    cout << dec << num << endl;
    cout << oct << num << endl;
    cout << hex << num << endl;

    int sec = 0, min = 0, hour = 0;
    cout << setfill('0') << setw(2) << hour << ":" << setw(2) << min
         << ":" << setw(2) << sec << endl;
    return 0;
}
