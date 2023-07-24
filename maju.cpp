//Using abstract keyword, explore Maju student portal. Create Maju class,
//create virtual method sidemenu(). Then create classes with the name that
//is appear at your side menu list, inherit these classes to Maju class , create
//virtual methods according to requirement.

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

//abstract class
class MAJU
{
    public:

        virtual void sideMenu()=0;

        
};

// side menu

class GeneralInformation : public MAJU
{
    protected :
    //data variables for personal information
    string registrationNo;
    string name; 
    string fatherName;
    string address;
    string email;
    string phone;
    string dateOfBirth;
    string program;
    string school;
    string college; 
    //data variables for academic information
    //matric
    float matricMarks;
    float matricTotalMarks;
    int yearMatric;
    float percentageMatric;
    //intremediate
    float intermediateMarks;
    float intermediateTotalMarks;
    int yearIntermediate;
    float percentageIntermediate;

    public :
    

    //func for getting personal information
    void personalInformation()
    {
        
        cout<<"Enter your Registration No : ";
        getline(cin,registrationNo);
        cout<<"Enter your Program : ";
        getline(cin,program);
        cout<<"Enter your Name : ";
        getline(cin,name);
        cout<<"Enter your Father Name : ";
        getline(cin,fatherName);
        cout<<"Enter your Email : ";
        getline(cin,email);
        cout<<"Enter your phone : ";
        getline(cin,phone);
        cout<<"Enter your Address : ";
        getline(cin,address);
        cout<<"Enter your Date of Birth : ";
        getline(cin,dateOfBirth);
    }
    //func for getting academic inforamtion
    void academicInformation()
    {
        cout<<"\nEnter your Matric or S.S.C or O-Level Details "<<endl<<endl;
        cout<<"Enter School Name : ";
        getline(cin,school);
        cout<<"Enter Obtained Marks : ";
        cin>>matricMarks;
        cout<<"Enter Total Marks : ";
        cin>>matricTotalMarks;
        cout<<"Enter Year of Passing : ";
        cin>>yearMatric;

        cout<<"\nEnter your Intermediate or H.S.C or A-Level Details "<<endl<<endl;
        cout<<"Enter College Name : ";
        getline(cin,college);
        cout<<"Enter Obtained Marks : ";
        cin>>intermediateMarks;
        cout<<"Enter Total Marks : ";
        cin>>intermediateTotalMarks;
        cout<<"Enter Year of Pasing : ";
        cin>>yearIntermediate;
    }
    //func for dispalying personal and academic information
    void sideMenu()
    {
        
        cout<<"******Personal Information********************************************************"<<endl;
        cout<<" Registration#: "<<registrationNo<<endl;
        cout<<"      Program : "<<program<<endl;
        cout<<" Student Name : "<<name<<endl;
        cout<<"  Father Name : "<<fatherName<<endl;
        cout<<"Date of Birth : "<<dateOfBirth<<endl;
        cout<<"      Address : "<<address<<endl;
        cout<<"        Phone : "<<phone<<endl;
        cout<<"        Email : "<<email<<endl;
        cout<<"**********************************************************************************/n/n"<<endl<<endl;

        cout<<"******Academic Information*******************************************************************************"<<endl;
        cout.setf(ios::left);

        // heading of display table in row
        cout<<setw(30)<<"Degree ";
        cout<<setw(20)<<"Marks Obtained";
        cout<<setw(20)<<"Total Marks";
        cout<<setw(20)<<"percentage";
        cout<<setw(20)<<"Passing Year";
        cout<<setw(20)<<"Institute"<<endl;

        // details of the student for matric in row
        cout<<setw(30)<<"SSC/Matric/O-Level";
        cout<<setw(20)<<matricMarks;
        cout<<setw(20)<<matricTotalMarks;
        percentageMatric=(matricMarks*100)/matricTotalMarks;
        cout<<setw(20)<<percentageMatric;
        cout<<setw(20)<<yearMatric;
        cout<<setw(20)<<school<<endl;

        // details of the student for intermediate in row
        cout<<setw(30)<<"HSC/Intermediate/A-Level";
        cout<<setw(20)<<intermediateMarks;
        cout<<setw(20)<<intermediateTotalMarks;
        percentageIntermediate=(intermediateMarks*100)/intermediateTotalMarks;
        cout<<setw(20)<<percentageIntermediate;
        cout<<setw(20)<<yearIntermediate;
        cout<<setw(20)<<college<<endl;
        cout<<"*********************************************************************************************************"<<endl<<endl;
        
    }

