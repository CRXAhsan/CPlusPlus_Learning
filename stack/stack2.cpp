#include<iostream>
using namespace std;

template <typename T> 
class Stack
{
    private:
        int size;
        int top;
        T* arr;
        
    public:
        Stack(int size)
        {
            this->size=size;
            // dynamically allocate the memory so that we can make user defined array stack
            arr = new T[size]; 
            top=-1;
        }

        ~Stack()
        {
            //free the memory which we use for making our stack
            delete[] arr;
        }

        bool is_Empty()
        {
            if (top < 0 )
            {
                return false;
            }
            else
            {
                return true;
            } 
        }

        bool is_Full()
        {
            if (top < size)
            {

                return true;
            }
            else
            {
                return false;
            } 
        }

        void push(T a)
        {
            if (!is_Full())
            {
                cout<<"#####  Stack Overflow  #####\n";
            }
            else
            {
                arr[++top] = a ;
                cout<<arr[top]<<"  Pushed into Stack\n";
            }
        }

        // for adding any value to the stack
        void pop()
        {
            if (!is_Empty())
            {
                cout<<"#####  Stack Underflow  #####\n";
            }
            else
            {
                cout<<arr[top--]<<"\n";
            }
        }
        // for checking the value on the top of the stack
        void peak()
        {
            if (!is_Empty())
            {
                cout<<"#####  Stack is Empty  #####\n";
            }
            else
            {
                cout<<arr[top]<<"\n";
            }
        }

        void sizeOfStack()
        {
            cout<<(top+1)<<" values in stack.\n";
        }
};

int main()
{
    Stack <int> stack1(10);
    cout<<"#####  When push data  #####\n";
    stack1.push(32);
    stack1.push(55);
    stack1.push(12);
    stack1.push(49);
    stack1.sizeOfStack();

    cout<<"#####  when Pop data  #####\n";
    stack1.pop();
    stack1.sizeOfStack();
    stack1.pop();
    stack1.sizeOfStack();

    cout<<"#####  When peak data  #####\n";
    stack1.peak();

}