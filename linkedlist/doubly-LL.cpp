#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node *prev;
		
	Node()
	{
		data = 0;
		next = NULL;
		prev = NULL;
	}
	
	Node(int val)
	{
		data = val;
		next = NULL;
		prev = NULL;
	}
};

class Linkedlist{
	Node *head;
	
	public:
	Linkedlist()
	{
		head = NULL;
	}
	
	
	
	
	
	
	
	
	
	
	
	void printList(Node *head);
	void insertAtStart(Node **head, int data);
	void insertAfterGivenNode(Node *lastNode, int value);
};

//void Linkedlist::printList()
//{
//	Node * ptr = head;
//
//if(head == NULL)
//{
//	cout<<"Linked list is empty"<<endl;
//}
//while(ptr != NULL){
//        //end = head;
//        cout<<ptr->data<<" ";
//        ptr = ptr->next;
//    }
//}

void Linkedlist::insertAtStart(Node **head, int data){
        
    Node *new_node = new Node();
	
	new_node->data = data;
	new_node->next = (*head);
	new_node->prev = NULL;
	
	
	//if prev of first node i.e. 6 to 
	//new _node i.e. newly created head
	if((*head)!= NULL)
	{
		(*head)-> prev = new_node;
	}
    
    (*head) = new_node;
}

void Linkedlist::insertAfterGivenNode(Node *lastNode, int value)
{
	//create new node
	Node *new_node = new Node();
	
	//place data into the new node
	new_node -> data = value;
	//make its next pointer point to the next of provided node
	new_node -> next = lastNode -> next;
	//make the provided node next point to new node 
	lastNode -> next = new_node;
	//new node prev should point to provided node
	new_node -> prev = lastNode;
	
	//check if new node next is null
	//if not then assign its next prev to new node created
	if (new_node->next != NULL)
        new_node->next->prev = new_node;
	
}

void Linkedlist::printList(Node * head)
{
	while(head != NULL){
        //end = head;
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main()
{
	Linkedlist ll;
	
	Node *head=NULL;
	
	ll.insertAtStart(&head,5);
	ll.insertAtStart(&head,6);
	ll.insertAtStart(&head,7);
	
	ll.insertAfterGivenNode(head, 52);
	ll.insertAfterGivenNode(head->next->next, 78);
//	while(head != NULL){
//        //end = head;
//        cout<<head->data<<" ";
//        head = head->next;
//    }
	ll.printList(head);
	return 0;
	
}
