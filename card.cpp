#include <iostream>
#include <ctime>
using namespace std;

class Student
{
private:
    string name, id, semester;

public:
    void setStudent()
    {
        cout << "Enter Your Name.\n";
        cin >> name;
        cout << "Enter Your ID.\n";
        cin >> id;
        cout << "Enter Your Semester.\n";
        cin >> semester;
    }
    void getStudent()
    {
        cout << "Name     : " << name << "\n";
        cout << "ID       : " << id << "\n";
        cout << "Semester : " << semester << "\n";
    }
};
class FlexRupeesAccount;
class MealPlanFunds;
class TransferMealPlanFunds;

class SahulatCard
{
private:
    int amount;
    int choice;

public:
    SahulatCard()
    {
        FlexRupeesAccount *f1 = new FlexRupeesAccount;
        MealPlanFunds *m1 = new MealPlanFunds;
        TransferMealPlanFunds *t1 = new TransferMealPlanFunds;
    }

    void sahulatMenu(FlexRupeesAccount *f1, MealPlanFunds *m1, TransferMealPlanFunds *t1)
    {
        cout << "1. Deposit Cash.\n";
        cout << "2. Chech Account Balance.\n";
        cout << "3. Purchase \n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "1. Add cash to flex. \n";
            cout << "2. Add cash to meal plan. \n";
            cin >> choice;
            switch (choice)
            {
            case 1:
                f1->flexMenu();
                break;

            case 2:
                m1->deposit();
                break;
            }
            break;

        case 2:
            cout << "Which Account Balance You want to Check.\n";
            cout << "1. Flex Ruppes Account\n";
            cout << "2. Meal Plan Fund Account\n";
            cout << "3. Transfer Meal Plan Fund Account\n";
            cin >> choice;
            switch (choice)
            {
            case 1:
                f1->checkBalance();
                break;

            case 2:
                m1->checkBalance();
                break;
            case 3:
                t1->checkBalance();
                break;
            }
            break;

        case 3:
            cout << "What do you want to purchase.\n";
            cout << "1. Biryani.\n";
            cout << "2. Pulao. \n";
            cin >> choice;
            switch (choice)
            {
            case 1:

                break;

            default:
                break;
            }
        }
    }
};

class Account
{
protected:
    int money;
    int balance;
    int choice;
    int amount;

public:
    void deposit()
    {
    }
    void checkBalance(){};
    void purchase(){};
};

class FlexRupeesAccount : public Account
{
private:
    int balance;

public:
    void flexMenu()
    {
        cout << "Enter amount to add.\n";
        cin >> money;
        deposit(money);
    }
    void deposit(int money)
    {
        balance = balance + money;
    }
    void checkBalance()
    {
        cout << "Total Balance in Flex Ruppes Account is : " << balance << "\n";
    }
    void purchase()
    {
        cout << "1. Meal Plan [Available...] Rs:15,000 \n";
        cout << "2. PhotoCopying [Coming Soon...]\n";
        cout << "3. Libraries [Coming Soon...]\n";
        cin >> choice;
        switch (choice)
        {
        case 1:

            break;

        default:
            break;
        }
    }
};

class MealPlanFunds : public Account
{
private:
    int meal_funds, money_trans, choice;

public:
    void getMealFunds(int meal_funds)
    {
        this->meal_funds = meal_funds;
    }
    void deposit()
    {
        cout << "How much Money you want to transfer in meal plan fund\n";
        cin >> money_trans;
        if (money_trans > balance)
        {
            cout << "You dont have enough money in your flex ruppes account\n";
        }
        else
        {
            meal_funds = money_trans;
            balance = balance - money_trans;
        }
    }
    void mealMenu()
    {
        cout << "<--------All Meal Plans-------->\n";
        cout << "1. Biryani,       120 rs\n";
        cout << "2. Zinger,        230 rs\n";
        cout << "3. Daal & Chawal, 100 rs\n";
        cout << "4. Pulao,         130 rs\n";
        cout << "5. Nihari,        150 rs\n";
        cin >> choice;
    }
    void purchase()
    {
        mealMenu();

        switch (choice)
        {
        case 1:
            if (meal_funds > 120)
            {
                cout << "Successfully purchased...\n";
                meal_funds = meal_funds - 120;
            }
            else
            {
                cout << "you dont have enough money in meal plan funds\n";
            }
            break;

        case 2:
            if (meal_funds > 230)
            {
                cout << "Successfully purchased...\n";
                meal_funds = meal_funds - 230;
            }
            else
            {
                cout << "you dont have enough money in meal plan funds\n";
            }
            break;
        case 3:
            if (meal_funds > 100)
            {
                cout << "Successfully purchased...\n";
                meal_funds = meal_funds - 100;
            }
            else
            {
                cout << "you dont have enough money in meal plan funds\n";
            }
            break;
        case 4:
            if (meal_funds > 130)
            {
                cout << "Successfully purchased...\n";
                meal_funds = meal_funds - 130;
            }
            else
            {
                cout << "you dont have enough money in meal plan funds\n";
            }
            break;
        case 5:
            if (meal_funds > 150)
            {
                cout << "Successfully purchased...\n";
                meal_funds = meal_funds - 150;
            }
            else
            {
                cout << "you dont have enough money in meal plan funds\n";
            }
            break;
        default:
            cout << "You have entered wrong choice\n";
            break;
        }
    }
    void checkBalance()
    {
        cout << "Total Balance in meal plan fund Account is : " << meal_funds << "\n";
    }
};

class TransferMealPlanFunds : public Account
{
private:
    int trans_fund;

public:
    void deposit(Account &A1)
    {
        this->trans_fund;
    }
    void purchase()
    {
    }
    void checkBalance()
    {
    }
};

class MealPlan : public MealPlanFunds, public TransferMealPlanFunds
{
private:
    int discount;
    Money *money1;

public:
    MealPlan()
    {
        money1->initial();
    }
};

class Money
{
private:
    int initials;
    int balance;
    int amount;

public:
    Money()
    {
    }
    void initial()
    {
        this->initials = initials;
    }
};

struct tm
{
    int tm_sec;   // seconds of minutes from 0 to 61
    int tm_min;   // minutes of hour from 0 to 59
    int tm_hour;  // hours of day from 0 to 24
    int tm_mday;  // day of month from 1 to 31
    int tm_mon;   // month of year from 0 to 11
    int tm_year;  // year since 1900
    int tm_wday;  // days since sunday
    int tm_yday;  // days since January 1st
    int tm_isdst; // hours of daylight savings time
};

int main()
{
    Student s1;
    s1.setStudent();
    s1.getStudent();

    FlexRupeesAccount f1;
    MealPlanFunds m1;
    TransferMealPlanFunds t1;

    SahulatCard SC1;
    SC1.sahulatMenu(&f1, &m1, &t1);
}