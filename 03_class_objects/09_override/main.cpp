#include <iostream>

using namespace std;

class Human {
public:
	Human() {
	
	}

	virtual void display() {
		cout << "Human display" << endl;
	}

	virtual void run() {
		cout << "Human run" << endl;
	}
};

class Man : public Human {	
private:
	int age;
	int sex;

public:
	Man() {
	
	}

	virtual void display() {
		cout << "Man display" << endl;
	}

	virtual void run() {
		cout << "Man run" << endl;
	}
};

int main(int argc, const char *argv[])
{
	Human *ph = new Man;

	ph->display();
	ph->run();

	return 0;
}
