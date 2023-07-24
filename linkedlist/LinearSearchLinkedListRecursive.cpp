#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        next = NULL;
    }

    Node(int a)
    {
        this->data = a;
        this->next = NULL;
    }
};

class linkedList
{
public:
    Node *head;

    linkedList()
    {
        head = NULL;
    }

    void insert_at_begin(int a)
    {
        Node *newNode = new Node(a);
        newNode->next = head;
        head = newNode;
        cout << a << " insert at begin succesfully\n";
    }

    void insert_at_end(int a)
    {
        Node *newNode = new Node(a);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << a << " insert at end succesfully\n";
    }
};
    int count=1;

void LinearSearch(Node *temp, int actualData)
{

    if (temp == NULL)
    {
        return;
    }

    else if (temp->data == actualData)
    {
        cout << "Present at Position : " << count << "\n";
    }
    count++;

    LinearSearch(temp->next, actualData);
}

int main()
{
    int choice, data, pos, update;

    linkedList list;

    list.insert_at_begin(11);
    list.insert_at_end(12);
    list.insert_at_end(13);
    list.insert_at_end(12);
    list.insert_at_end(14);
    list.insert_at_end(15);
    list.insert_at_end(12);
    int num;
    cout<<"Enter number to find :";
    cin >>num;
    LinearSearch(list.head, num);
}