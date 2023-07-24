#include <iostream>
using namespace std;

void BinarySearch(int arr[], int size, int find)
{
    int count = 0;
    int start = 0;
    int end = size, mid;
    while (start <= end)
    {

        mid = (start + end) / 2;
        if (find == arr[mid])
        {
            cout << arr[mid] << " is present in the array \n";
            return;
        }
        else if (arr[mid] < find)
        {
            start = mid + 1;
        }
        else if (arr[mid] > find)
        {
            end = mid - 1;
        }
    }

    cout << find << " is not present in the array\n";
}

int main()
{
    int size, find;
    cout << "Enter size of arrray\n";
    cin >> size;
    int arr[size];
    cout << "Enter Array Elements\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter element to be find : ";
    cin >> find;

    BinarySearch(arr, size, find);
}