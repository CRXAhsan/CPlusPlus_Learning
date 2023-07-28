#include <iostream>
using namespace std;

class Propositions
{
private:
    bool p, q;

public:
    void getPropositions()
    {
        cout << "You have to enter in 0 & 1 form\n";
        cout << "1 for True\n";
        cout << "0 for False\n\n";
        cout << "Enter the Truth value of p : ";
        cin >> p;
        cout << "Enter the Truth value of q : ";
        cin >> q;
    }

    void setPropositions()
    {

        bool conjunction = p && q;
        cout << "Conjunction: " << conjunction << "\n";

        bool disjunction = p || q;
        cout << "Disjunction: " << disjunction << "\n";

        bool exclusiveOr = (p || q) && !(p && q);
        cout << "Exclusive or: " << exclusiveOr << "\n";

        bool conditional = !p || q;
        cout << "Conditional statement: " << conditional << "\n";

        bool biconditional = (p && q) || (!p && !q);
        cout << "Biconditional: " << biconditional << "\n";
    }
};

int main()
{
    Propositions p;
    p.getPropositions();
    p.setPropositions();
}