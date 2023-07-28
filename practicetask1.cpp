// Write an application that creates objects of each of the three classes
// Suppose the National Bank decides that every account type must have some monthly fees.
// Therefore, a deductFees() method should be added to the Account class: public class Account
// { public void deductFees() { . . . } . . . } But what should this method do? Of course, we could
// have the method do nothing. But then a programmer implementing a new subclass might simply forget to
// implement the deductFees method, and the new account would inherit the do-nothing method of the superclass.
// Also Bank does not open any generalize Account. So, class Account should not be instantiated.
// Implement a better way to do so: That forces the implementers of subclasses to specify concrete
// implementations of this method. (Of course, some subclasses might decide to implement a do-nothing method,
// but then that is their choice—not a silently inherited default.)
// Design a class Account with Account number, Account title and status (Active/ Closed) and methods
// closeAccount() and Display().
// Design it’s subclasses Current Account and Saving Account with balance and methods deductfee(), Saving
// Account also has profit. For Current Account 500 Rs. are deducted from user account if the balance is
// greater than 15000. For Saving Account 1% of Profit is deducted from balance of the user. If the profit is
// greater than 3000.
// Test the  class by creating the objects  both types of account.

#include <iostream>
using namespace std;

class account
{
protected:
    int accountNo;
    string accountTitle;
    bool status;
    int balance;
    int profit;

public:
    virtual void deductFees() = 0;

    void setAccountNo(int accountNo)
    {
        this->accountNo = accountNo;
    }

    void setAccountTitle(string accountTitle)
    {
        this->accountTitle = accountTitle;
    }

    void setAccountStatus(bool status)
    {
        if (status == 1)
        {
            this->status = "active";
        }

        else
        {
            this->status = "closed";
        }
    }

    void closeAccount()
    {
        cout << "your account has been deleted. " << endl;
    }

    void display()
    {
        cout << "Account no     : " << accountNo << endl;
        cout << "Account Title  : " << accountTitle << endl;
        cout << "Account Status : " << status << endl;
    }
};

class currentAccount : public account
{
public:
    void deductFees(int balance)
    {
        if (balance > 15000)
        {
            balance = balance - 500;
        }
    }

    void display()
    {
        cout << "Account Deduction Fees : " << balance << endl;
    }
};

class savingAccount : public account
{
public:
    void deductFees(int balance)
    {
        if (balance > 3000)
        {
            balance = balance - 1 % ;
        }
    }
    void display()
    {
        cout << "Account Deduction Fees : " << balance << endl;
    }
};

int main()
{
    currentAccount c1;

    c1.setAccountNo(1234);
    c1.setAccountTitle("ahsan");
    c1.setAccountStatus(1);
    c1.display();
    c1.deductFees(15000);
}