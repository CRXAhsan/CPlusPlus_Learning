#include<iostream>
using namespace std;

int main()
{
    // this is a short trick to completely zero the whole array by defining only first element
    //of the array
    int arr[5] = {0};

    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    //this is the array which we have given we dont no the size of this array so we have a 
    //formula to find how much elements are in this array
    int array1[] = {1,2,3,4,4,5,6,7,8,0,9};

    // here we have to divide the array with ite data type to calculate its length
    int size = sizeof(array1)/sizeof(int);

    /*types of array algorithm
    bubble sort
    insertion sort
    selection sort
    merge sort(divide and conquer technique)1.break,2.sort,3.merge the array
    heap sort
    */

}