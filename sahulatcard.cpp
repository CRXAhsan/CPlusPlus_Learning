#include<iostream>
using namespace std;

class Student
{
    private:
        string name, id, semester;

    public:
    Student()
    {
        
    }
        void studentDetails()
        {
            cout<<"Enter Name : ";
            cin >>name;
            cout<<"Enter Id : ";
            cin >>id;
            cout<<"Enter Semester : ";
            cin >>semester;
        }

};

class FlexRuppes 
{
    public:
    int balanceFlex=0;
    FlexRuppes()
    {
        balanceFlex=0;
    }
    void purchase(int amount)
    {
        int formula = (amount * 0.17);
        cout<<"You have make purchased from flex ruppes account\n";
        cout<<"Your Bill : "<<amount<<"\n";
        balanceFlex=balanceFlex-(amount + formula);
        cout<<"After 17% GST the Bill is : "<<amount+formula<<"\n";
        cout<<"Thank You!...\n";
    }

    void deposit(int amount)
    {
        cout<<"You have deposited in flex ruppes account\n";
        cout<<"Before Deposit : "<<balanceFlex<<"\n";
        balanceFlex=balanceFlex+amount;
        cout<<"After Deposit : "<<balanceFlex<<"\n";
    }

    void checkBalance()
    {
        cout<<"Total Balance : "<<balanceFlex<<"\n";
    }
};

class MealPlanFunds  
{
    public:
    int balanceMeal=0 ;
    MealPlanFunds()
    {
        balanceMeal=0;
    }

    void purchase(int amount)
    {
        cout<<"You have make purchased from Meal Plan Funds account\n";
        balanceMeal=balanceMeal-amount;
        cout<<"Your Bill : "<<amount<<"\n";
        cout<<"Thank You!...\n";
    }

    void checkBalance()
    {
        cout<<"Total Balance : "<<balanceMeal<<"\n";
    }
};

class TransferMealPlanFunds  
{
    public:
    int balanceTransfer=0;
    int formula;
    TransferMealPlanFunds()
    {
        balanceTransfer=0;
    }
    void purchase(int amount)
    {   
        int formula = (amount * 0.07);
        cout<<"You have make purchased from Transfer Meal Plan account\n";
        cout<<"Your Bill : "<<amount<<"\n";
        balanceTransfer=balanceTransfer-(amount+formula);
        cout<<"After 10% discount & 17% GST the Bill is : "<<amount+formula<<"\n";
        cout<<"Thank You!...\n";
    }

    void checkBalance()
    {
        cout<<"Total Balance : "<<balanceTransfer<<"\n";
    }
};

class Account
{
    FlexRuppes f1;
    MealPlanFunds m1;
    TransferMealPlanFunds t1;
    
    public:

    void purchase(int amount)
    {
        
        
        if(amount < t1.balanceTransfer)
        {
            t1.purchase(amount);
        }
        else if(amount < m1.balanceMeal)
        {
            m1.purchase(amount);
        }
        else if(amount < f1.balanceFlex)
        {
            f1.purchase(amount);
        }
        else
        {
            cout<<"You dont Have Enough Balance In Your Accounts\n";
        }
    }

    void deposit(int choice, int amount)
    {

        if (choice == 1)
        {
            f1.deposit(amount);
        }
        else if(choice == 2)
        {
            if(f1.balanceFlex > amount)
            {
                cout<<"Transfering funds...\n";
                f1.balanceFlex=f1.balanceFlex - amount;
                m1.balanceMeal=m1.balanceMeal + amount;
                cout<<"Funds transfered successfully...\n";
            }
            else
            {
                cout<<"You dont have enough cash in flex ruppes account\n";
            }
        }
        else if(choice == 3)
        {
            cout<<"Transfering funds...\n";
            t1.balanceTransfer = t1.balanceTransfer + m1.balanceMeal;
            m1.balanceMeal = 0;
            cout<<"Funds transfered successfully...\n";
        }
    }

    void checkBalance()
    {
        int choice;
        cout<<"Which Account Balance you want to check\n";
        cout<<"1. Flex Ruppes Acount\n";
        cout<<"2. Meal Plan Account\n;";
        cout<<"3. Transfer Meal Plan Account\n;";
        cin >>choice;
        if(choice == 1)
        {
            f1.checkBalance();
        }
        else if(choice == 2)
        {
            m1.checkBalance();
        }
        else if(choice == 3)
        {
            t1.checkBalance();
        }
        else
        {
            cout<<"You dont Have Enough Balance In Your Accounts\n";
        }
    }
};

class SahulatCard
{
    private:
    int amount;
    
    Account *a1;
    public:

        void purchase()
        {
            int choice=0;
            cout<<"1. biryani\n";
            cout<<"2. pulao\n";
            
            cin >>choice;
            if(choice == 1)
            {
                amount = 120;
                a1->purchase(amount);
            }
            else if(choice == 2)
            {
                amount = 150;
                a1->purchase(amount);
            }
            else{
                cout<<"you have entered wrong choice\n";
            }
            
        }

        void deposit()
        {
            int choice =0 ;
            int amount =0;
            
            do
            {
            cout<<"Press 1. If you want to add cash to flex ruppes account\n";
            cout<<"Press 2. if you want to transfer money from flex to Meal Plan\n";
            cout<<"Press 3. if your semester is finish, Your funds will be transfered\n";
            cin >>choice;

            if(choice == 1)
            {
                cout<<"Enter amount to deposit\n";
            cin >>amount;
                a1->deposit(choice,amount);
            }
            else if(choice == 2)
            {
                cout<<"Enter amount to deposit\n";
            cin >>amount;
                a1->deposit(choice,amount);
            }
            else if(choice == 3)
            {
                a1->deposit(choice, amount);
            }
            else
            {
                cout<<"you enter wrong choice\n";
            }
            } while (choice >= 1 || choice <=3);
            
        }

        void checkBalance()
        {
            a1->checkBalance();
        }
};

int main()
{
    int choice;
    Student s;
    s.studentDetails();

    SahulatCard Card;

    do
    {
        cout<<"1. Deposit\n";
        cout<<"2. purchase\n";
        cout<<"3. check balance\n";
        cin >>choice;
        switch (choice)
        {
        case 1:
            Card.deposit();
            break;
        case 2:
            Card.purchase();
            break;
        case 3:
            Card.checkBalance();
            break;
        
        }
    } 
    while (choice);
    
    
}