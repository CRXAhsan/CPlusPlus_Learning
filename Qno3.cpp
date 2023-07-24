#include<iostream>
using namespace std;

template<typename T>
class Queue
{
    T* queue;
    int front, rear;
    int size;

    public:

    Queue(int size)
    {
        front = -1;
        rear = -1;
        this->size=size;
        queue = new T[size];
    }

    ~Queue()
    {
        //free the memory which we use for making our stack
        delete[] queue;
    }

        bool is_Empty()
        {
            if ( rear < size )
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
            if (rear == (size-1))
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
                cout<<"#####  Queue Overflow  #####\n";
            }
            else
            {
                if (front == -1 && rear == -1)
                {
                    front = 0;
                }
                cout<<"Enter Element : ";
                cin>>queue[++rear];
                cout<<queue[rear]<<"  Enqueued into Queue...\n";
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
                cout<<"#####  Queue Underflow  #####\n";
            }
            else
            {
                cout<<queue[front++]<<" Dequed from Queue\n";
            }
        }

        // for checking the front value of the queue
        void peak()
        {
            if (!is_Empty())
            {
                cout<<"#####  Queue is Empty  #####\n";
            }
            else
            {
                cout<<queue[front]<<" value at front of Queue\n";
            }
        }

        void Size()
        {
            cout<<(rear-(front-1))<<" Elements Present in the Queue...\n";
        }
};

int main()
{
    int size;
    int choice;

    cout<<"First of all Declare a Queue...\n";
    cout<<"Enter Size of Queue : ";
    cin >>size;

    Queue<int> que_1(size);

    do
    {
        cout<<"What do you Want to do...\n\n";
        cout<<"1. Enqueue data\n";
        cout<<"2. Dequeue data\n";
        cout<<"3. Peak data\n";
        cout<<"4. How many Elements present in the Queue\n";
        cout<<"0. Exit\n";
        cin >>choice;

        switch (choice)
        {
        case 1:

            que_1.Enqueue();
            break;

        case 2:
            
            que_1.Dequeue();
            break;

        case 3:
            
            que_1.peak();
            break;

        case 4:
            
            que_1.Size();
            break;
        }
        
    } while (choice != 0);
    
}