#include<iostream>
using namespace std;

class Stack{
    private:
        int size;
        int top;
        int* arr;
        
    public:
        Stack(int size)
        {
            this->size=size;
            // dynamically allocate the memory so that we can make user defined array stack
            arr = new int[size]; 
            top=-1;
        }

        ~Stack()
        {
            //free the memory which we use for making our stack
            delete[] arr;
        }
        // for adding any value to the stack
        void push()
        {
            if (top >= (size-1))
            {
                cout<<"Stack Overflow\n";
            }
            else
            {
                cin>>arr[++top] ;
                cout<<arr[top]<<"Pushed into Stack\n";
            }
        }

        // for adding any value to the stack
        void pop()
        {
            if (top < 0)
            {
                cout<<"Stack Underflow\n";
            }
            else
            {
                cout<<arr[top--];
            }
        }
        // for checking the value on the top of the stack
        void peak()
        {
            if (top < 0)
            {
                cout<<"Stack is Empty\n";
            }
            else
            {
                cout<<arr[top];
            }
            
        }

        bool isEmpty()
        {
            if (top < 0)
            {
                /* code */
            }
            
            return (top < 0 || top < size-1);
        }

        bool isFull()
        {
            return (top );
        }

};

int main()
{
    int choice;
    Stack s(10);

    do
    {
        system("cls");
        cout<<"1. push value\n";
        cout<<"2. pop value\n";
        cout<<"3. peek value\n";
        cout<<"0.  exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            s.push();
            break;
        
        case 2:
            s.pop();
            break;

        case 3:
            s.peak();
            break;
        }
    } 
    while (choice != 0);
    
}