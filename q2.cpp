#include<iostream>
using namespace std;  

	class Rectangle{
		private:
			
			float  area;
		
		public:
		
			void SetArea (float l, float w)
			{
				area=l*w;
			}
			
			void GetArea ()
			{
				cout<<"Area of Rectangle is "<<area<<endl;
			}
	};

int main(){
	float len,bre;
	
	Rectangle r1;
	
	cout<<"Enter length of rectangle "<<endl;
	cin>>len;
	cout<<"Enter breath of rectangle "<<endl;
	cin>>bre;
	
	r1.SetArea(len,bre);
	r1.GetArea();
}
