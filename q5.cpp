#include<iostream> 
using namespace std;  

	class Pattern{

		public:
		
			void SetRow (int num)
			{
				for(int i=0; i<num; i++){
					for(int j=0; j<=i; j++){
						cout<<" * ";
					}
					cout<<endl;
				}
			}
			
			void GetRow ()
			{
				
			}
	};

int main(){
	int num;
	
	Pattern p1;
	
	cout<<"Enter any number "<<endl;
	cin>>num;
	
	
	p1.SetRow(num);
	p1.GetRow();
}
