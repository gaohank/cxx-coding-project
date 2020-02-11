#include <iostream>
#include "dog.h"
#include "cat.h"

using namespace std;
using namespace animal;

// 多人协作开发

namespace spa {
    int x;
}

namespace spa {
    int y;
}

int main()
{
    using namespace spa;
    x = 100;
    y = 200;
    cout << x << y << endl;

    dog d;
    cat c;
    return 0;
}


