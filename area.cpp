 #include <iostream>
using namespace std;

// create a class of shape named
class Shape
{
	// two private members for storing values of two integers
	private:
    	int A, B;
    	
	public:
		// create public functions
    	void get() 
		{
        	cout << "Enter value: "<<endl;
        	cin >> A;
        	cin >> B;
    	}
    	// function for calculating circle radius
    	int circle() 
		{
        return (2*3.142*A*B);
    	}
    	// function for calculating area of square 
    	int square() 
		{
        	return A*B;
	    }
	    // function for calculating area of triangle
	    int triangle() 
		{
	        return (A*B)/2;
	    }
};


int main() 
{
	
    int choice;
    
    // call the class and make an object named as
    Shape c1;
    
    // menu for calculation choices
    cout<< "Enter 1 for circle radius"
        << "\nEnter 2 for square area"
        << "\nEnter 3 for triangle area"
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
            			cout << "Result: " << c1.circle() << endl;
	            		break;
    			  		case 2:
    	       				c1.get();
				           	cout << "Result: " << c1.square() << endl;
           					break;
			       			case 3:
	        				    c1.get();
				    	        cout << "Result: " << c1.triangle() << endl;
        	   					break;
           								
        		}
        		
        		//conditon at which the loop terminates
    	} while (choice >= 1 && choice <= 3);
}
