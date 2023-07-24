#include <iostream>
using namespace std;

void LinearSearch(int arr[], int size, int find)
{
    int j = 0, dupliacte[10], count = 0;
    for (int i = 0; i < size; i++)
    {
        if (find == arr[i])
        {
            dupliacte[j] = i;
            count++;
            j++;
        }
    }
    if (count > 0)
    {
        cout << find << " is present in the array at below positions\n";
        for (int j = 0; j < count; j++)
        {
            cout << "At Position : " << dupliacte[j] << "\n";
        }
    }
    else
    {
        cout << find << " is not present in the array\n";
    }
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

    LinearSearch(arr, size, find);
}