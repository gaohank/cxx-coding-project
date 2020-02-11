#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string s1("china"), s2 = " is good", s3;
    s3 = s1 + s2;
    cout << s3 << endl;
    cout << sizeof(string) << sizeof(s1) << endl;
    cout << s3.size() << endl;
    s1.swap(s2); // 交换
    cout << s1 << s2 << endl;
    cout << s1.find("go", 0) << endl; // 查找字符或者数组

    s2 = s3;
    if (s1 > s2) cout << "s1 > s2" << endl;
    else if (s1 == s2) cout << "s1 = s2" << endl;
    else cout << "s1 < s2" << endl;

    cout << s3[2] << endl;

    char buf[1024] = {0};
    strcpy(buf, s3.c_str()); // c_str为取指针

    cout << buf << endl;

    string str = "   123    ";
    int fpos = str.find_first_not_of(' ');
    int lpos = str.find_last_not_of(' ');
    cout << fpos << lpos << endl;

    str.erase(0, fpos);
    str.erase(lpos + 1);
    cout << str << endl;

    return 0;
}
