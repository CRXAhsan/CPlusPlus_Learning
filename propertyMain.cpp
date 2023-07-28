#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//-------------------Property-----------------------------------------

class Property
{
public:
    Property()
    {
        price = "";
        sqft = "";
        address = "";
        name = "";
        contact = "";
        str1 = "";
        str = "";
        lineNumber = 0;
    }

    virtual void addProperty() = 0;
    virtual void deleteProperty() = 0;
    virtual void showProperty() = 0;
    string addPropertyInformation()
    {
        system("cls");
        cout << "################# Fill the Below Information #################\n";
        cout << "#\n";
        cout << "# Enter Your Name             : ";
        cin >> name;
        fflush(stdin);
        cout << "# Enter Your Contact Number   : ";
        cin >> contact;
        fflush(stdin);
        cout << "# Enter your Property Address : ";
        cin >> address;
        fflush(stdin);
        cout << "# Enter Area in sqft          : ";
        cin >> sqft;
        fflush(stdin);
        cout << "# Enter price                 : ";
        cin >> price;
        fflush(stdin);
        cout << "#\n";
        cout << "##############################################################\n";
        system("pause");

        str = name + " " + contact + " " + address + " " + sqft + " " + price;

        return str;
    }

    ~Property()
    {
    }

protected:
    string address;
    string sqft;
    string price;
    string str;
    string name;
    string contact;
    string str1;
    int lineNumber = 0;
    ofstream write;
    ifstream read;
};

//-------------------Plot-----------------------------------------

class Plot : public Property
{
public:
    Plot()
    {
    }

    void addProperty()
    {
        str1 = addPropertyInformation();

        write.open("plot.txt", ios::app);

        if (write.is_open())
        {
            write << str1 << endl;
            cout << "\n\n\t\t\t\tPlot Added Successfully...\n";
            system("pause");
        }
        else
        {
            cout << "[ERROR] FAILED TO OPEN FILE";
        }

        write.close();
    }

    void deleteProperty()
    {
        int choice;
        showProperty();

        cout << "\nEnter the Plot Listed No to delete : ";
        cin >> choice;

        //--------------to store the data first in temporary file----------------------

        write.open("temp.txt", ios::out);

        read.open("plot.txt");

        while (getline(read, str1))
        {
            ++lineNumber;

            if (lineNumber == choice)
            {
                continue;
            }

            write << str1 << "\n";
        }

        read.close();

        write.close();

        //---------------to update the original file------------------

        write.open("plot.txt", ios::out);

        read.open("temp.txt");

        while (getline(read, str1))
        {
            write << str1 << "\n";
        }

        read.close();

        write.close();

        cout << "\n\t\t\tPlot deleted Successfully...\n";
        system("pause");
    }

    void showProperty()
    {
        int count = 0;

        system("cls");
        cout << "################### All Listed Plots ####################\n";
        cout << "#\t\t\t\t\t\t\t#\n";

        read.open("plot.txt", ios::in);

        if (read.is_open())
        {
            while (getline(read, str1))
            {
                int start, end;

                cout << "#\t\t Plot No : " << ++count << "\t\t\t\t#\n";

                start = 0;
                end = str1.find(" ", start);
                name = str1.substr(start, end - start);
                cout << "# Seller Name        : " << name << "\t\t\t\t#\n";

                start = end + 1;
                end = str1.find(" ", start);
                contact = str1.substr(start, end - start);
                cout << "# Seller Contact No. : " << contact << "\t\t\t#\n";

                start = end + 1;
                end = str1.find(" ", start);
                address = str1.substr(start, end - start);
                cout << "# Address Of Plot    : " << address << "\t\t\t\t#\n";

                start = end + 1;
                end = str1.find(" ", start);
                sqft = str1.substr(start, end - start);
                cout << "# Area in Sqft       : " << sqft << "\t\t\t\t#\n";

                start = end + 1;
                end = str1.find(" ", start);
                price = str1.substr(start, end - start);
                cout << "# Price In PKR       : " << price << "\t\t\t\t#\n";
                cout << "#\t\t\t\t\t\t\t#\n";
            }
        }
        else
        {
            cout << "[ERROR] FAILED TO OPEN FILE\n";
        }

        read.close();
        cout << "#\t\t\t\t\t\t\t#\n";
        cout << "#########################################################\n";
        system("pause");
    }

