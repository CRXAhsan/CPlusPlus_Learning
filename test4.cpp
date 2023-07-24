#include<iostream>
using namespace std;
//generic or you can say template 

template<typename t> void display(t a)
{
    cout<<"A : "<<a<<"\n";
}
template<typename type1> void SumOfNumbers(type1 a, type1 b)
{
    
    cout<<"a : "<<a<<"\n";
    cout<<"b : "<<b<<"\n";
}

int main()
{
    // display("Ahsan");
    SumOfNumbers(12,15);
    SumOfNumbers(12.3,15.4);
    return 0;
}