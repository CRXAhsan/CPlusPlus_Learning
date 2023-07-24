#include <iostream>
using namespace std;

void findMinIndex(int *arr, int size, int currentIndex, int minIndex)
{
    if (currentIndex == size)
    {
        return;
    }

    if (arr[currentIndex] < arr[minIndex])
    {
        minIndex = currentIndex;
    }

    findMinIndex(arr, size, currentIndex + 1, minIndex);
}

void swap(int *arr, int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void selectionSortRecursive(int *arr, int size, int currentIndex = 0)
{
    if (currentIndex == size - 1)
    {
        return;
    }

    int minIndex = currentIndex;
    findMinIndex(arr, size, currentIndex + 1, minIndex);

    if (minIndex != currentIndex)
    {
        swap(arr, minIndex, currentIndex);
    }

    selectionSortRecursive(arr, size, currentIndex + 1);
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

    selectionSortRecursive(arr, size);

    cout << "##### After Sorting #####\n\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " , ";
    }
    cout << "\n\n##########################\n\n";
}