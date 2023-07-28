#include <iostream>
using namespace std;

int main()
{
    string var = "HelloWorld";
    string temp;
    cout << "string before : " << var << "\n";

    int n = var.length();

    for (int i = (n - 1); i >= 0; i--)
    {
        temp = temp + var[i];
    }
    cout << "string After : " << temp << "\n";
}