    void compulsoryData()
    {
        cout<<" Registration#: "<<setw(20)<<registrationNo;
        cout<<"      Program : "<<setw(20)<<program<<endl;
        cout<<" Student Name : "<<setw(20)<<name;
        cout<<"  Father Name : "<<setw(20)<<fatherName<<endl;
        cout<<"Date of Birth : "<<setw(20)<<dateOfBirth<<endl;
    }
};

class Announcements : public MAJU
{
    public:
    
    //func for maju announcements for students
    void sideMenu()
    {
        
        cout<<"*****Anouncement*****************\n\n";
        cout<<"*No Announcement Found\n\n";
        cout<<"*********************************\n\n";
        
    }
};

class Notice_Board : public MAJU
{
    public:
    
    //func for notices for maju students generateed by university
    void sideMenu()
    {
        
        cout<<"******Notice Board****************\n"<<endl;
        cout<<"Attendenace Policy-FALL 2022"<<endl;
        cout<<"Office of the Registrar"<<endl;
        cout<<"[Download]\n"<<endl;
        cout<<"**********************************\n"<<endl;
        
    }
};

class My_Courses :  public GeneralInformation
{
    protected:
    // data members for courses of student 
    string course_1;
    string course_2;
    string course_3;
    string course_4;
    string course_5;
    string course_6;

    public:

    string getcourse1(){ return course_1; }
    string getcourse2(){ return course_2; }
    string getcourse3(){ return course_3; }
    string getcourse4(){ return course_4; }
    string getcourse5(){ return course_5; }
    string getcourse6(){ return course_6; }

    //func for getting the courses of student
    void selecCourses()
    {
        
        cout<<"Enter the Name of the Courses in which you want to enroll"<<endl<<endl;
        cout<<"Course No.1 : ";
        getline(cin,course_1);
        cout<<"Course No.2 : ";
        getline(cin,course_2);
        cout<<"Course No.3 : ";
        getline(cin,course_3);
        cout<<"Course No.4 : ";
        getline(cin,course_4);
        cout<<"Course No.5 : ";
        getline(cin,course_5);
        cout<<"Course No.6 : ";
        getline(cin,course_6);
    }

    //func for displaying the courses of student
    void sideMenu()
    {
        
        cout.setf(ios::left);
        cout<<"******My Courses (FA22)*****************************************************\n "<<endl;
        compulsoryData();
        cout<<"\n*****Courses**************************************************************\n "<<endl;
        cout<<"  1.  "<<getcourse1()<<"   2.   "<<getcourse2()<<"    3.   "<<getcourse3()<<endl;
        cout<<"  4.  "<<getcourse4()<<"   5.   "<<getcourse5()<<"    6.   "<<getcourse6()<<endl;
        cout<<"****************************************************************************\n"<<endl;
        
    }

};

class My_Time_Table :  public My_Courses
{
    public:
    

    //fall semester program time table
    void sideMenu()
    {
        
        cout<<"*********************************************My Time Table (FA22)*********************************************\n"<<endl;
        compulsoryData();
        cout<<setw(20)<<"Time  |  Day";
        cout<<setw(20)<<"Mon";
        cout<<setw(20)<<"Tues";
        cout<<setw(20)<<"Wed";
        cout<<setw(20)<<"Thur";
        cout<<setw(20)<<"Fri"<<endl;

        cout<<setw(20)<<"8:30 - 9:30";
        cout<<setw(20)<<getcourse1();
        cout<<setw(20)<<getcourse2();
        cout<<setw(20)<<getcourse3();
        cout<<setw(20)<<getcourse4();
        cout<<setw(20)<<getcourse5()<<endl;

        cout<<setw(20)<<"9:30 - 10:30";
        cout<<setw(20)<<getcourse6();
        cout<<setw(20)<<getcourse1();
        cout<<setw(20)<<getcourse2();
        cout<<setw(20)<<getcourse3();
        cout<<setw(20)<<getcourse4()<<endl;

        cout<<setw(20)<<"11:30 - 12:30";
        cout<<setw(20)<<getcourse5();
        cout<<setw(20)<<getcourse6();
        cout<<setw(20)<<getcourse1();
        cout<<setw(20)<<getcourse2();
        cout<<setw(20)<<getcourse3()<<endl;

        cout<<setw(20)<<"12:30 - 1:30";
        cout<<setw(20)<<getcourse4();
        cout<<setw(20)<<getcourse5();
        cout<<setw(20)<<getcourse6()<<endl;
        cout<<"****************************************************************************************************************\n"<<endl;
        
    }
};

