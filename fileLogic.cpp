#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string input();

int main()
{

    string str, fname, lname, username, password;
    char choice;
    ofstream write;
    ifstream read;
    //---------------use for writing data file--------------------------------
    // write.open("user.txt", ios::app);
    // do
    // {
    //     str = input();
    //     if (write.is_open())
    //     {
    //         write << str << endl;
    //     }
    //     else
    //     {
    //         cout << "[ERROR] FAILED TO OPEN FILE";
    //     }
    //     cout << "Would you like to add another user(Y/n):";
    //     cin >> choice;

    // } while (choice == 'y' || choice == 'Y');
    // write.close();

    //---------------use for reading data file--------------------------------

    read.open("user.txt", ios::in);
    if (read.is_open())
    {
        while (getline(read, str))
        {
            int start, end;
            cout << str << endl;
            start = 0;
            end = str.find(" ", start);
            fname = str.substr(start, end - start);
            cout << "First Name: " << fname << endl;
            start = end + 1;
            end = str.find(" ", start);
            lname = str.substr(start, end - start);
            cout << "Last Name: " << lname << endl;
            start = end + 1;
            end = str.find(" ", start);
            username = str.substr(start, end - start);
            cout << "Username: " << username << endl;
            start = end + 1;
            end = str.find(" ", start);
            password = str.substr(start, end - start);
            cout << "Password: " << password << endl;
        }
    }
    else
    {
        cout << "[ERROR] FAILED TO OPEN FILE\n";
    }
    read.close();
}

string input()
{
    string fname, lname, username, password, str;

    cout << "Enter first name: ";
    cin >> fname;
    fflush(stdin);
    cout << "Enter last name: ";
    cin >> lname;
    fflush(stdin);
    cout << "Enter username: ";
    cin >> username;
    fflush(stdin);
    cout << "Enter password: ";
    cin >> password;
    fflush(stdin);

    str = fname + " " + lname + " " + username + " " + password;
    return str;
}