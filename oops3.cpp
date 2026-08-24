#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;

   // Person(string name, int age) {
   //    this->name=name;
   //     this->age = age;
    // }
    Person() {

    }
};

class Student : public Person {
public:
    int rollno;

    void getinfo() {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "rollno: " << rollno << endl;
    }
};

int main() {
    Student s1;
    s1.name = "rahul kumar";
    s1.age = 21;
    s1.rollno = 1234;

    s1.getinfo();
    return 0;
};