class My_Attendance :  public My_Courses
{
    public:
    
    //func for displaying attendance of fall semester
    void sideMenu()
    {
        
        cout<<"***********************************My Attendance (FA22)*********************************************\n"<<endl;
        compulsoryData();
        cout<<endl;
        cout<<setw(100)<<"Courses Name "<<endl;
        cout<<setw(100)<<getcourse1()<<setw(20)<<"Total Lectures : 32"<<setw(20)<<"Total Abscents : 1"<<endl;
        cout<<setw(100)<<getcourse2()<<setw(20)<<"Total Lectures : 32"<<setw(20)<<"Total Abscents : 0"<<endl;
        cout<<setw(100)<<getcourse3()<<setw(20)<<"Total Lectures : 32"<<setw(20)<<"Total Abscents : 3"<<endl;
        cout<<setw(100)<<getcourse4()<<setw(20)<<"Total Lectures : 32"<<setw(20)<<"Total Abscents : 1"<<endl;
        cout<<setw(100)<<getcourse5()<<setw(20)<<"Total Lectures : 32"<<setw(20)<<"Total Abscents : 0"<<endl;
        cout<<setw(100)<<getcourse6()<<setw(20)<<"Total Lectures : 32"<<setw(20)<<"Total Abscents : 0"<<endl;
        cout<<"\n****************************************************************************************************"<<endl;
        
    }
    
};

class My_Transcript : public My_Courses
{
    public:
    
    //func for dispalying your credit hours
    void sideMenu()
    {
        
        cout<<"**********************************My Transcript (FA22)*********************************************"<<endl;
        cout<<"Semester#2 [FALL 2022]"<<endl<<endl;
        compulsoryData();
        cout<<endl;

        cout<<setw(100)<<"Courses"<<setw(20)<<"Credit Hours"<<setw(20)<<"Grades"<<endl;
        cout<<setw(100)<<getcourse1()<<setw(20)<<"3"<<setw(20)<<"A"<<endl;
        cout<<setw(100)<<getcourse2()<<setw(20)<<"3"<<setw(20)<<"A+"<<endl;
        cout<<setw(100)<<getcourse3()<<setw(20)<<"2"<<setw(20)<<"A-"<<endl;
        cout<<setw(100)<<getcourse4()<<setw(20)<<"3"<<setw(20)<<"B+"<<endl;
        cout<<setw(100)<<getcourse5()<<setw(20)<<"2"<<setw(20)<<"A"<<endl;
        cout<<setw(100)<<getcourse6()<<setw(20)<<"3"<<setw(20)<<"A+"<<endl<<endl;
        cout<<"***************************************************************************************************"<<endl;

    }
};

class Academic_Deadlines : public MAJU
{
    public:
    
    // func for displaying academic deadlines of students
    void sideMenu()
    {
        
        cout<<"*******************Academic Deadlines : FA22***********************"<<endl<<endl;
        cout<<"*Academic deadlines are not published for term FA22 "<<endl<<endl;
        cout<<"*******************************************************************"<<endl;
        
    }
};

class Academic_Calendar : public MAJU
{
    public:
    
    //func for students all academic activities
    void sideMenu()
    {
        
        cout<<"***************************************Academic Calender : FA22*************************************************************** "<<endl<<endl;
        cout<<setw(30)<<"Serial No."<<setw(50)<<"Activity"                                 <<setw(50)<<"              Date"<<endl;
        cout<<setw(30)<<"1 "        <<setw(50)<<"Course Registration (Existing Batches)"   <<setw(50)<<"  Saturday, August 13, 2022 "<<endl;
        cout<<setw(30)<<"2 "        <<setw(50)<<"Orientation of New Intake (FALL 2022)"    <<setw(50)<<"	Saturday, September 10, 2022"<<endl;
        cout<<setw(30)<<"3 "        <<setw(50)<<"Commencement of Classes"                  <<setw(50)<<"	Monday, September 12, 2022"<<endl;
        cout<<setw(30)<<"4 "        <<setw(50)<<"Course Add/Drop"                          <<setw(50)<<"	Monday, September 12, 2022 "<<endl;
        cout<<setw(30)<<"5 "        <<setw(50)<<"Eid Milad Un Nabi (PBUH) *"               <<setw(50)<<"	Sunday, October 09, 2022"<<endl;
        cout<<setw(30)<<"6 "        <<setw(50)<<"Midterm Examinations"                     <<setw(50)<<"	Wednesday, November 09, "<<endl<<endl;
        cout<<"*******************************************************************************************************************************"<<endl;
                                                            
    }
};

