// A real-world application where a queue data structure would be useful is in a call center.
// When customers call in, their requests are added to a queue in the order they are received.
// Call center agents then work through the queue, handling each request in turn.
// Without a queue, there would be no guarantee that requests are handled in the order they
// are received, and some requests may be lost or overlooked.
// Implement the above mentioned scenario using queue. Use proper naming conventions for the
// both variable and function declaration.

#include <iostream>
using namespace std;

template <typename T>
class Call_Center
{
    T *Wait_list;
    int front, rear;
    int size;

public:
    Call_Center(int size)
    {
        front = -1;
        rear = -1;
        this->size = size;
        Wait_list = new T[size];
    }

    ~Call_Center()
    {
        // free the memory which we use for making our stack
        delete[] Wait_list;
    }

    bool is_Empty()
    {
        if (rear < size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool is_Full()
    {
        if (rear == (size - 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Recieve_A_Call(string message)
    {
        if (is_Full())
        {
            cout << "\nSorry! There is Some thing Wrong Conveying Message...\n";
            system("pause");
        }
        else
        {
            if (front == -1 && rear == -1)
            {
                front = 0;
            }
            rear++;
            Wait_list[rear] = message;

            cout << "\nYour Message is Conveyed Succssfully...\n";
            system("pause");
        }
    }

    // for attending a call existing in the call list
    void Delete_A_Call()
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }

        if (!is_Empty())
        {
            cout << "#####  Hurrah! No call In Pending  #####\n";
            system("pause");
        }
        else
        {
            cout << front << " Caller Message, \n"
                 << Wait_list[front] << "\n";
            front++;
            system("pause");
        }
    }

    // for checking the pending values in the call list
    void Display_Pending_Calls()
    {
        if (!is_Empty())
        {
            cout << "##### No Pending Calls #####\n";
            system("pause");
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << front << ". Caller : " << Wait_list[i] << "\n";
            }
            system("pause");
        }
    }
};

int main()
{
    int size;
    int choice;
    string message;

    cout << "How many calls you want to attend in a day...\n";
    cout << "Enter No.Of Calls : ";
    cin >> size;

    Call_Center<string> Booth_1(size);

    do
    {
        system("cls");
        cout << "############# Welcome To Apna Call Center #############\n";
        cout << "1. Delete A Call \n";
        cout << "2. Display messages in Pending \n";
        cout << "3. Recieve a call\n";
        cout << "0. Exit \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Booth_1.Delete_A_Call();
            break;

        case 2:
            Booth_1.Display_Pending_Calls();
            break;

        case 3:
            cout << "Enter Messasge : ";
            fflush(stdin);
            getline(cin, message);
            Booth_1.Recieve_A_Call(message);
            break;
        }
    } while (choice != 0);
}