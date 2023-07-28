// (Function Overriding) Write a program in which create two classes
// Person(base class) and Student (Derived Class), in Person class,create
// DisplayMethod() in which print all personal details like: name, cnic, age,
// siblings, address. In student class , create DisplayMethod() in which print
// details like : University name, course name, studentid, earned credithrs,
// required credithrs, pkr dues, cgpa. Create object in which you call only
// Student class DisplayMetthod().

#include <iostream>
using namespace std;

class person
{
protected:
    string name, address;
    int age, cnic, siblings;

public:
    void setperson(string name, int cnic, int age, int siblings, string address)
    {
        this->name = name;
        this->cnic = cnic;
        this->age = age;
        this->siblings = siblings;
        this->address = address;
    }

    void displayMethod()
    {
        cout << "Name     : " << name << endl;
        cout << "CNIC     : " << cnic << endl;
        cout << "Age      : " << age << endl;
        cout << "Siblings : " << siblings << endl;
        cout << "Address  : " << address << endl;
    }
};

class student : public person
{
protected:
    string uniName, course, stu_id;
    int earnCredit, reqCredit, dues;
    float cgpa;

public:
    void setstudent(string uniNam, string stu_id, string course, int earnCredit, int reqCredit, int dues, float cgpa)
    {
        this->uniName = uniName;
        this->stu_id = stu_id;
        this->course = course;
        this->earnCredit = earnCredit;
        this->reqCredit = reqCredit;
        this->dues = dues;
        this->cgpa = cgpa;
    }

    void displaymethod()
    {
        cout << "University Name       : " << uniName << endl;
        cout << "Student ID            : " << stu_id << endl;
        cout << "Course Name           : " << course << endl;
        cout << "Earned Credit Hours   : " << earnCredit << endl;
        cout << "Required Credit Hours : " << reqCredit << endl;
        cout << "Total Dues            : " << dues << endl;
        cout << "TOtal CGPA            : " << cgpa << endl;
    }
};

int main()
{
    student s1;
    s1.setstudent("MAJU", "Sp22-bscs-0098", "OOPlab", 13, 16, 15000, 3.5);
    s1.displaymethod();
}