class Course_Registration : public MAJU
{
    public:
    
    //func for registration
    void sideMenu()
    {
        
        cout<<"*******************Course registration for term (FA22)*******************\n"<<endl;
        cout<<"Cannot register course because you have already registered course"<<endl<<endl;
        cout<<"*************************************************************************"<<endl;
        
    }
};

class Course_Withdrawal : public MAJU
{
    public:
    
    void sideMenu()
    {
        
        cout<<"***************My Date Sheet***************\n"<<endl;
        cout<<"MIDTERM  [ Click here to view ] "<<endl<<endl;
        cout<<"*******************************************"<<endl;
        
    }
};

class Course_Evaluation : public MAJU
{
    public:
    
    void sideMenu()
    {
        
        cout<<"*************Course Evaluation*************\n"<<endl;
        cout<<"Session has been expired or unbegun"<<endl<<endl;
        cout<<"*******************************************"<<endl;
        
    }
};

class My_Program_Courses : public MAJU
{
    public:
    
    void sideMenu()
    {
        
    cout<<"*********My Program Courses***************\n"<<endl;
    cout<<" Code "<<"         Course name            \n"<<endl; 
	cout<<"CS1210"<<" Introduction to Computing      "<<endl;
	cout<<"CS1211"<<" Introduction to Computing Lab  "<<endl;	
	cout<<"CS1410"<<" Computer Programming           "<<endl;	
	cout<<"CS1411"<<" Computer Programming Lab       "<<endl;	
	cout<<"MG1100"<<" Principles of Management       "<<endl;	
	cout<<"MT1150"<<" Basic Maths-I	                 "<<endl;	
	cout<<"SS1100"<<" Freshman English               "<<endl;	
	cout<<"SS1160"<<" Functional English             "<<endl;	
	cout<<"SS1400"<<" Islamic Studies	             "<<endl;	
	cout<<"SS1410"<<" Ethics	                     "<<endl;
	cout<<"CS1420"<<" Object Oriented Programming	 "<<endl;
	cout<<"CS1421"<<" Object Oriented Programming Lab"<<endl;	
	cout<<"CS2620"<<" Discrete Structures	         "<<endl;	
	cout<<"MT1140"<<" Calculus and AnalyticalGeometry"<<endl;
	cout<<"MT1180"<<" Basic Maths-II	             "<<endl;
	cout<<"NS1240"<<" Applied Physics	             "<<endl;
	cout<<"SS2120"<<" Oral Communication	         "<<endl;
	cout<<"CS2510"<<" Data Structures and Algorithms "<<endl;
	cout<<"CS2511"<<" Data Structures and Algorithms "<<endl;	
	cout<<"CS3110"<<" Software Engineering	         "<<endl;
	cout<<"CS3111"<<" Software Engineering Lab	     "<<endl;
	cout<<"MT2210"<<" Linear Algebra	             "<<endl;
	cout<<"MT2300"<<" Probability and Statistics	 "<<endl;	
	cout<<"SS2300"<<" Principles of Psychology	     "<<endl;	
	cout<<"SS2310"<<" Principles of Sociology	     "<<endl;	
    cout<<"\n******************************************"<<endl;
    
    }
};

class Program_Time_Table : public MAJU
{
    public:
    
    void sideMenu()
    {
        
        cout<<"***********************Program Time Table***********************"<<endl<<endl;
        cout<<"  program time table is not issued yet"<<endl;
        cout<<"\n****************************************************************"<<endl;
        
    }
};

class My_Datesheet : public MAJU
{
    public:
    
    void sideMenu()
    {
        
        cout<<"*****************My Date Sheet*****************"<<endl<<endl;
        cout<<"date sheet for mid term examination"<<endl;
        cout<<"[clicl here]\n"<<endl;
        cout<<"***********************************************"<<endl;
        
    }
};