    ~Plot()
    {
    }

private:
};

//-------------------Flat-----------------------------------------

class Flat : public Property
{
public:
    Flat()
    {
    }

    void addProperty()
    {
        str1 = addPropertyInformation();

        write.open("flat.txt", ios::app);

        if (write.is_open())
        {
            write << str1 << endl;
            cout << "\n\n\t\t\t\tFlat Added Successfully...\n";
            system("pause");
        }
        else
        {
            cout << "[ERROR] FAILED TO OPEN FILE";
        }

        write.close();
    }

    void deleteProperty()
    {
        int choice;
        showProperty();

        cout << "Enter the Flat Listed No to delete : ";
        cin >> choice;

        //--------------to store the data first in temp----------------------

        write.open("temp.txt", ios::out);

        read.open("flat.txt");

        while (getline(read, str1))
        {
            ++lineNumber;

            if (lineNumber == choice)
            {
                continue;
            }

            write << str1 << "\n";
        }

        read.close();

        write.close();

        //---------------to update the original file------------------

        write.open("flat.txt", ios::out);

        read.open("temp.txt");

        while (getline(read, str1))
        {
            write << str1 << "\n";
        }

        read.close();

        write.close();

        cout << "\n\t\t\tFlat deleted Successfully...\n";
        system("pause");
    }

    void showProperty()
    {
        int count = 0;

        system("cls");
        cout << "################### All Listed Flats ####################\n";
        cout << "#\t\t\t\t\t\t\t#\n";

        read.open("flat.txt", ios::in);

        if (read.is_open())
        {
            while (getline(read, str1))
            {
                int start, end;

                cout << "#\t\t Flat No : " << ++count << "\t\t\t\t#\n";

                start = 0;
                end = str1.find(" ", start);
                name = str1.substr(start, end - start);
                cout << "# Seller Name        : " << name << "\t\t\t\t#\n";

                start = end + 1;
                end = str1.find(" ", start);
                contact = str1.substr(start, end - start);
                cout << "# Seller Contact No. : " << contact << "\t\t\t#\n";

                start = end + 1;
                end = str1.find(" ", start);
                address = str1.substr(start, end - start);
                cout << "# Address Of Plot    : " << address << "\t\t\t\t#\n";

                start = end + 1;
                end = str1.find(" ", start);
                sqft = str1.substr(start, end - start);
                cout << "# Area in Sqft       : " << sqft << "\t\t\t\t#\n";

                start = end + 1;
                end = str1.find(" ", start);
                price = str1.substr(start, end - start);
                cout << "# Price In PKR       : " << price << "\t\t\t\t#\n";
                cout << "#\t\t\t\t\t\t\t#\n";
            }
        }
        else
        {
            cout << "[ERROR] FAILED TO OPEN FILE\n";
        }

        read.close();
        cout << "#\t\t\t\t\t\t\t#\n";
        cout << "#########################################################\n";
        system("pause");
    }

    ~Flat()
    {
    }

private:
};

//-------------------House-----------------------------------------

class House : public Property
{
public:
    House()
    {
    }

    void addProperty()
    {
        str1 = addPropertyInformation();

        write.open("house.txt", ios::app);

        if (write.is_open())
        {
            write << str1 << endl;
            cout << "\n\n\t\t\t\tHouse Added Successfully...\n";
            system("pause");
        }
        else
        {
            cout << "[ERROR] FAILED TO OPEN FILE";
        }

        write.close();
    }

    void deleteProperty()
    {
        int choice;
        showProperty();

        cout << "Enter the House Listed No to delete : ";
        cin >> choice;

        //--------------to store the data first in temp----------------------

        write.open("temp.txt", ios::out);

        read.open("house.txt");

        while (getline(read, str1))
        {
            ++lineNumber;

            if (lineNumber == choice)
            {
                continue;
            }

            write << str1 << "\n";
        }

        read.close();

        write.close();

        //---------------to update the original file------------------

        write.open("house.txt", ios::out);

        read.open("temp.txt");

        while (getline(read, str1))
        {
            write << str1 << "\n";
        }

        read.close();

        write.close();

        cout << "\n\t\t\tHouse deleted Successfully...\n";
        system("pause");
    }

