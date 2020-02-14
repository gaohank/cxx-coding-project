#include <iostream>
#include "head.h"

using namespace std;

int ctype_function(int a, int b) {
    cout << "this is c compile function" << endl;
    return a + b;
}

using namespace std;

int main() {
    cout << ctype_function(1, 2) << endl;
}