#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

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

    void insert_at_begin(int a)
    {
        Node *newNode = new Node(a);
        if (head != NULL)
        {
            head->prev = newNode;
        }
        newNode->next = head;
        head = newNode;
        cout << a << " inserted at the beginning successfully\n";
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
            newNode->prev = temp;
        }
        cout << a << " inserted at the end successfully\n";
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

            while (currentPos < pos && temp->next != NULL)
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
                cout << data << " inserted at position " << pos << " successfully\n";
            }
            else
            {
                temp->next = newNode;
                newNode->prev = temp;
                cout << data << " inserted at the end successfully\n";
            }
        }
    }

    void print_linked_list()
    {
        Node *temp = head;

        if (head == NULL)
        {
            cout << "Linked list is empty\n";
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
            cout << "Linked List is already empty\n";
        }
        else
        {
            Node *temp = head;
            head = head->next;
            if (head != NULL)
            {
                head->prev = NULL;
            }
            delete temp;
        }
    }

    void delete_from_end()
    {
        Node *temp = head;

        if (temp == NULL)
        {
            cout << "Linked List is already empty\n";
        }
        else if (temp->next == NULL)
        {
            head = NULL;
            delete temp;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->prev->next = NULL;
            delete temp;
        }
    }

    void delete_from_specific_position(int pos)
    {
        if (head == NULL)
        {
            cout << "Linked List is already empty\n";
        }
        else if (pos <= 1)
        {
            delete_from_begin();
        }
        else
        {
            int currentPos = 1;
            Node *temp = head;

            while (currentPos < pos && temp != NULL)
            {
                temp = temp->next;
                currentPos += 1;
            }

            if (currentPos == pos && temp != NULL)
            {
                temp->prev->next = temp->next;
                if (temp->next != NULL)
                {
                    temp->next->prev = temp->prev;
                }
                delete temp;
                cout << "Deleted successfully from position " << pos << "\n";
            }
            else
            {
                cout << "This position does not exist in the linked list\n";
            }
        }
    }

    void delete_from_specific_data(int deleteData)
    {
        if (head == NULL)
        {
            cout << "Linked List is already empty\n";
        }
        else
        {
            Node *temp = head;

            while (temp != NULL)
            {
                if (temp->data == deleteData)
                {
                    if (temp == head)
                    {
                        head = temp->next;
                        if (head != NULL)
                        {
                            head->prev = NULL;
                        }
                    }
                    else
                    {
                        temp->prev->next = temp->next;
                        if (temp->next != NULL)
                        {
                            temp->next->prev = temp->prev;
                        }
                    }
                    Node *toDelete = temp;
                    temp = temp->next;
                    delete toDelete;
                }
                else
                {
                    temp = temp->next;
                }
            }
        }
    }

    void update_from_specific_data(int actualData, int replaceData)
    {
        Node *temp = head;
        int count = 0;

        while (temp != NULL)
        {
            if (temp->data == actualData)
            {
                temp->data = replaceData;
                count++;
            }
            temp = temp->next;
        }

        if (count == 0)
        {
            cout << "No occurrences of " << actualData << " found in the linked list\n";
        }
        else
        {
            cout << "Updated " << count << " occurrences of " << actualData << " with " << replaceData << "\n";
        }
    }

    void update_from_specific_position(int pos, int replaceData)
    {
        int currentPos = 1;
        Node *temp = head;

        if (temp == NULL)
        {
            cout << "Linked List is empty\n";
        }
        else
        {
            while (currentPos < pos && temp != NULL)
            {
                temp = temp->next;
                currentPos += 1;
            }
            if (currentPos == pos && temp != NULL)
            {
                temp->data = replaceData;
                cout << "Updated position " << pos << " with " << replaceData << "\n";
            }
            else
            {
                cout << "Invalid position\n";
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
        cout << "Number of elements present in the linked list: " << count << "\n";
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

        cout << "1. Add at the beginning\n";
        cout << "2. Add at the end\n";
        cout << "3. Add at a specific position\n";
        cout << "4. Print the whole linked list\n";
        cout << "5. Delete from the beginning\n";
        cout << "6. Delete from the end\n";
        cout << "7. Delete from a specific position\n";
        cout << "8. Delete a specific data\n";
        cout << "9. Update a specific position\n";
        cout << "10. Update a specific data\n";
        cout << "11. Size of the linked list\n";
        cout << "0. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            list.insert_at_begin(data);
            break;

        case 2:
            cout << "Enter data: ";
            cin >> data;
            list.insert_at_end(data);
            break;

        case 3:
            cout << "Enter position where you want to insert data: ";
            cin >> pos;
            cout << "Enter data: ";
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
            cout << "Enter the position you want to delete: ";
            cin >> pos;
            list.delete_from_specific_position(pos);
            break;

        case 8:
            cout << "Enter the data you want to delete: ";
            cin >> data;
            list.delete_from_specific_data(data);
            break;

        case 9:
            cout << "Enter the position you want to update: ";
            cin >> pos;
            cout << "Enter the data you want to update: ";
            cin >> data;
            list.update_from_specific_position(pos, data);
            break;

        case 10:
            cout << "Enter the data you want to replace: ";
            cin >> data;
            cout << "Enter the updated data: ";
            cin >> update;
            list.update_from_specific_data(data, update);
            break;

        case 11:
            list.size_of_linkedList();
            break;
        }
    } while (choice != 0);

    return 0;
}
