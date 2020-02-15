#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream pic("test.jpg", ios::binary);
    // 关闭空格过滤
    pic.unsetf(ios::skipws);
    unsigned char c;
    vector<unsigned char> obj;
    // 获得所有的二进制数据
    while (pic >> c) {
        obj.push_back(c);
    }
    pic.close();
    cout << obj.size() << endl;
    for (int i = 0; i < obj.size(); i ++) {
        printf("%02x", obj[i]);
    }
    return 0;
}
