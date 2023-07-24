#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        next = NULL;
        prev = NULL;
    }

    Node(int a)
    {
        this->data = a;
        this->next = NULL;
        this->prev = NULL;
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

    void insert_at_begin(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;

            cout << data << " insert at begin succesfully\n";
        }
    }

    void insert_at_end(int data)
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
            newNode->prev = temp;
        }
        cout << data << " insert at end succesfully\n";
    }

    void insert_at_random_position(int pos, int data)
    {
        Node *newNode = new Node(data);
        int currentPos = 1;

        if (head == NULL)
        {
            head = newNode;
        }
        else if (pos <= 1)
        {
            insert_at_begin(data);
        }
        else
        {
            Node *temp = head;

            while (currentPos != pos && temp->next != NULL)
            {
                temp = temp->next;
                currentPos += 1;
            }
            if (currentPos == pos)
            {
                newNode->next = temp;
                newNode->prev = temp->prev;
                temp->prev->next = newNode;
                temp->prev = newNode;

                cout << data << " insert at " << pos << " succesfully\n";
            }
            else
            {
                insert_at_end(data);
                cout << "add at last of linked list...\n";
            }
        }
    }

    void print_linked_list()
    {
        Node *temp;
        temp = head;

        if (head == NULL)
        {
            cout << "linked list is empty...\n";
        }

        while (temp != NULL)
        {
            cout << temp->data << "\n";
            temp = temp->next;
        }
    }

    void delete_from_begin()
    {
        if (head == NULL)
        {
            cout << "Linked List is Already Empty...\n";
        }
        else
        {
            head = head->next;
            head->prev = NULL;
        }
    }

    void delete_from_end()
    {
        Node *temp = head;

        if (temp == NULL)
        {
            cout << "Linked List is Already Empty...\n";
        }
        else if (temp->next == NULL)
        {
            head = NULL;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
        }
    }

    void delete_from_specific_position(int pos)
    {
        Node *temp = head;
        int currentPos = 1;

        if (temp == NULL)
        {
            cout << "Linked List is Already Empty...\n";
        }

        else if (pos == 1 && temp->next == NULL)
        {
            head = NULL;
        }

        else if (pos == 1)
        {
            delete_from_begin();
        }

        else
        {
            while (currentPos != pos && temp != NULL)
            {
                temp = temp->next;
                currentPos += 1;
            }
            if (currentPos == pos)
            {
                temp->prev->next = temp->next;

                if (temp->next != NULL)
                {
                    temp->next->prev = temp->prev;
                }
                delete temp;
            }
            else
            {
                cout << "This position is not exist in linked list... \n";
            }
        }
    }

    void delete_from_specific_data(int deleteData)
    {
        Node *temp = head;

        if (temp == NULL)
        {
            cout << "Linked List is already empty...\n";
        }
        else
        {
            while (temp != NULL)
            {
                if (temp->data == deleteData)
                {
                    if (temp == head)
                    {
                        delete_from_begin();
                    }
                    else
                    {
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                    }
                }

                temp = temp->next;
            }
        }
    }

    void update_from_specific_data(int actualData, int replaceData)
    {
        Node *temp = head;

        if (temp == NULL)
        {
            cout << "Linked List is Empty...\n";
        }
        else
        {
            while (temp != NULL)
            {
                if (temp->data == actualData)
                {
                    temp->data = replaceData;
                }
                temp = temp->next;
            }
        }
    }

    void update_from_specific_position(int pos, int replaceData)
    {
        int currentPos = 0;

        Node *temp = head;

        if (temp == NULL)
        {
            cout << "Linked List is Empty...\n";
        }
        else
        {
            while (currentPos <= pos && temp != NULL)
            {
                temp = temp->next;
                currentPos += 1;
            }
            if (currentPos == pos)
            {
                temp->data = replaceData;
            }
        }
    }

    void size_of_linkedList()
    {
        int count = 0;
        Node *temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        cout << count << " elments present in the linked list\n";
    }
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
        cout << "5.  Delete From Begin.\n";
        cout << "6.  Delete From End.\n";
        cout << "7.  Delete From Specific Position.\n";
        cout << "8.  Delete From Specific Data.\n";
        cout << "9.  Updata From Specific Position.\n";
        cout << "10. Update From Specific Data.\n";
        cout << "11. for size of linked list\n";
        cout << "0.  for exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data : ";
            cin >> data;
            list.insert_at_begin(data);
            break;

        case 2:
            cout << "Enter data : ";
            cin >> data;
            list.insert_at_end(data);
            break;

        case 3:
            cout << "Enter position on which you have to enter data : ";
            cin >> pos;
            cout << "Enter data : ";
            cin >> data;
            list.insert_at_random_position(pos, data);
            break;

        case 4:
            list.print_linked_list();
            break;

        case 5:
            list.delete_from_begin();
            break;

        case 6:
            list.delete_from_end();
            break;

        case 7:
            cout << "Enter Position you want to delete the list.\n";
            cin >> pos;
            list.delete_from_specific_position(pos);
            break;

        case 8:
            cout << "Enter data you want to delete from linked list.\n";
            cin >> data;
            list.delete_from_specific_data(data);
            break;

        case 9:
            cout << "Enter positon you want to Update. \n";
            cin >> pos;
            cout << "Enter data you want to Update. \n";
            cin >> data;
            list.update_from_specific_position(pos, data);
            break;

        case 10:
            cout << "Enter data which you want to replace\n";
            cin >> data;
            cout << "Enter the updated data.\n";
            cin >> update;
            list.update_from_specific_data(data, update);
            break;

        case 11:
            list.size_of_linkedList();
            break;
        }
    } while (choice != 0);
}