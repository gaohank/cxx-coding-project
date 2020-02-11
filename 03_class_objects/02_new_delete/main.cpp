#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

// new delete是关键字。

class A {
public:
    A()
    {
        cout << "A()" << endl;
    }
    ~A()
    {
        cout << "~A()" << endl;
    }
    void *operator new[](size_t size)
    {
        cout << "new[]" << endl;
        char *p = (char *)malloc(size);
        return p;
    }

    void operator delete[](void *p)
    {
        cout << "delete[]" << endl;
        free(p);
    }
};

int main()
{
    int *p = (int *)malloc(sizeof(int));
    int *p1 = new int(200);
    cout << sizeof(p) << endl;
    cout << *p1 << endl;

    string *pstr = new string("china");
    cout << *pstr << endl;


    struct man {
        int hight;
        int weight;
        int age;
        bool sex;
    };

    man *bob = new man{10, 20, 5, true};

    cout << bob->age << endl;
    cout << bob->hight << endl;
    cout << bob->weight << endl;

    return 0;
}

int main2()
{
    int *p = new int[5], i;
    memset(p, 0, sizeof(int[5]));
    for (i = 0; i < 5; i++)
        cout << p[i] << endl;

    int (*parr)[4] = new int[3][4]{{0}};
    memset(parr, 0, sizeof(int[3][4]));

    int j = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            cout << parr[i][j];
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}

int main1()
{
    int *pi = new int;
    int *pbuf = new int[200];
    cout << sizeof(pi) << endl;
    cout << sizeof(pbuf) << endl;
    cout << sizeof(*pi) << endl;
    cout << sizeof(*pbuf) << endl;
    delete pi;
    delete[] pbuf;
}