class Fee_Challan : public My_Courses
{
    public:
    
    //func for fee challan generation
    void sideMenu()
    {

        cout<<"************************************************************Registered Courses*******************************************************************************\n"<<endl;
        cout<<"Course Title                 "<<"Credit Hours"<<"   Per Credit Fee  "<<"Course Fee"<<"Section"<<" Status  "<<"     Teacher Name     "<<"     Place(s)"<<endl;
    	cout<<"Discrete Structures          "<<"     3      "<<"         5500      "<<"  16500   "<<"  BM   "<<"Confirmed"<<"FAIZ ULLAH	           "<<"CG-C1,CG-C4,CG-C5"<<endl;
    	cout<<"OOP lab                      "<<"     1      "<<"         5500      "<<"  5500    "<<"  BM   "<<"Confirmed"<<"HIBA IRFAN	           "<<"CS-C1"<<endl;
    	cout<<"Object Oriented Programming  "<<"     3      "<<"         5500      "<<"  16500   "<<"  BM   "<<"Confirmed"<<"ZAIN NOREEN	       "<<"CG-C5,CG-C6,CG-C8"<<endl;
    	cout<<"Oral Communication           "<<"     3      "<<"         5500      "<<"  16500   "<<"  BM   "<<"Confirmed"<<"SUMRA PEERAN	       "<<"AG-C2,CG-C4"<<endl;
    	cout<<"Calcules And Analytical      "<<"     3      "<<"         5500      "<<"  16500   "<<"  BM   "<<"Confirmed"<<"MUHAMMAD UMER ZEESHAN "<<"CG-C1,CG-C5,CG-C8"<<endl;
    	cout<<"Applied Physics              "<<"     3      "<<"         5500      "<<"  16500   "<<"  BM   "<<"Confirmed"<<"Muhammad Zeeshan	   "<<"CG-C2,CG-C8"<<endl;
        cout<<"Total                        "<<"     16     "<<"         88000     "<<endl;	
        cout<<"\n**************************************************************************************************************************************************************\n";
        	
    }
};

class My_Deficiency_Course : public MAJU
{
    public:
    
    void sideMenu()
    {
        
        cout<<"******My Defiency Course***************\n"<<endl;
        cout<<"No defiency course to display\n"<<endl;
        cout<<"***************************************"<<endl;
        
    }
};

class Advance_Registration : public MAJU
{
    public:
    
    void sideMenu()
    {
        
        cout<<"******Advance Registration*************************"<<endl<<endl;
        cout<<"* No advance registration is available yet \n"<<endl;
        cout<<"***************************************************"<<endl;
        
    }
};

class Advance_Registration_Fee_Challan : private MAJU
{
    public:
    
    void sideMenu()
    {
        
        cout<<"*****Advance Registration Fee Chalan*********************"<<endl<<endl;
        cout<<"* No advance registration fee chalan is available\n"<<endl;
        cout<<"*********************************************************"<<endl;
        
    }
};

int main()
{

    GeneralInformation GI;
    GI.personalInformation();
    GI.academicInformation();
    GI.sideMenu();

    Announcements A;
    A.sideMenu();

    Notice_Board NB;
    NB.sideMenu();

    My_Courses MC;
    MC.selecCourses();
    MC.sideMenu();

    My_Time_Table MTT;
    MTT.sideMenu();

    My_Attendance MA;
    MA.sideMenu();

    My_Transcript MT;
    MT.sideMenu();

    Academic_Deadlines AD;
    AD.sideMenu();

    Academic_Calendar AC;
    AC.sideMenu();

    Course_Registration CR;
    CR.sideMenu();

    Course_Withdrawal CW;
    CW.sideMenu();

    Course_Evaluation CE;
    CE.sideMenu();

    My_Program_Courses MPC;
    MPC.sideMenu();

    Program_Time_Table PTT;
    PTT.sideMenu();

    My_Datesheet MD;
    MD.sideMenu();

    Fee_Challan FC;
    FC.sideMenu();

    My_Deficiency_Course MDC;
    MDC.sideMenu();

    Advance_Registration AR;
    AR.sideMenu();

    Advance_Registration_Fee_Challan ARFC;
    ARFC.sideMenu();

}