#include <iostream>
using namespace std;

class Tree
{
public:
    void printTree(int arr[], int size)
    {
        node = size / 2;

        cout << "Possible parent nodes present in your array are " << node << "\n";
        cout << "Give the parent node number to print its left and right child values\n";
        cin >> parent;
        parent = parent - 1;

        leftChild = (2 * parent) + 1;
        rightChild = (2 * parent) + 2;

        cout << "Parent Value is   : " << arr[parent];
        cout << "\nLeft Child Value  : " << arr[leftChild];
        cout << "\nRight Child Value : " << arr[rightChild];
    }

    void insertInTree(int arr[] , int size)
    {
        
    }

private:
    int node, parent, leftChild, rightChild;
};

int main()
{
    int size;

    Tree t;

    cout<<"Enter array size : ";
    cin>> size;

    int arr[size];

    cout<<"Array Elements\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    
    t.printTree(arr, size);
}