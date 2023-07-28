#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
    int size;
    int top;
    T *arr;

public:
    Stack(int size)
    {
        this->size = size;
        // dynamically allocate the memory so that we can make user defined array stack
        arr = new T[size];
        top = -1;
    }

    ~Stack()
    {
        // free the memory which we use for making our stack
        delete[] arr;
    }

    bool is_Empty()
    {
        if (top < 0)
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
            cout << "#####  Stack Overflow  #####\n";
        }
        else
        {
            arr[++top] = a;
            cout << arr[top] << "  Pushed into Stack\n";
        }
    }

    // for adding any value to the stack
    void pop()
    {
        if (!is_Empty())
        {
            cout << "#####  Stack Underflow  #####\n";
        }
        else
        {
            cout << arr[top] << "  Popped from Stack\n";
            cout << arr[top--] << "\n";
        }
    }
    // for checking the value on the top of the stack
    T peak()
    {
        if (!is_Empty())
        {
            cout << "#####  Stack is Empty  #####\n";
        }
        else
        {
            return arr[top];
        }
    }

    void sizeOfStack()
    {
        cout << (top + 1) << " values in stack.\n";
    }
};

int main()
{
    string variable_1;
    int n;
    int count = 0;

    cout << "Enter String : ";
    cin >> variable_1;

    n = variable_1.length();

    Stack<char> stack1(n);

    for (int i = 0; i < n; i++)
    {
        stack1.push(variable_1[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (stack1.peak() == variable_1[i])
        {
            stack1.pop();
            count++;
        }
    }
    cout << "####  Conditions For Palindrome ####\n\n";
    if (count == n)
    {
        cout << "Palindrome\n\n";
    }
    else
    {
        cout << "Not Palidrome\n\n";
    }
}