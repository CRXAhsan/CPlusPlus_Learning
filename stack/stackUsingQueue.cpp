#include <iostream>
using namespace std;

template <typename Q>
class Queue
{
    Q *queue;
    int front, rear;
    int size;

public:
    Queue(int size)
    {
        front = -1;
        rear = -1;
        this->size = size;
        queue = new Q[size];
    }

    ~Queue()
    {
        // free the memory which we use for making our stack
        delete[] queue;
    }
    // check that the queue is empty or not
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

    // check that the queue is Full or not
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

    // for adding any value to the queue
    void Enqueue(int a)
    {
        if (is_Full())
        {
            cout << "Full...\n";
        }
        else
        {
            if (front == -1 && rear == -1)
            {
                front = 0;
            }
            rear++;
            queue[rear] = a;
        }
    }

    // for deleting any value to the queue
    Q Dequeue()
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }

        if (!is_Empty())
        {
            cout << "Empty...\n";
        }
        else
        {
            return queue[front++];
        }
    }

    // for checking the front value of the queue
    Q peak()
    {
        if (!is_Empty())
        {
            cout << "Empty...\n";
        }
        else
        {
            return queue[front];
        }
    }
};

template <typename S>
class Stack
{
private:
    int size;
    int top;
    Queue<S> que1;
    Queue<S> que2;
    Queue<S> temp_queue;

public:
    Stack(int size) : que1(size), que2(size), temp_queue(size)
    {
        this->size = size;
    }

    bool is_Empty()
    {
        if (que1.is_Empty() && que2.is_Empty())
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
        if (que1.is_Full() || que2.is_Full())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(S a)
    {
        if (is_Full())
        {
            cout << "#####  Stack Overflow  #####\n";
        }
        else
        {
            que2.Enqueue(a);
            cout << "  Pushed into Stack\n";
            while (!que1.is_Empty())
            {
                S x;
                x = que1.Dequeue();
                que2.Enqueue(x);
            }
            temp_queue = que1;
            que1 = que2;
            que2 = temp_queue;
        }
    }

    // for deleting any value to the stack
    void pop()
    {
        if (!is_Empty())
        {
            cout << "#####  Stack Underflow  #####\n";
        }
        else
        {
            cout << que1.Dequeue() << "\n";
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
            que1.peak();
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