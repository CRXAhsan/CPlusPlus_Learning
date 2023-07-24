#include<iostream>
using namespace std;

class convertName{

    private:string name="Ahsan tariq";

    public:
    int nameconvert(){
    	cout<<"The ascii code of name is "<<name<<" "<<endl;
        for (int i = 0; i < name.length(); i++)
        {
            cout<<int (name.at(i));
           
       
        }
       
    }
};
int main(){
convertName n1;
cout<<n1.nameconvert();

}
