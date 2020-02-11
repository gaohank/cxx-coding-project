#include <iostream>

using namespace std;

// public不影响子类成员的访问，影响父类成员在子类的访问

// 初始化顺序，父类初始化、类对象初始化、子类初始化

// 赋值兼容

class student {
public:
    student(){}
    student(string, int, float);
    void dis()
    {
        cout << "stu" << endl;
        cout << name << age << score << endl;
    }
private:
    string name;
    int age;
    float score;
};

student::student(string sn, int a, float s) : name(sn), age(a), score(s)
{

}

class boystudent : public student
{
public:
    boystudent(){}
    void dis()
    {
        cout << "boy" << endl;
    }
};

int main()
{
    student st("hank", 28, 90);
    boystudent boy;
    st.dis();
    boy.dis();
    return 0;
}

#include <string.h>

class stu {
public:
    stu(string na) : len(strlen(na.c_str())),name(na)
    {

    }

    void dis()
    {
        cout << len << endl;
    }

private:
    string name;
    int len;
};

int main1()
{
    stu st("hello");
    st.dis();
    return 0;
}
