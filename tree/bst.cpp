#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *leftChild;
    Node *rightChild;

    Node()
    {
        this->leftChild = NULL;
        this->rightChild = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }
};

class BST
{
public:
    Node *root;

    BST()
    {
        root = NULL;
    }

    bool isEmpty()
    {
        return (root == NULL);
    }

    void insertNode(int data)
    {
        Node *newNode = new Node(data);
        Node *curr, *prev;

        if (isEmpty())
            root = newNode;
        else
        {
            curr = prev = root;
            while (curr != NULL)
            {
                if (newNode->data > curr->data)
                {
                    prev = curr;
                    curr = curr->rightChild;
                }
                else
                {
                    prev = curr;
                    curr = curr->leftChild;
                }
            }
            if (prev->data > newNode->data)
            {
                prev->leftChild = newNode;
            }
            else
            {
                prev->rightChild = newNode;
            }
        }
        cout << "Node inserted successfully." << endl;
    }

    void displayBST()
    {
        if (isEmpty())
            cout << "\nBST Under Flow";
        else
        {
            cout << endl
                 << "Inorder: ";
            inorder(root);
            cout << endl
                 << "PreOrder: ";
            preorder(root);
            cout << endl
                 << "PostOrder: ";
            postorder(root);
            cout << endl;
        }
    }

    void inorder(Node *trav)
    {
        if (trav != NULL)
        {
            inorder(trav->leftChild);
            cout << " " << trav->data;
            inorder(trav->rightChild);
        }
    }

    void preorder(Node *trav)
    {
        if (trav != NULL)
        {
            cout << " " << trav->data;
            preorder(trav->leftChild);
            preorder(trav->rightChild);
        }
    }

    void postorder(Node *trav)
    {
        if (trav != NULL)
        {
            postorder(trav->leftChild);
            postorder(trav->rightChild);
            cout << " " << trav->data;
        }
    }

    void search(int data)
    {
        Node *temp = root;
        int depth = 0;
        while (temp != NULL)
        {
            depth++;
            if (temp->data == data)
            {
                cout << "\nData found at depth: " << depth << endl;
                return;
            }
            else if (temp->data > data)
            {
                temp = temp->leftChild;
            }
            else
            {
                temp = temp->rightChild;
            }
        }
        cout << "\nData not found" << endl;
    }

    int getSize()
    {
        return countNodes(root);
    }

    void printLeafNodes()
    {
        cout << "Leaf Nodes: ";
        printLeafNodesRec(root);
        cout << endl;
    }

    int getRootValue()
    {
        if (!isEmpty())
            return root->data;
        else
        {
            cout << "BST is empty" << endl;
        }
    }

    void deleteNode(int data)
    {
        if (isEmpty())
        {
            cout << "BST is empty. Cannot delete node." << endl;
            return;
        }
        bool isFound = false;
        Node *curr = root;
        Node *parent = NULL;
        while (curr != NULL)
        {
            if (curr->data == data)
            {
                isFound = true;
                break;
            }
            else if (data < curr->data)
            {
                parent = curr;
                curr = curr->leftChild;
            }
            else
            {
                parent = curr;
                curr = curr->rightChild;
            }
        }
        if (!isFound)
        {
            cout << "Node not found. Cannot delete." << endl;
            return;
        }
        if (curr->leftChild == NULL && curr->rightChild == NULL)
        {
            // Node is a leaf node
            if (parent == NULL)
                root = NULL;
            else if (parent->leftChild == curr)
                parent->leftChild = NULL;
            else
                parent->rightChild = NULL;
            delete curr;
        }
        else if (curr->leftChild != NULL && curr->rightChild != NULL)
        {
            // Node has two children
            Node *successor = getInorderSuccessor(curr);
            curr->data = successor->data;
            deleteNode(successor->data);
        }
        else
        {
            // Node has one child
            Node *child = (curr->leftChild != NULL) ? curr->leftChild : curr->rightChild;
            if (parent == NULL)
                root = child;
            else if (parent->leftChild == curr)
                parent->leftChild = child;
            else
                parent->rightChild = child;
            delete curr;
        }
        cout << "Node deleted successfully." << endl;
    }

    int countLevels()
    {
        return countLevelsRec(root);
    }

    int countTotalNodes()
    {
        return countNodes(root);
    }

private:
    int countNodes(Node *trav)
    {
        if (trav == NULL)
            return 0;
        else
            return countNodes(trav->leftChild) + countNodes(trav->rightChild) + 1;
    }

    void printLeafNodesRec(Node *trav)
    {
        if (trav == NULL)
            return;
        if (trav->leftChild == NULL && trav->rightChild == NULL)
            cout << trav->data << " ";
        printLeafNodesRec(trav->leftChild);
        printLeafNodesRec(trav->rightChild);
    }

    Node *getInorderSuccessor(Node *node)
    {
        Node *curr = node->rightChild;
        while (curr != NULL && curr->leftChild != NULL)
            curr = curr->leftChild;
        return curr;
    }

    int countLevelsRec(Node *trav)
    {
        if (trav == NULL)
            return 0;
        else
        {
            int leftHeight = countLevelsRec(trav->leftChild);
            int rightHeight = countLevelsRec(trav->rightChild);
            return 1 + max(leftHeight, rightHeight);
        }
    }
};

int main()
{
    BST tree;
    int choice, data;

    while (true)
    {
        cout << "********************* What do you want to *********************\n";
        cout << "1. Insert a node\n";
        cout << "2. Delete a node\n";
        cout << "3. Search for a node\n";
        cout << "4. Get the root value\n";
        cout << "5. Count the total number of nodes\n";
        cout << "6. Count the number of levels\n";
        cout << "7. Display the BST\n";
        cout << "8. Print leaf nodes\n";
        cout << "9. Exit\n";
        cout << "******************************************************************\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the data to insert: ";
            cin >> data;
            tree.insertNode(data);
            break;
        case 2:
            cout << "Enter the data to delete: ";
            cin >> data;
            tree.deleteNode(data);
            break;
        case 3:
            cout << "Enter the data to search: ";
            cin >> data;
            tree.search(data);
            break;
        case 4:
            cout << "Root value: " << tree.getRootValue() << endl;
            break;
        case 5:
            cout << "Total number of nodes: " << tree.countTotalNodes() << endl;
            break;
        case 6:
            cout << "Number of levels: " << tree.countLevels() << endl;
            break;
        case 7:
            cout << "BST contents:\n";
            tree.displayBST();
            break;
        case 8:
            tree.printLeafNodes();
            break;
        case 9:
            cout << "Exiting program..." << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    }

    return 0;
}
