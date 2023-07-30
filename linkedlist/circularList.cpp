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

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class CircularlinkedList
{
public:
    Node *head;

    CircularlinkedList()
    {
        head = NULL;
    }

    void insert_at_begin(int a)
    {
        Node *temp = head;
        Node *newNode = new Node(a);

        temp =head->next;
        head = newNode;
        newNode = temp;
        
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

    void print_linked_list_Node_of_specific_position(int pos)
    {
        int currntPos = 1;
        Node *temp;
        temp = head;

        if (head == NULL)
        {
            cout << "linked list is empty...\n";
        }

        while (currntPos < pos && temp != NULL)
        {
            temp = temp->next;
            currntPos++;
        }
        cout << temp->data << "\n";
    }

    void print_linked_list_from_specfic_node_to_specific_node(int startPos, int endPos)
    {
        int currntPos = 1;
        Node *temp;
        temp = head;

        if (head == NULL)
        {
            cout << "linked list is empty...\n";
        }

        while (currntPos < startPos && temp != NULL)
        {
            temp = temp->next;
            currntPos++;
        }

        if (currntPos == startPos)
        {
            while (startPos <= endPos && temp != NULL)
            {
                cout << temp->data << "\n";
                temp = temp->next;
                startPos++;
            }
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
        }
    }

    void delete_from_end()
    {
        Node *temp1;
        Node *temp2 = head;

        if (temp2 == NULL)
        {
            cout << "Linked List is Already Empty...\n";
        }
        else if (temp2->next == NULL)
        {
            head = NULL;
        }
        else
        {
            while (temp2->next != NULL)
            {
                temp1 = temp2;
                temp2 = temp2->next;
            }
            temp1->next = NULL;
        }
    }

    void delete_from_specific_position(int pos)
    {
        Node *temp1 = NULL;
        Node *temp2 = head;
        int currentPos = 1;

        if (temp2 == NULL)
        {
            cout << "Linked List is Already Empty...\n";
        }

        else if (pos == 1 && temp2->next == NULL)
        {
            head = NULL;
        }

        else if (pos == 1)
        {
            delete_from_begin();
        }

        else
        {
            while (currentPos <= (pos - 1) && temp2 != NULL)
            {
                temp1 = temp2;
                temp2 = temp2->next;
                currentPos += 1;
            }
            if (currentPos == pos)
            {
                temp1->next = temp2->next;
                cout << "deleted Succesfully\n";
            }
            else
            {
                cout << "This position is not exist in linked list... \n";
            }
        }
    }

    void delete_from_specific_data(int deleteData)
    {
        Node *temp1 = NULL;
        Node *temp2 = head;

        if (temp2 == NULL)
        {
            cout << "Linked List is already empty...\n";
        }
        else
        {
            while (temp2 != NULL)
            {
                if (temp2->data == deleteData)
                {
                    if (temp2 == head)
                    {
                        head = temp2->next;
                    }
                    else
                    {
                        temp1->next = temp2->next;
                    }
                    Node *temp = temp2;
                    temp2 = temp2->next;
                    delete temp;
                }
                else
                {
                    temp1 = temp2;
                    temp2 = temp2->next;
                }
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
        int currentPos = 1;

        Node *temp = head;

        if (temp == NULL)
        {
            cout << "Linked List is Empty...\n";
        }
        else
        {
            while (currentPos < pos && temp != NULL)
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

    int size_of_linkedList()
    {
        int count = 0;
        Node *temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void middle_of_linked_list()
    {
        int middle = (size_of_linkedList() / 2) + 1;

        print_linked_list_Node_of_specific_position(middle);
    }

    int count_no_of_specific_data_in_the_linked_list(int data)
    {
        Node *temp = head;
        int count = 0;

        while (temp != 0)
        {
            if (data == temp->data)
            {
                count++;
            }

            temp = temp->next;
        }
        return count;
    }

    void check_if_linked_list_is_circular_or_not()
    {
        if (head == NULL)
        {
            cout<<"linked list is empty...\n";
        }
        else 
        {
            Node *temp = head;
            while (temp != NULL && temp != head)
            {
                temp= temp->next;
            }

            if (temp == head)
            {
                cout<<"Circular LINKED list...\n";
            }
            else
            {
                cout<<"Not Circular LINKED list...\n";
            }
            
            
        }
        
        
    }

    
};

int main()
{
    int choice, data, pos, update, pos1;

    CircularlinkedList list;
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
        cout << "12. Print linked list Node of specfic position\n";
        cout << "13. Print linked list from specific Node Position to specfic Node position\n";
        cout << "14. Print Middle elemnt of the linked list\n";
        cout << "15. Count How many existances of a single data are present in the given linked list\n";
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
            cout << "Size of linked List: " << list.size_of_linkedList() << "\n";
            break;

        case 12:
            cout << "Enter pos of node of linkedlist\n";
            cin >> pos;

            list.print_linked_list_Node_of_specific_position(pos);
            break;

        case 13:
            cout << "Enter the starting Position.\n";
            cin >> pos;
            cout << "Enter the Ending Position.\n";
            cin >> pos1;
            list.print_linked_list_from_specfic_node_to_specific_node(pos, pos1);
            break;

        case 14:
            list.middle_of_linked_list();
            break;
        case 15:
            cout << "Enter the data whom occurence you want to find\n";
            cin >> data;
            cout << "Total Exixtence of " << data << " is " << list.count_no_of_specific_data_in_the_linked_list(data) << "\n";
        }
    } while (choice != 0);
}