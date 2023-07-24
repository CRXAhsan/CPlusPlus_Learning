#include <iostream>
using namespace std;

void insert(int *arr, int size, int key)
{
    if (size > 0 && arr[size - 1] > key)
    {
        arr[size] = arr[size - 1];
        insert(arr, size - 1, key);
    }
    else
    {
        arr[size] = key;
    }
}

void insertionSortRecursive(int *arr, int size)
{
    if (size <= 1)
        return;

    insertionSortRecursive(arr, size - 1);
    insert(arr, size - 1, arr[size - 1]);
}

int main()
{
    int size;
    cout << "Enter size of arrray\n";
    cin >> size;
    int arr[size];
    cout << "Enter Array Elements\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "##### Before Sorting #####\n\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " , ";
    }
    cout << "\n\n##########################\n\n";

    insertionSortRecursive(arr, size);

    cout << "##### After Sorting #####\n\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " , ";
    }
    cout << "\n\n##########################\n\n";
}