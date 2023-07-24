#include <iostream>
using namespace std;

	class Fibonacci {
		
		private: int number;

			public:
				
				void SetSeries()
				{
				cout<<"Enter the lenght of Fibonacci series: ";
				cin>> number;
				}
				
				void GetSeries()
				{
				int c=1,n=1,p=0;
				
				while(n <= number)
				{
				c = n;
				n = c + p;
				p = c;
				cout << c << ", ";
	
	   			}
   
				}
	};
	
int main(){
	
	Fibonacci  F1;
	F1.SetSeries();
	F1.GetSeries();

}
