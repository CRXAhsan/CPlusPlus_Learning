#include<iostream>
using namespace std;

int main()
{
    string fname, lname, fullname, uniName;
    // get line functions for getting input with spaces
    cout<<"What is your First name?\n";
    getline(cin, fname);
    cout<<"What is your Last name?\n";
    getline(cin, lname);
    cout<<"What is your University name?\n";
    getline(cin, uniName);

    // adding to string into a single string means concatenation
    fullname = fname + lname;

    //another method o f adding string is append 
    fullname = fname.append(lname);

    //if we want to find the lenth of the string so use length() func or size() func
    cout<<"\nTotal characters from length func "<<uniName.length();
    cout<<"\nTotal characters from size func "<<uniName.size();

    // if we want to manipulate the string character so 
    string mystring = "Hello";
    mystring[0] = 'J';
    cout<<mystring;



    cout<<"#### Information ####\n";
    cout<<"Name : "<<fullname;
    cout<<"\nUniversity Name : "<<uniName<<"\n";
}