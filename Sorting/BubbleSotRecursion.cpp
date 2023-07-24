#include <iostream>
using namespace std;

void Swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSortRecursion(int arr[], int start, int end)
{
    if (start < end)
    {
        if (arr[start] > arr[start + 1])
        {
            Swap(arr[start], arr[start + 1]);
        }
        BubbleSortRecursion(arr, start + 1, end);
    }
}

void BubbleSort(int arr[], int start, int end)
{
    if (start < end)
    {
        BubbleSortRecursion(arr, start, end);
        BubbleSort(arr, start, end);
    }
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

    BubbleSort(arr, 0, size - 1);

    cout << "##### After Sorting #####\n\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " , ";
    }
    cout << "\n\n##########################\n\n";
}