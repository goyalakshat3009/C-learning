#include <iostream>
#include <string>
using namespace std;

class Teacher {
private:
    double salary;

public:
    string name;
    string dept;
    string subject;

    // parameterized constructor
    Teacher(string name, string dept, string subject, double salary) {
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }

    // copy constructor
    Teacher(Teacher &orgObj) { // pass by reference
        cout << "i am custom copy constructor...\n";
        this->name = orgObj.name;
        this->dept = orgObj.dept;
        this->subject = orgObj.subject;
        this->salary = orgObj.salary;
    }

    void changeDept(string newDept) {
        dept = newDept;
    }

    void getinfo() {
        cout << "name : " << name << endl;
        cout << "subject : " << subject << endl;
    }
};

int main() {
    Teacher t1("Akshat", "ComputerScience", "C++", 25000);
    // t1.getinfo();

    Teacher t2(t1); // custom copy constructor -invoke
    t2.getinfo();

    return 0;
}
