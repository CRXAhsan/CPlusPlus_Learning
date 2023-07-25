#include <iostream>
using namespace std;

// Find the element that appears once in an array where every other element appears twice

int elementApperaOnceInArray(int arr[], int size)
{
    int count;
    for (int i = 0; i < size - 1; i++)
    {
        count = 0;
        for (int j = i; j < size - 1; j++)
        {
            if (arr[i] == arr[j + 1])
            {
                count++;
            }
        }
        if (count == 0)
        {
            return arr[i];
        }
    }
}

// Write a program to print all the LEADERS in the array. An element is a leader if it is greater than all the elements to its right side. And the rightmost element is always a leader.

void printAllLeaderElements(int *arr, int size)
{
    int count;
    for (int i = 0; i < size; i++)
    {
        count = 0;
        for (int j = i; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                if (arr[i] != arr[j])
                {
                    count++;
                }
            }
        }

        if (count == 0)
        {
            cout << arr[i] << " , ";
        }
    }
}

// Find Subarray with given sum | Set 1 (Non-negative Numbers)

void subArrayOfGivenSum(int *arr, int size)
{
    int sum, totalSum, start, end, count = 0;
    cout << "Enter sum you want array size against that : ";
    cin >> sum;
    for (int i = 0; i < size; i++)
    {

        totalSum = 0;

        for (int j = i; j < size; j++)
        {
            totalSum += arr[j];
            if (sum == totalSum)
            {
                start = arr[i];
                end = arr[j];
                cout << "Sum found between index " << i << " & " << j << "\nThe elements are: \n";
                for (int k = i; k <= j; k++)
                {
                    cout << arr[k] << " , ";
                }
                cout<<"\n";
                count++;
            }
        }
    }
    if (count == 0)
    {
        cout << "No any sub array found for the given sum\n";
    }
}

int main()
{
    int size, temp = 0;
    cout << "Enter array size\n";
    cin >> size;
    int arr[size];
    cout << "Enter array elements\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // temp = elementApperaOnceInArray(arr, size);
    // cout << "Value " << temp << " is present one time in the whole array\n";

    // printAllLeaderElements(arr, size);

    subArrayOfGivenSum(arr, size);
}