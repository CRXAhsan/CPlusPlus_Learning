#include <iostream>
using namespace std;

void InsertionSort(int *arr , int size)
{
	for(int i = 0 ; i < (size - 1) ; i++)
	{
		for(int j = i+1 ; j > 0 ; j--)
		{
			if( arr[j] < arr[j-1] )
			{
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
			else
			{
				break;
			}
		}
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

    InsertionSort(arr, size);

    cout << "##### After Sorting #####\n\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " , ";
    }
    cout << "\n\n##########################\n\n";
}