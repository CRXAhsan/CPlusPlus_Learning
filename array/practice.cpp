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

void printAllLeaderElements(int *arr , int size)
{
    int count;
    for (int i = 0; i < size; i++)
    {
        count=0;
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
            cout<<arr[i]<<" , ";
        }
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

    //temp = elementApperaOnceInArray(arr, size);
    //cout << "Value " << temp << " is present one time in the whole array\n";


    printAllLeaderElements(arr,size);
}