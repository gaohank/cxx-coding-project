#include <iostream>
#include <string.h>

using namespace std;

class stu {

public:
    stu(char name[], int age) :
        name(name), age(age)
    {}

    ~stu() {
        delete[] name;
    }

    void display() {
        cout << name << age << endl;
    }

    stu& grow_up() {
        age++;
        return *this;
    }

    stu& operator=(stu &another);

private:
    char *name;
    int age;
};

stu& stu::operator =(stu &another)
{
    this->age = another.age;
    int len = strlen(another.name);
    this->name = new char[len + 1];
    strcpy(name, another.name);

    return *this;
}

int main()
{
    stu gao((char *)"gaosongling", 23);
    gao.grow_up().grow_up().grow_up().display();

    stu a((char *)"gao", 21),b((char *)"yang", 27),c((char *)"liu", 30);

    (a = b) = c;

    a.display();
    b.display();
    c.display();

    return 0;
}
