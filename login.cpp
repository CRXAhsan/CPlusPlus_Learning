#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Person
{
    protected:
        string username, password,confirmPassword, str;
        
    public:
        ifstream read;
        ofstream write;

    Person()
    {
        username="";
        password="";
    }

        void login()
        {
            cout<<"Enter Username: ";
            cin >>username;
            fflush(stdin);
            cout<<"Enter Password: ";
            cin >>password;
            fflush(stdin);
            
        }

        string login_newAccount()
        {
            do
            {
            cout<<"Enter Username: ";
            cin >>username;
            fflush(stdin);
            cout<<"Enter Password: ";
            cin >>password;
            fflush(stdin);
            cout<<"Enter Password: ";
            cin >>confirmPassword;
            fflush(stdin);

            } 
            while (password == confirmPassword);

            str = username + " " + password;
            return str;
        }


    
     void menu(){}
};

class admin : public Person
{
    private:
        string actualUser, actualPassword;
        
        
    public:

        admin()
        {
            
        }

        void checkAdmin()
        {
            int repeat=0;
            do
            {
                login();
            
            read.open("admin.txt", ios::in);

            if (read.is_open())
            {
                while (getline(read, str))
                {
                    int start, end;

                    start=0;
                    end = str.find(" ",start);
                    actualUser = str.substr(start, end-start);
                    start=end+1;
                    end = str.find(" ",start);
                    actualPassword = str.substr(start, end-start);
                    if (actualUser == username)
                    {
                        if(actualPassword == password)
                        {
                            repeat++;
                        }
                        else
                        {
                            cout<<"You enter wrong password\n";
                        }
                    }
                    else
                    {
                        cout<<"You enter wrong username\n";
                    }
                }
            }
            else
            {
                cout<<"[ERROR] FAILED TO OPEN FILE\n";
            }
            read.close();

            }
            while (repeat == 0);
        }        

        void menu()
        {
            int choice;
            cout<<"What do you want to do? \n";
            cout<<"1. Display all Sellers \n";
            cout<<"2. Display all Buyers \n";
            cout<<"3. Display Properties \n";
            cin >>choice;
            switch (choice)
            {
            case 1:
                displaySellers();
                break;
            
            case 2:
                displayBuyers();
                break;

            case 3:
                cout<<"Which property listing you want to dispaly\n";
                cout<<"1. Plot \n";
                cout<<"2. House\n";
                cout<<"3. Flat \n";
                cout<<"4. Shop \n";
                cin >>choice;
                switch (choice)
                {
                case 1:
                    cout<<"here are all plots\n";
                    break;
                
                case 2:
                    cout<<"here are all house\n";
                    break;

                case 3:
                    cout<<"here are all flats\n";
                    break;
                
                case 4:
                    cout<<"here are all shops\n";
                    break;
                }
                break;
            }
        }

        void displaySellers()
        {
            system("cls");
            cout<<"#################### Sellers ####################\n";
            cout<<"#\t\t\t\t\t\t#\n";
            read.open("seller.txt", ios::in);

            if (read.is_open())
            {
                while (getline(read, str)){
                int start,end;
                
                start=0;
                end = str.find(" ",start);
                username = str.substr(start, end-start);
                cout<<"# Username: "<<username;
                
                start=end+1;
                end = str.find(" ",start);
                password = str.substr(start, end-start);
                cout<<"\t\t\t\t#\n# Password: "<<password;
                cout<<"\t\t\t\t#\n#\t\t\t\t\t\t#\n";
            }
            }
            else
            {
                cout<<"[ERROR] FAILED TO OPEN FILE\n";
            }

            read.close();
            cout<<"#\t\t\t\t\t\t#\n";
            cout<<"#################################################\n";
            
        }

        void displayBuyers()
        {
            read.open("buyer.txt", ios::in);

            if (read.is_open())
            {
                while (getline(read, str)){
                int start,end;
                
                start=0;
                end = str.find(" ",start);
                username = str.substr(start, end-start);
                cout<<"Username: "<<username<<endl;
                
                start=end+1;
                end = str.find(" ",start);
                password = str.substr(start, end-start);
                cout<<"Password: "<<password<<endl<<endl;
            }
            }
            else
            {
                cout<<"[ERROR] FAILED TO OPEN FILE\n";
            }

            read.close();
        }


};

int main()
{
    admin per;
    // per.checkAdmin();
    per.displaySellers();
}