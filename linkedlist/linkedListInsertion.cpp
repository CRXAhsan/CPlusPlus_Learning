#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

private:
};

class linkedList
{
public:
    Node *head;
    linkedList()
    {
        head = NULL;
    }

    void insertNodeAtBegin(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        cout << "Node Inserted At Begin Successfully...\n";
    }

    void insertNodeAfterGivenPosition(int pos, int data)
    {
        int currentPos = 1;
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
        }
        else if (pos <= 1)
        {
            insertNodeAtBegin(data);
        }
        else
        {
            Node *temp = head;

            while (currentPos < (pos - 1) && temp->next != NULL)
            {
                temp = temp->next;
                currentPos += 1;
            }
            if (currentPos <= pos)
            {
                newNode->next = temp->next;
                temp->next = newNode;
                cout << data << " insert at " << pos << " succesfully\n";
            }
            else
            {
                temp->next = newNode;
                cout << "add at last of linked list...\n";
            }
        }

        cout << "Node Inserted At Given Position Successfully...\n";
    }

    void insertNodeAtEnd(int data)
    {
        Node *newNode = new Node(data);
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

            cout << "Node Inserted At End Successfully...\n";
        }
    }

    void printLinkedList()
    {
        if (head == NULL)
        {
            cout << "Linked List Is Empty...\n";
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout<<"\n";
        }
    }

private:
};

int main()
{
    int choice, data, pos, update;

    linkedList list;
    do
    {
        system("pause");
        system("cls");

        cout << "1.  Add at begin.\n";
        cout << "2.  Add at end.\n";
        cout << "3.  Add at random.\n";
        cout << "4.  Print The Whole Linked List.\n";
        cout << "0.  for exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data : ";
            cin >> data;
            list.insertNodeAtBegin(data);
            break;

        case 2:
            cout << "Enter data : ";
            cin >> data;
            list.insertNodeAtEnd(data);
            break;

        case 3:
            cout << "Enter position on which you have to enter data : ";
            cin >> pos;
            cout << "Enter data : ";
            cin >> data;
            list.insertNodeAfterGivenPosition(pos, data);
            break;

        case 4:
            list.printLinkedList();
            break;
        }
    } while (choice != 0);
}