    void showProperty()
    {
        int count = 0;

        system("cls");
        cout << "################## All Listed Houses ####################\n";
        cout << "#\t\t\t\t\t\t\t#\n";

        read.open("house.txt", ios::in);

        if (read.is_open())
        {
            while (getline(read, str1))
            {
                int start, end;

                cout << "#\t\tHouse No : " << ++count << "\t\t\t\t#\n";

                start = 0;
                end = str1.find(" ", start);
                name = str1.substr(start, end - start);
                cout << "# Seller Name        : " << name << "\t\t\t\t#\n";

                start = end + 1;
                end = str1.find(" ", start);
                contact = str1.substr(start, end - start);
                cout << "# Seller Contact No. : " << contact << "\t\t\t#\n";

                start = end + 1;
                end = str1.find(" ", start);
                address = str1.substr(start, end - start);
                cout << "# Address Of Plot    : " << address << "\t\t\t\t#\n";

                start = end + 1;
                end = str1.find(" ", start);
                sqft = str1.substr(start, end - start);
                cout << "# Area in Sqft       : " << sqft << "\t\t\t\t#\n";

                start = end + 1;
                end = str1.find(" ", start);
                price = str1.substr(start, end - start);
                cout << "# Price In PKR       : " << price << "\t\t\t\t#\n";
                cout << "#\t\t\t\t\t\t\t#\n";
            }
        }
        else
        {
            cout << "[ERROR] FAILED TO OPEN FILE\n";
        }

        read.close();
        cout << "#\t\t\t\t\t\t\t#\n";
        cout << "#########################################################\n";
        system("pause");
    }

    ~House()
    {
    }

private:
};

//-------------------Shop-----------------------------------------

class Shop : public Property
{
public:
    Shop()
    {
    }

    void addProperty()
    {
        str1 = addPropertyInformation();

        write.open("shop.txt", ios::app);

        if (write.is_open())
        {
            write << str1 << endl;
            cout << "\n\n\t\t\t\tShop Added Successfully...\n";
            system("pause");
        }
        else
        {
            cout << "[ERROR] FAILED TO OPEN FILE";
        }

        write.close();
    }

    void deleteProperty()
    {
        int choice;
        showProperty();

        cout << "Enter the Shop Listed No to delete : ";
        cin >> choice;

        //--------------to store the data first in temp----------------------

        write.open("temp.txt", ios::out);

        read.open("shop.txt");

        while (getline(read, str1))
        {
            ++lineNumber;

            if (lineNumber == choice)
            {
                continue;
            }

            write << str1 << "\n";
        }

        read.close();

        write.close();

        //---------------to update the original file------------------

        write.open("shop.txt", ios::out);

        read.open("temp.txt");

        while (getline(read, str1))
        {
            write << str1 << "\n";
        }

        read.close();

        write.close();

        cout << "\n\t\t\tShop deleted Successfully...\n";
        system("pause");
    }

    void showProperty()
    {
        int count = 0;

        system("cls");
        cout << "################### All Listed Shops ####################\n";
        cout << "#\t\t\t\t\t\t\t#\n";

        read.open("shop.txt", ios::in);

        if (read.is_open())
        {
            while (getline(read, str1))
            {
                int start, end;

                cout << "#\t\t Shop No : " << ++count << "\t\t\t\t#\n";

                start = 0;
                end = str1.find(" ", start);
                name = str1.substr(start, end - start);
                cout << "# Seller Name        : " << name << "\t\t\t\t#\n";

                start = end + 1;
                end = str1.find(" ", start);
                contact = str1.substr(start, end - start);
                cout << "# Seller Contact No. : " << contact << "\t\t\t#\n";

                start = end + 1;
                end = str1.find(" ", start);
                address = str1.substr(start, end - start);
                cout << "# Address Of Shop    : " << address << "\t\t\t\t#\n";

                start = end + 1;
                end = str1.find(" ", start);
                sqft = str1.substr(start, end - start);
                cout << "# Area in Sqft       : " << sqft << "\t\t\t\t#\n";

                start = end + 1;
                end = str1.find(" ", start);
                price = str1.substr(start, end - start);
                cout << "# Price In PKR       : " << price << "\t\t\t\t#\n";
                cout << "#\t\t\t\t\t\t\t#\n";
            }
        }
        else
        {
            cout << "[ERROR] FAILED TO OPEN FILE\n";
        }

        read.close();
        cout << "#\t\t\t\t\t\t\t#\n";
        cout << "#########################################################\n";
        system("pause");
    }

