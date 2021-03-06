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
    printf("\n");
    unsigned char *data = obj.data();
    for (int i = 0; i < obj.size(); i ++) {
        printf("%02x", data[i]);
    }

    // 追加形式写入文件
    ofstream out("file.txt", ios::app);
    if (out.fail()) {
        cout << "ofstream error!" << endl;
        exit(0);
    }
    out << "hello" << endl << "world" << endl;
    out.close();
    return 0;
}
