//Print all even numbers available in the array.
//checking commit for array
#include<iostream>
using namespace std;

class array
{
    private:
        int size;
        int* arr;
    
    public:

        array()
        {
            arr= new int[size];
        }

        ~array()
        {
            delete[] arr;
        }

        void Array_Information()
        {
            cout<<"Enter Array Size\n";
            cin>>size;
            cout<<"Enter Array Elements\n";
            for (int i = 0; i < size; i++)
            {
                cin>>arr[i];
            }
        }

        void Even()
        {
            cout<<"\nEven numbers present in array\n";
            for (int i = 0; i < size; i++)
            {
                if (arr[i]%2 == 0)
                {
                    cout<<arr[i]<<" , ";
                }
                
            } 
        }

        void Odd()
        {
            cout<<"\n\nOdd numbers present in array\n";
            for (int i = 0; i < size; i++)
            {
                if (arr[i]%2 != 0)
                {
                    cout<<arr[i]<<" , ";
                }
                
            } 
        }

        void PrimeNumbers()
        {
            cout<<"\n\nPrime numbers present in array\n";
            for (int i = 0; i < size; i++)
            {
                int count=0;
                for(int j=1 ; j<=arr[i] ; j++)
                {
                    if (arr[i] % j == 0)
                    {
                        count++;
                    }
                }
                if (count == 2)
                {
                    cout<<arr[i]<<" , ";
                }
                
            } 
        }
};

int main()
{
    int choice;
    array a;
    do
    {    
    cout<<"\n\nwhat do you want to do\n";
    cout<<"1. Input Array\n";
    cout<<"2. All Even Numbers Presnt in the Array\n";
    cout<<"3. All Odd Numbers Presnt in the Array\n";
    cout<<"4. All Prime Numbers Presnt in the Array\n";
    cout<<"0. for Exit\n";
    cin>>choice;

    switch (choice)
    {
    case 1:
        a.Array_Information();
        break;
    
    case 2:
        a.Even();
        break;

    case 3:
        a.Odd();
        break;

    case 4:
        a.PrimeNumbers();
        break;
    }

    } while (choice != 0);

    
}