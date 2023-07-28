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
    T pop()
    {
        if (!is_Empty())
        {
            cout << "#####  Stack Underflow  #####\n";
        }
        else
        {
            return arr[top--];
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

int Priority(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string exp)
{
    Stack<char> s1(10);
    string temp;

    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];

        if (c == '(')
        {
            s1.push(c);
        }

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= 0 && c <= 9))
        {
            temp = temp + c;
        }

        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (Priority)
            {
                /* code */
            }

            s1.push(c);
        }

        if (c == ')')
        {
            while (s1.peak() != '(')
            {
                temp = temp + s1.pop();
            }
            s1.pop();
        }
    }

    cout << temp;
}

int main()
{
    string expression;
    cout << "Enter string\n";
    getline(cin, expression);

    expression = "(" + expression + ")";

    infixToPostfix(expression);
}