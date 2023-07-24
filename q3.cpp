#include<iostream> 
using namespace std;  

	class Number{

		public:
		
			void SetNum (int n)
			{
				if(n>0)
				{
					cout<<n<<" is positive."<<endl;
				}
				
				else
				{
					cout<<n<<" is negative."<<endl;
				}
				
				if(n%2==0)
				{
					cout<<n<<" is even."<<endl;
				}
				
				else
				{
					cout<<n<<"is odd."<<endl;
				}
			}
			
			void GetNum ()
			{
				
			}
	};

int main(){
	int  num;
	
	Number n1;
	
	cout<<"Enter any number "<<endl;
	cin>>num;
	
	
	n1.SetNum(num);
	n1.GetNum();
}