    ~Shop()
    {
    }

private:
};

//-------------------Person-----------------------------------------

class Person
{
public:
    Person()
    {
        p = new Plot();
        h = new House();
        f = new Flat();
        s = new Shop();
        username = "";
        password = "";
    }

    void login()
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

    string login_newAccount()
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

    virtual void checkUser() = 0;
    virtual void showUser() = 0;
    virtual void deleteUser() = 0;
    virtual void addUser() = 0;
    virtual void Menu() = 0;
    virtual void checkIfUser() = 0;

    ~Person()
    {
    }

protected:
    string username, password, confirmPassword, str, str1;
    string actualUser, actualPassword;
    int lineNumber, choice;
    int confirmation = 0;
    Plot *p;
    Shop *s;
    Flat *f;
    House *h;

    ifstream read;
    ofstream write;
};

//-------------------Seller-----------------------------------------

class Seller : public Person
{
public:
    Seller()
    {
    }

    void checkUser()
    {
        int repeat = 0;

        login();

        read.open("seller.txt", ios::in);

        if (read.is_open())
        {
            while (getline(read, str))
            {
                int start, end;

                start = 0;
                end = str.find(" ", start);
                actualUser = str.substr(start, end - start);
                start = end + 1;
                end = str.find(" ", start);
                actualPassword = str.substr(start, end - start);
                if (actualUser == username && actualPassword == password)
                {
                    repeat++;
                }
            }
        }
        else
        {
            cout << "[ERROR] FAILED TO OPEN FILE\n";
        }
        read.close();

        if (repeat > 0)
        {
            Menu();
        }
        else
        {
            cout << "Username or Password Wrong!...\n";
            system("pause");
            checkUser();
        }
    }

    void showUser()
    {
        int count = 0;

        system("cls");
        cout << "#################### Sellers ####################\n";
        cout << "#\t\t\t\t\t\t#\n";
        read.open("seller.txt", ios::in);

        if (read.is_open())
        {
            while (getline(read, str))
            {
                int start, end;

                cout << "#\t\t Seller No : " << ++count << "\t\t\t#\n";

                start = 0;
                end = str.find(" ", start);
                username = str.substr(start, end - start);
                cout << "# Username: " << username;

                start = end + 1;
                end = str.find(" ", start);
                password = str.substr(start, end - start);
                cout << "\t\t\t\t#\n# Password: " << password;
                cout << "\t\t\t\t#\n#\t\t\t\t\t\t#\n";
            }
        }
        else
        {
            cout << "#[ERROR] FAILED TO OPEN FILE\t\t#\n";
        }

        read.close();
        cout << "#\t\t\t\t\t\t#\n";
        cout << "#################################################\n";
        system("pause");
    }

    void deleteUser()
    {
        int choice;
        showUser();

        cout << "\nEnter the Seller Listed No to delete : ";
        cin >> choice;

        //--------------to store the data first in temporary file----------------------

        write.open("temp.txt", ios::out);

        read.open("seller.txt");

        while (getline(read, str1))
        {
            ++lineNumber;

            if (lineNumber == choice)
            {
                continue;
            }

            write << str1 << "\n";
        }

        read.close();

        write.close();

        //---------------to update the original file------------------

        write.open("seller.txt", ios::out);

        read.open("temp.txt");

        while (getline(read, str1))
        {
            write << str1 << "\n";
        }

        read.close();

        write.close();

        cout << "\n\t\t\tSeller deleted Successfully...\n";
        system("pause");
    }

