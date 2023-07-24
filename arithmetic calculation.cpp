 #include <iostream>
using namespace std;

// create a class of calculations named
class Calculations 
{
	// two private members for storing values of two integers
	private:
    	int A, B;
    	
	public:
		// create public functions
    	void get() 
		{
        	cout << "Enter First Number: "<<endl;
        	cin >> A;
        	cout << "Enter Second Number: "<<endl;
        	cin >> B;
    	}
    	// function for addition
    	int add() 
		{
        return A + B;
    	}
    	// function for subraction 
    	int sub() 
		{
        	return A - B;
	    }
	    // function for multiplication
	    int mul() 
		{
	        return A * B;
	    }
	    // function for division
	    int div() 
		{
	    	return A / B;
	   	}
	   	// function for modulus 
	   	int mod()
		{
	   	return A % B;
	    }
};


int main() 
{
	
    int choice;
    
    // call the class and make an object named as
    Calculations c1;
    
    // menu for calculation choices
    cout<< "Enter 1 Add 2 Numbers"
        << "\nEnter 2 Subtract 2 Numbers"
        << "\nEnter 3 Multiply 2 Numbers"
        << "\nEnter 4 Divide 2 Numbers"
        << "\nEnter 0 To Exit"
        << "\n";
        
        // using do while so that the calculator perform calculation with one run
	    do 
		{
    	    cout << "\nEnter Choice: ";
        	cin >> choice;
        	
        	// switch case use for the calculation which is in th menu
				switch (choice) 
				{
					
    	    		case 1:
        	    		c1.get();
            			cout << "Result: " << c1.add() << endl;
	            		break;
    			  		case 2:
    	       				c1.get();
				           	cout << "Result: " << c1.sub() << endl;
           					break;
			       			case 3:
	        				    c1.get();
				    	        cout << "Result: " << c1.mul() << endl;
        	   					break;
								case 4:
    	       						c1.get();
					        	   	cout << "Result: " << c1.div() << endl;
           							break;
           							case 5:
           								c1.get();
           								cout << "Result: " << c1.div() << endl;
           								break;
           								
        		}
        		
        		//conditon at which the loop terminates
    	} while (choice >= 1 && choice <= 5);
}
