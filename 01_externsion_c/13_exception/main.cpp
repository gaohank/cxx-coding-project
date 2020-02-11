#include <iostream>

using namespace std;

class zero_exception : public exception {
public:
    const char *what() const noexcept override {
        return "Division by zero condition!";
    }
};

double division(int a, int b)
{
    if (b == 0) {
        // 通过throw抛出异常
//        throw "Division by zero condition!";
        throw zero_exception();
    }
    return (double)a / b;
}


int main() {
    try {
        double num = division(100, 0);
        cout << num << endl;
    } catch (int a) {
        cout << "int" << endl;
    } catch (double b) {
        cout << "double" << endl;
    } catch (const char * msg) {
        cout << "const char *" << endl;
    } catch (exception& e) {
        cout << "zero_exception" << endl;
    } catch (...) { // 捕获所有其他类型异常
        cout << "catch exception" << endl;
    }

    return 0;
}