    void addUser()
    {
        str = login_newAccount();

        write.open("seller.txt", ios::app);

        if (write.is_open())
        {
            write << str << endl;
        }
        else
        {
            cout << "[ERROR] FAILED TO OPEN FILE";
        }

        write.close();

        cout << "\n\t\t\tAccount Created Successfully...\n";
        system("pause");
    }

    void Menu()
    {
        int choice;
        system("cls");
        cout << "#################################\n";
        cout << "#\t\t\t\t#\n";
        cout << "# What do you want to Sell      #\n";
        cout << "# 1. Plot \t\t\t#\n";
        cout << "# 2. House\t\t\t#\n";
        cout << "# 3. Flat \t\t\t#\n";
        cout << "# 4. Shop \t\t\t#\n";
        cout << "#\t\t\t\t#\n";
        cout << "#################################\n";
        cout << "Enter your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            p->addProperty();
            break;

        case 2:
            h->addProperty();
            break;

        case 3:
            f->addProperty();
            break;

        case 4:
            s->addProperty();
            break;
        }
    }

    void checkIfUser()
    {
        int choice;
        system("cls");
        cout << "#################################\n";
        cout << "#\t\t\t\t#\n";
        cout << "# 1. Already have Account\t#\n";
        cout << "# 2. Create new Account\t\t#\n";
        cout << "# 0. Exit From Here\t\t#\n";
        cout << "#\t\t\t\t#\n";
        cout << "#################################\n";
        system("pause");
        cout << "Enter your choice\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            checkUser();
            break;

        case 2:
            addUser();
            checkUser();
            break;

        case 0:
            break;
        }
    }

    ~Seller()
    {
    }

private:
};

//-------------------Buyer-----------------------------------------

class Buyer : public Person
{
public:
    Buyer()
    {
    }

    void checkUser()
    {
        int repeat = 0;

        login();

        read.open("buyer.txt", ios::in);

        if (read.is_open())
        {
            while (getline(read, str))
            {
                int start, end;

                start = 0;
                end = str.find(" ", start);
                actualUser = str.substr(start, end - start);
                start = end + 1;
                end = str.find(" ", start);
                actualPassword = str.substr(start, end - start);
                if (actualUser == username && actualPassword == password)
                {
                    repeat++;
                }
            }
        }
        else
        {
            cout << "[ERROR] FAILED TO OPEN FILE\n";
        }
        read.close();

        if (repeat > 0)
        {
            Menu();
        }
        else
        {
            cout << "Username or Password Wrong!...\n";
            system("pause");
            checkUser();
        }
    }

    void showUser()
    {
        int count = 0;

        system("cls");
        cout << "##################### Buyers ####################\n";
        cout << "#\t\t\t\t\t\t#\n";
        read.open("buyer.txt", ios::in);

        if (read.is_open())
        {
            while (getline(read, str))
            {
                int start, end;

                cout << "#\t\t Buyer No : " << ++count << "\t\t\t#\n";

                start = 0;
                end = str.find(" ", start);
                username = str.substr(start, end - start);
                cout << "# Username: " << username;

                start = end + 1;
                end = str.find(" ", start);
                password = str.substr(start, end - start);
                cout << "\t\t\t\t#\n# Password: " << password;
                cout << "\t\t\t\t#\n#\t\t\t\t\t\t#\n";
            }
        }
        else
        {
            cout << "#[ERROR] FAILED TO OPEN FILE\t\t#\n";
        }

        read.close();
        cout << "#\t\t\t\t\t\t#\n";
        cout << "#################################################\n";
        system("pause");
    }

    void deleteUser()
    {
        int choice;
        showUser();

        cout << "\nEnter the Buyer Listed No to delete : ";
        cin >> choice;

        //--------------to store the data first in temporary file----------------------

        write.open("temp.txt", ios::out);

        read.open("buyer.txt");

        while (getline(read, str1))
        {
            ++lineNumber;

            if (lineNumber == choice)
            {
                continue;
            }

            write << str1 << "\n";
        }

        read.close();

        write.close();

        //---------------to update the original file------------------

        write.open("buyer.txt", ios::out);

        read.open("temp.txt");

        while (getline(read, str1))
        {
            write << str1 << "\n";
        }

        read.close();

        write.close();

        cout << "\n\t\t\tBuyer Deleted Successfully...\n";
        system("pause");
    }

