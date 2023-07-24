#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>

using namespace std;

void addRecord();

class student
{
    int rollNo; 
    char name[20];
    char gender;
    int age;
    int clas;

    public:
    //func for accessing the roll no attribute
    int getRollNo()
    {
        return rollNo;
    }

    //func to access the name attribbute
    char *getName()
    {
        return name;
    }

    //func to register data or getting the data of student
    void getData()
        {
            cout<<"Enter Roll No : ";
            cin>>rollNo;
            cout<<"Enter Name    : ";
            cin.ignore();
            cin.getline(name, 20);
            cout<<"Enter Gender  : ";
            cin>>gender;
            cout<<"Enter Age     : ";
            cin>>age;
            cout<<"Enter Class   : ";
            cin>>clas;
        }

    //func to modify the student data 
    void modifyData()
        {
            cout<<"Roll No : "<<rollNo<<endl;
            cout<<"Enter Name    : ";
            cin.ignore();
            cin.getline(name, 20);
            cout<<"Enter Gender  : ";
            cin>>gender;
            cout<<"Enter Age     : ";
            cin>>age;
            cout<<"Enter Class   : ";
            cin>>clas;
        }

    //func to display data in form of table
    void listData()
        {
            cout.setf(ios::left);
            cout<<setw(10)<<rollNo;
            cout<<setw(20)<<name;
            cout<<setw(10)<<gender;
            cout<<setw(10)<<age;
            cout<<setw(10)<<clas;
            cout<<endl;
        }

    //func to show student information in list form
    void showData()
        {
            cout<<"Roll No : "<<rollNo<<endl;
            cout<<"Name    : "<<name<<endl;
            cout<<"Gender  : "<<gender<<endl;
            cout<<"Age     : "<<age<<endl;
            cout<<"Class   : "<<clas<<endl;
        }
        
};

//func for the main display of the program
void menu() 
        {
            cout<<"****Student Record****\n";
            cout<<"0. exit\n";
            cout<<"1. Register New Student\n";
            cout<<"2. Show All Student\n";
            cout<<"3. Search by Roll No \n";
            cout<<"4. Search by Name \n";
            cout<<"5. Modify student record \n";
            cout<<"6. Delete student record \n";
            cout<<"Enter your choice : ";
        }

//func for file handling
void addRecord()
{
    ofstream fout;
    fout.open("StudentData",ios::out | ios::app | ios::binary);
    fout.close();
}

//func to display heading of table 
void heading() 
        {
            cout.setf(ios::left); // it is use for displaying content to left instea of down
            cout<<setw(10)<<"Roll No "; // setw(10) is use for set width of coulmns
            cout<<setw(20)<<"Name ";
            cout<<setw(10)<<"Gender ";
            cout<<setw(10)<<"Age ";
            cout<<setw(10)<<"Class ";
            cout<<endl;
        }

// main func from where program executes
int main()
{
    int n=0 , ch , rn;
    int i;
    char nm[20];
    int pos;

    //class and its object
    student s[10];
    
    do
    {
        system("cls");
        menu();
        cin>>ch;
        switch (ch)
        {
            case 1: // for registrarion of new student
                s[n].getData();
                n++;
                cout<<"\nRecord saved successfully...\n";
                break;
        
            case 2:  // for show all records of all students
                if( n>0 )
                {
                    heading();
                    for (i=0; i<n; i++)
                    {
                        s[i].listData();
                    }
                }
                else
                {
                    cout<<"No record to dispaly..."<<endl;
                }
                break;

            case 3: // for searching of student by roll no
            
                if( n>0 )
                {
                    cout<<"Enter Roll no to dispaly : ";
                    cin>>rn;

                    for (i=0; i<n; i++)
                    {
                        if(rn==s[i].getRollNo())
                        {
                            s[i].showData();
                        }
                        else
                        {
                            cout<<"No such Roll no found...\n";
                        }
                    }
                }
                else
                {
                    cout<<"No record to dispaly..."<<endl;
                }

                break;

            case 4: // for searching of student by name

                if( n>0 )
                {
                    cout<<"Enter Name to dispaly : ";
                    cin>>nm;

                    for (i=0; i<n; i++)
                    {
                       // strcmpi is a func which compare char arrays if upper case or lower case and return output
                       if (strcmpi(nm,s[i].getName())==0)
                        {
                            s[i].showData();
                        }
                        else
                        {
                            cout<<"No such name found...\n";
                        }
                    }
                }
                else
                {
                    cout<<"No record to dispaly..."<<endl;
                }
                break;

                case 5: // for searching of student by roll no
            
                if( n>0 )
                {
                    cout<<"Enter Roll no to modify record : ";
                    cin>>rn;

                    for (i=0; i<n; i++)
                    {
                        if(rn==s[i].getRollNo())
                        {
                            cout<<"Following record will be modified...\n";
                            s[i].showData();

                            cout<<"Enter New Data\n";
                            s[i].modifyData();
                        }
                        else
                        {
                            cout<<"No such Roll no found...\n";
                        }
                    }
                }
                else
                {
                    cout<<"No record to dispaly..."<<endl;
                }

                break;

                case 6: // for searching of student by roll no
            
                if( n>0 )
                {
                    cout<<"Enter Roll no to delete data : ";
                    cin>>rn;

                    for (i=0; i<n; i++)
                    {
                        if(rn==s[i].getRollNo())
                        {
                            cout<<"Following record is deleted...\n";
                            s[i].showData();
                            pos=i;
                        }
                        else
                        {
                            cout<<"No such Roll no found...\n";
                        }
                    }
                    for (i=pos ; i<n-1 ; i++ )
                    {
                        s[i]=s[i+1];
                    }
                    n--;
                    
                }
                else
                {
                    cout<<"No record to dispaly..."<<endl;
                }

                break;

        }

        system("pause");
    } while (ch);
    
}