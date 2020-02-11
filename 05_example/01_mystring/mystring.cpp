#include "mystring.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace  std;

mystring::mystring(const char *str)
{
    size = strlen(str);
    _str = new char[size + 1];
    memset(_str, 0, size + 1);
    strcpy(_str, str);
}

mystring::mystring(const mystring &another)
{
    delete []_str;
    size = another.size;
    _str = new char[size + 1];
    memset(_str, 0, size + 1);
    strcpy(_str, another._str);
}

mystring::~mystring()
{
    delete []_str;
}

char *mystring::c_ptr()
{
    return _str;
}

void mystring::display()
{
    cout << _str << endl;
}

mystring &mystring::operator=(const mystring &another)
{
    if (this == &another) {
        return *this;
    }
    delete []_str;
    size = another.size;
    _str = new char[size + 1];
    memset(_str, 0, size + 1);
    strcpy(_str, another._str);

    return *this;
}

mystring mystring::operator+(const mystring &another)
{
    mystring tmp;
    delete []tmp._str;
    tmp.size = this->size + another.size;
    tmp._str = new char[tmp.size + 1];
    memset(tmp._str, 0, tmp.size + 1);
    strcat(tmp._str, this->_str);
    strcat(tmp._str, another._str);
    return tmp;
}

char& mystring::operator[](int pos)
{
    return this->_str[pos];
}

bool mystring::operator>(const mystring &another)
{
    if (strcmp(_str, another._str) > 0) {
        return true;
    }
    return false;
}

bool mystring::operator<(const mystring &another)
{
    if (strcmp(_str, another._str) < 0) {
        return true;
    }
    return false;
}

bool mystring::operator==(const mystring &another)
{
    if (strcmp(_str, another._str) == 0) {
        return true;
    }
    return false;
}

char mystring::at(int pos)
{
    return _str[pos];
}