    void addUser()
    {
        str = login_newAccount();

        write.open("buyer.txt", ios::app);

        if (write.is_open())
        {
            write << str << endl;
        }
        else
        {
            cout << "[ERROR] FAILED TO OPEN FILE";
        }

        write.close();

        cout << "\n\t\t\tAccount Created Successfully...\n";
        system("pause");
    }

    void Menu()
    {
        int choice;
        do
        {
            system("cls");
            cout << "#################################\n";
            cout << "#\t\t\t\t#\n";
            cout << "# What do you want to Buy       #\n";
            cout << "# 1. Plot \t\t\t#\n";
            cout << "# 2. House\t\t\t#\n";
            cout << "# 3. Flat \t\t\t#\n";
            cout << "# 4. Shop \t\t\t#\n";
            cout << "#\t\t\t\t#\n";
            cout << "#################################\n";
            cout << "Enter your Choice : ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                p->showProperty();
                break;

            case 2:
                h->showProperty();
                break;

            case 3:
                f->showProperty();
                break;

            case 4:
                s->showProperty();
                break;
            }
        } while (choice != 0);
    }

    void checkIfUser()
    {
        system("cls");
        cout << "#################################\n";
        cout << "#\t\t\t\t#\n";
        cout << "# 1. Already have Account\t#\n";
        cout << "# 2. Create new Account\t\t#\n";
        cout << "# 0. Exit From Here\t\t#\n";
        cout << "#\t\t\t\t#\n";
        cout << "#################################\n";

        cout << "Enter your choice\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            checkUser();
            break;

        case 2:
            addUser();
            checkUser();
            break;

        case 0:
            break;
        }
    }

    ~Buyer()
    {
    }

private:
};

//-------------------admin-----------------------------------------

class Admin : public Person
{
public:
    Admin()
    {
        buy = new Buyer();
        sel = new Seller();
    }

