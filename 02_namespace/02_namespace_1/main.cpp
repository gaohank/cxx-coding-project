#include <iostream>

using namespace std;

// namespace 空间名

namespace cities {
    int x;
    int y;
    namespace village {
        int m;
        int n;
    }
}

namespace contries {
    int x;
    int y;
}

int main()
{
    cities::x = 200;

    cout << "cities::x = " << cities::x << endl;

    { // 添加using的作用域
        using namespace cities;
        y = 20;

        cout << "using namespace cities: x = " << x << endl;
        cout << "using namespace cities: y = " << cities::y << endl;
    }
    {
        using contries::x;
        x = 100;
        cout << "using namespace contries::x, x = " << x << endl;
    }

    using namespace cities::village;
    m = 100;
    n = 200;

    int x = 0, y = 100;
    cout << "global namespace: " << x << y << endl;

    return 0;
}
