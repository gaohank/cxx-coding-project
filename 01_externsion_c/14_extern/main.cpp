#include <iostream>
#include "head.h"

int ctype_function(int a, int b) {
    return a + b;
}

using namespace std;

int main() {
    cout << ctype_function(1, 2) << endl;
}