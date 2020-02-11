#include <iostream>
#include <time.h>

using namespace std;

// 默认参数从右向左默认，中间不能跳跃。
// 默认参数在声明不在定义

void weather_cast(string weater = "PM2.5")
{
    time_t t = time(NULL);

    struct tm *time = localtime(&t);
    cout << time->tm_hour << endl;
    cout << time->tm_mday << endl;
    cout << time->tm_min << endl;
    cout << time->tm_mon << endl;
    cout << time->tm_sec << endl;
    cout << time->tm_wday << endl;
    cout << time->tm_yday << endl;
    cout << time->tm_year + 1900 << endl;
    char tmp[64];
    strftime(tmp, 64, "%Y %m %d %X %A %H:%M:%S", time);
    cout << tmp << endl;

    cout << weater << endl;
}

int volume(int l, int w = 10, int h = 20)
{
    return l * w * h;
}

int main()
{
    weather_cast();
    cout << volume(5) << endl;
    cout << volume(5, 2) << endl;
    return 0;
}
