#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> stk;
    stk.push(20);
    stk.push(10);
    stk.push(50);

    cout << stk.size();
}