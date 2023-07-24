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
            cout << arr[top--] << "\n";
        }
    }
    // for checking the value on the top of the stack
    void peak()
    {
        if (!is_Empty())
        {
            cout << "#####  Stack is Empty  #####\n";
        }
        else
        {
            cout << arr[top] << "\n";
        }
    }

    void sizeOfStack()
    {
        cout << (top + 1) << " values in stack.\n";
    }
};

template <typename Q>
class Queue
{

    Stack<Q> mainStack;
    Stack<Q> tempStack;

    int front, rear;
    int size;

public:
    Queue(int size) : mainStack(size), tempStack(size)
    {
        this->size = size;
    }

    bool is_Empty()
    {
        if (mainStack.is_Empty())
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

    void Enqueue()
    {
        if (is_Full())
        {
            cout << "#####  Queue Overflow  #####\n";
        }
        else
        {
            if (front == -1 && rear == -1)
            {
                front = 0;
            }
            cout << "Enter Element : ";
            cin >> queue[++rear];
            cout << queue[rear] << "  Enqueued into Queue...\n";
        }
    }

    // for adding any value to the queue
    void Dequeue()
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }

        if (!is_Empty())
        {
            cout << "#####  Queue Underflow  #####\n";
        }
        else
        {
            cout << queue[front++] << " Dequed from Queue\n";
        }
    }

    // for checking the front value of the queue
    void peak()
    {
        if (!is_Empty())
        {
            cout << "#####  Queue is Empty  #####\n";
        }
        else
        {
            cout << queue[front] << " value at front of Queue\n";
        }
    }

    void Size()
    {
        if (front == -1 && rear == -1)
        {
            cout << "0 Elements Present in the Queue...\n";
        }
        else
        {
            cout << (rear - (front - 1)) << " Elements Present in the Queue...\n";
        }
    }
};

int main()
{
    Stack<int> s(5);

    s.push(3);
    s.push(4);
    s.push(5);

    s.pop();
    s.pop();
    s.pop();
}