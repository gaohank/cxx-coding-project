#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class mypow {
public:
    int operator()(int i)
    {
        return i * i;
    }
};

bool mycomplare(int i, int j)
{
    return i < j;
}

class mycom {
public:
    int operator()(int i, int j)
    {
        return i < j;
    }
};

int main()
{
    mypow a;
    cout << a(5) << endl;

    int array[8] = {10, 5, 2, 9, 20, 61, 4, 1};
    vector<int> vi(array, array + 8);

    sort(vi.begin(), vi.end(), mycomplare);
//    sort(vi.begin(), vi.end(), mycom());

    for (int i = 0; i < 8; i++) {
        cout << vi[i] << endl;
    }

    return 0;
}