    void showUser()
    {
        system("cls");
        cout << "#########################################\n";
        cout << "#\t\t\t\t\t#\n";
        cout << "#\tWhat do you want to Dispaly.\t#\n";
        cout << "# 1. Dispaly Sellers\t\t\t#\n";
        cout << "# 2. Dispaly Buyers\t\t\t#\n";
        cout << "#\t\t\t\t\t#\n";
        cout << "#########################################\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            sel->showUser();
            break;

        case 2:
            buy->showUser();
            break;
        }
    }

    void deleteUser()
    {
        system("cls");
        cout << "#########################################\n";
        cout << "#\t\t\t\t\t#\n";
        cout << "#\tWhat do you want to Delete.\t#\n";
        cout << "# 1. Delete Seller\t\t\t#\n";
        cout << "# 2. Delete Buyer\t\t\t#\n";
        cout << "#\t\t\t\t\t#\n";
        cout << "#########################################\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            sel->deleteUser();
            break;

        case 2:
            buy->deleteUser();
            break;
        }
    }

    void Menu()
    {
        int choice;
        do
        {
            system("cls");
            cout << "################## Welcome " << actualUser << " ###################\n";
            cout << "#   \t\t\t\t\t\t\t#\n";
            cout << "#\t\t What do you want to do? \t\t#\n";
            cout << "# 1. Display Users \t\t\t\t\t#\n";
            cout << "# 2. Delete Users \t\t\t\t\t#\n";
            cout << "# 3. Display Properties \t\t\t\t#\n";
            cout << "# 4. Delete Properties \t\t\t\t\t#\n";
            cout << "# 0. Exit from here  \t\t\t\t\t#\n";
            cout << "#   \t\t\t\t\t\t\t#\n";
            cout << "#########################################################\n\n";
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                showUser();
                break;

            case 2:
                deleteUser();
                break;

            case 3:
                system("cls");
                cout << "#################################################\n";
                cout << "#\t\t\t\t\t\t#\n";
                cout << "#  Which property listing you want to dispaly   #\n";
                cout << "#\t\t\t\t\t\t#\n";
                cout << "# 1. Plot  \t\t\t\t\t#\n";
                cout << "# 2. House \t\t\t\t\t#\n";
                cout << "# 3. Flat  \t\t\t\t\t#\n";
                cout << "# 4. Shop  \t\t\t\t\t#\n";
                cout << "#\t\t\t\t\t\t#\n";
                cout << "#################################################\n\n";
                cout << "Enter Your Choice : ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    p->showProperty();
                    break;

                case 2:
                    h->showProperty();
                    break;

                case 3:
                    f->showProperty();
                    break;

                case 4:
                    s->showProperty();
                    break;
                }
                break;

            case 4:
                system("cls");
                cout << "#################################################\n";
                cout << "#\t\t\t\t\t\t#\n";
                cout << "#  Which property listing you want to delete   #\n";
                cout << "#\t\t\t\t\t\t#\n";
                cout << "# 1. Plot  \t\t\t\t\t#\n";
                cout << "# 2. House \t\t\t\t\t#\n";
                cout << "# 3. Flat  \t\t\t\t\t#\n";
                cout << "# 4. Shop  \t\t\t\t\t#\n";
                cout << "#\t\t\t\t\t\t#\n";
                cout << "#################################################\n\n";
                cout << "Enter Your Choice : ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    p->deleteProperty();
                    break;

                case 2:
                    h->deleteProperty();
                    break;

                case 3:
                    f->deleteProperty();
                    break;

                case 4:
                    s->deleteProperty();
                    break;
                }
                break;
            }
        } while (choice != 0);
    }

    void checkUser()
    {
        int repeat = 0;

        login();

        read.open("admin.txt", ios::in);

        if (read.is_open())
        {
            while (getline(read, str))
            {
                int start, end;

                start = 0;
                end = str.find(" ", start);
                actualUser = str.substr(start, end - start);
                start = end + 1;
                end = str.find(" ", start);
                actualPassword = str.substr(start, end - start);
                if (actualUser == username && actualPassword == password)
                {
                    repeat++;
                }
            }
        }
        else
        {
            cout << "[ERROR] FAILED TO OPEN FILE\n";
        }
        read.close();

        if (repeat > 0)
        {
            Menu();
        }
        else
        {
            cout << "Username or Password Wrong!...\n";
            system("pause");
        }
    }

    void addUser()
    {
    }

    void checkIfUser()
    {
    }

    ~Admin()
    {
        delete buy;
        delete sel;
    }

protected:
    Buyer *buy;
    Seller *sel;
};

//-------------------ProppertyManagemnetSystem-----------------------------------------

class PropertyManagementSystem
{
public:
    PropertyManagementSystem()
    {
        admin1 = new Admin();
        seller1 = new Seller();
        buyer1 = new Buyer();
    }

    void Menu()
    {
        int choice;
        do
        {
            system("cls");

            cout << "#########################################################################\n";
            cout << "#\t\t\t\t\t\t\t\t\t#\n#\t\t\t\t\t\t\t\t\t#\n";
            cout << "#\t\t\tProperty Management System\t\t\t#" << endl;
            cout << "#\t\t1. Admin\t\t\t\t\t\t#" << endl;
            cout << "#\t\t2. Buyer\t\t\t\t\t\t#" << endl;
            cout << "#\t\t3. Seller\t\t\t\t\t\t#" << endl;
            cout << "#\t\t0. Exit\t\t\t\t\t\t\t#" << endl;
            cout << "#\t\t\t\t\t\t\t\t\t#\n#\t\t\t\t\t\t\t\t\t#\n";
            cout << "#########################################################################" << endl;
            cout << "\n\n Your Choice : ";

            cin >> choice;
            switch (choice)
            {
            case 1:
                admin1->checkUser();
                break;

            case 2:
                buyer1->checkIfUser();
                break;

            case 3:
                seller1->checkIfUser();
                break;
            }

        } while (choice != 0);
    }

    ~PropertyManagementSystem()
    {
        delete admin1;
        delete seller1;
        delete buyer1;
    }

private:
    Admin *admin1;
    Seller *seller1;
    Buyer *buyer1;
};

//----------------------main--------------------------
int main()
{
    PropertyManagementSystem pms;
    pms.Menu();
}