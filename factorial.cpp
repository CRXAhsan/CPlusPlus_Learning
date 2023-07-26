#include<iostream>   
using namespace std;
// create a class of calculation 
class Calculations
{
	// make private members 
	private:
		int factorial;
		
	// make public functions
	public:
		
		// seter used for provide link between private members and public members
		void setfactorial(int fac)
		{
			factorial= fac;
		}
		
		// geters are used for getting the result
		int getfactorial()
		{
			int temp=1;
			
			// scenerio for finding factorial of any number
			for(int i=1; i<=factorial; i++)
			{
				temp=temp*i;
			}
			cout << "The factorial of "<<factorial<< " is "<<temp<<endl;
		}
};

int main()
{
	int num;
	
	// calling class and make an object named as "c1"
	Calculations c1;
	
	cout<<"Enter a integer number : "<<endl;
	cin>>num;
	
	// calling functions to perform calculation
	c1.setfactorial(num);
	c1.getfactorial();
	
}
