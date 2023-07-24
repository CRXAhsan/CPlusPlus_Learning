#include <iostream>
using namespace std;

void merge(int *arr, int start, int mid, int end)
{
    int leftArrSize = mid - start + 1;
    int rightArrSize = end - mid;
    int leftArr[leftArrSize];
    int rightArr[rightArrSize];

    for (int i = 0; i < leftArrSize; i++)
    {
        leftArr[i] = arr[start + i];
    }

    for (int j = 0; j < rightArrSize; j++)
    {
        rightArr[j] = arr[mid + j + 1];
    }

    int i = 0, j = 0, k = start;

    while (i < leftArrSize && j < rightArrSize)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < leftArrSize)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < rightArrSize)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main()
{
    int arr[15]{9, 6, 4, 7, 2, 0, 1, 7, 3, 89, 54, 12, 9, 13, 1};

    cout << "*************Before Sorting*************\n";
    for (int i = 0; i < 15; i++)
    {
        cout << arr[i] << " ";
    }
    mergeSort(arr, 0, 14);
    cout << "\n\n*************After Sorting*************\n";
    for (int i = 0; i < 15; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
