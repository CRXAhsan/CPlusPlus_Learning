#include "Person.h"

Person::Person()
{
    p = new Plot();
    h = new House();
    f = new Flat();
    s = new Shop();
    username = "";
    password = "";
}

void Person::login()
{
    system("cls");
    cout << "#########################################################################\n";
    cout << "#\t\t\t\t\t\t\t\t\t#\n#\t\t\t\t\t\t\t\t\t#\n";

    cout << "#\t\t\t      Login Creditionals    \t\t\t#" << endl;

    cout << "\n\n\t\tEnter Username: ";
    cin >> username;
    fflush(stdin);

    cout << "\n\t\tEnter Password: ";
    cin >> password;
    fflush(stdin);

    cout << "\n\n#########################################################################\n";
}

string Person::login_newAccount()
{
    do
    {
        system("cls");
        cout << "#########################################################################\n";
        cout << "#\t\t\t\t\t\t\t\t\t#\n#\t\t\t\t\t\t\t\t\t#\n";

        cout << "#\t\t\t      CreateNew Account    \t\t\t#" << endl;

        cout << "\n\n\t\tEnter Username: ";
        cin >> username;
        fflush(stdin);

        cout << "\n\t\tEnter Password: ";
        cin >> password;
        fflush(stdin);

        cout << "\n\t\tEnter Password: ";
        cin >> confirmPassword;
        fflush(stdin);

        if (password == confirmPassword)
        {
            cout << "\t\t\t\tAccount Create Successfully...\n";
            confirmation++;
        }
        else
        {
            cout << "\t\t\t\t Username Or Password Wrong!... \n";

        }

        cout << "\n\n#########################################################################\n";

    } while (confirmation == 0);
    system("pause");

    str = username + " " + password;
    return str;
}

void Person::checkUser()
{
}

void Person::showUser()
{

}

void Person::deleteUser()
{

}

void Person::addUser()
{
}

void Person::Menu()
{
}

void Person::checkIfUser()
{
}

Person::~Person()
{
    
}
