#ifndef MYSTRING_H
#define MYSTRING_H

#include <stdio.h>

class mystring
{
public:
    mystring(const char *str = "");
    mystring(const mystring &another);
    ~mystring();

    char *c_ptr();
    void display();
    mystring &operator=(const mystring &another);
    mystring operator+(const mystring &another);
    char& operator[](int pos);
    bool operator>(const mystring &another);
    bool operator<(const mystring &another);
    bool operator==(const mystring &another);
    char at(int pos);

private:
    char *_str;
    int size;
};

#endif // MYSTRING_H
