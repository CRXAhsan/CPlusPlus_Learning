#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST
{
    Node *root;

public:
    BST()
    {
        this->root = NULL;
    }

    void InOrderTraversal(Node *temp)
    {
        if (temp != NULL)
        {
            InOrderTraversal(temp->left);
            cout << temp->data << " , ";
            InOrderTraversal(temp->right);
        }
    }

    void PreOrderTraversal(Node *temp)
    {
        if (temp != NULL)
        {
            cout << temp->data << " , ";
            PreOrderTraversal(temp->left);
            PreOrderTraversal(temp->right);
        }
    }

    void PostOrderTraversal(Node *temp)
    {
        if (temp != NULL)
        {
            PostOrderTraversal(temp->left);
            PostOrderTraversal(temp->right);
            cout << temp->data << " , ";
        }
    }
};

int main()
{
    cout<<"";
}