// (Operator overloading) Write a program in which you set details as:

// Obj1(“My name --, my age --, my id--”)
// obj2(“ courses course --, credithrs --)
// obj3(“pkr dues -- ,gpa --, cgpa--”)”)
// obj4(“my elective courses – credit hrs --”)
// Concatenate all objects that has converted to one paragraph.

#include <iostream>
using namespace std;
class variable
{
string xyz;
public:
variable(){}

variable(string xyz)
{
this->xyz=xyz;
}
void operator+(variable);
void display();
};
void variable:: operator+(variable a)
{
string m = xyz + a.xyz;
cout<<m<<endl;
}
int main()
{
variable a1("My Name : Ahsan  ,My Age : 20 ,My ID : sp22-bscs-0098");
variable a2("COURSE : OOPlab, Credit Hour: 3");
a1+a2;
variable a3("DUES : 5600,GPA : 3.2, CGPA : 2.98");
variable a4("CALCULUS , 2");
a3+a4;

return 0;
}