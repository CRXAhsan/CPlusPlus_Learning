#include <iostream>
using namespace std;

template <typename T> 
class Stack
{
    private:
        int size;
        int top;
        T* arr;

    public:

    
        Stack()
        {

        }

        Stack(int size)
        {
            this->size=size;
            // dynamically allocate the memory so that we can make user defined array stack
            arr = new T[size]; 
            top=-1;
        }

        ~Stack()
        {
            //free the memory which we use for making our stack
            delete[] arr;
        }

        T top()
        {
            return arr[top];
        }

        bool is_Empty()
        {
            if (top < 0 )
            {
                return false;
            }
            else
            {
                return true;
            } 
        }

        bool is_Full()
        {
            if (top < size)
            {

                return true;
            }
            else
            {
                return false;
            } 
        }

        void push(T a)
        {
            if (!is_Full())
            {
                cout<<"#####  Stack Overflow  #####\n";
            }
            else
            {
                arr[++top] = a ;
                cout<<arr[top]<<"  Pushed into Stack\n";
            }
        }

        // for adding any value to the stack
        void pop()
        {
            if (!is_Empty())
            {
                cout<<"#####  Stack Underflow  #####\n";
            }
            else
            {
                cout<<arr[top--]<<"\n";
            }
        }
        // for checking the value on the top of the stack
        void peak()
        {
            if (!is_Empty())
            {
                cout<<"#####  Stack is Empty  #####\n";
            }
            else
            {
                cout<<arr[top]<<"\n";
            }
        }

        void sizeOfStack()
        {
            cout<<(top+1)<<" values in stack.\n";
        }

        
};

int prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

// The main function to convert infix expression
// to postfix expression
void infixToPostfix(string s)
{

	Stack<char> st;
	string result;

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];

		// If the scanned character is
		// an operand, add it to output string.
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'))
			result += c;

		// If the scanned character is an
		// ‘(‘, push it to the stack.
		else if (c == '(')
			st.push('(');

		// If the scanned character is an ‘)’,
		// pop and add to output string from the stack
		// until an ‘(‘ is encountered.
		else if (c == ')') {
			while (st.top() != '(') {
				result += st.top();
				st.pop();
			}
			st.pop();
		}

		// If an operator is scanned
		else {
			while (!st.is_Empty()
				&& prec(s[i]) <= prec(st.top())) {
				result += st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	// Pop all the remaining elements from the stack
	while (!st.is_Empty()) {
		result += st.top();
		st.pop();
	}

	cout << result << endl;
}

// Driver code
int main()
{
	string exp = "a+b*(c^d-e)^(f+g*h)-i";

	// Function call
	infixToPostfix(exp);
	
	return 0;
}
