#include<iostream>
using namespace std;
// create a class of employee
class Employee{
	//private class members
	private:
		string emp_name[200];
		int emp_id[200];
		int emp_salary[200];
		
	// public class functions
	public:
			
			// geters used to get values and relate them with private members
			void getname(string name[200])
			{
				for(int i=1; i<=5; i++)
				{
					emp_name[i]=name[i];
				}
			}
			
			void getid(int id[200]){
				for(int i=1; i<=5; i++)
				{
					emp_id[i]=id[i];
				}
				
			}
			
			void getsalary(int salary[200]){
				for(int i=1; i<=5; i++)
				{
					emp_salary[i]=salary[i];
				}
				
			}
			// using seter to reuse the data stored in private memebers
			void set_employee_details()
			{
				for(int i=1; i<=5; i++)
				{
					cout<<"Employee "<<i<<" details."<<endl;
					cout<<"Name: "<<emp_name[i]<<endl;
					cout<<"ID: "<<emp_id[i]<<endl;
					cout<<"Salary: "<<emp_salary[i]<<endl;
				}
				
			}
			
};

int main(){
	// call class and create a object "emp"
	Employee emp;
	
	//set arrays for recieve data
	string arr_name[200];
	int arr_id[200];
	int arr_salary[200];
	
	cout<<"Enter employee details"<<endl;
	
	// loop for taking data
	for(int i=1; i<=5; i++)
	{
	cout<<"Employee No. "<<i<<endl;
	
	cout<<"Name "<<endl;
	cin>>arr_name[i];
	
	cout<<"Id "<<endl;
	cin>>arr_id[i];
	
	cout<<"Salary "<<endl;
	cin>>arr_salary[i];
	}
	
	//calling functions first write object name then call the related functions
	emp.getname(arr_name);
	emp.getid(arr_id);
	emp.getsalary(arr_salary);
	
	emp.set_employee_details();
}
