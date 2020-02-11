#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

// new delete是关键字。

int main1()
{
    int *p = (int *)malloc(sizeof(int));
    int *p1 = new int(200);
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

int main()
{
    int *pi = new int;
    int *pbuf = new int[200];
    delete pi;
    delete[] pbuf;

    int *p = new int[5]{0};
    int **ppi = new int*[5]{NULL};
    int (*pii)[5] = new int[4][5]{{0}};
    delete[] p;
    delete[] ppi;
    delete[] pii;

}
