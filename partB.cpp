#include <iostream>
using namespace std;

class Series
{
private:
    int sequence[100];
    int n, count = 0, diff;
    int temp[100];

    int difference;
    int a, b;
    int result;
    int nth;

public:
    void setSequence()
    {
        cout << "How much numbers are in your Sequence\n";
        cin >> n;
        cout << "Enter Sequence\n";
        for (int i = 0; i < n; i++)
        {
            cin >> sequence[i];
        }
    }

    void getRecursiveAndClosure()
    {

        for (int i = 0; i < n; i++)
        {
            temp[i] = sequence[i + 1] - sequence[i];
            if (i == 0)
            {
                a = sequence[i + 1] - sequence[i];
                b = sequence[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (temp[i] = temp[i + 1])
            {
                diff = temp[i];
                count++;
            }
        }
        if (count == n)
        {
            for (int i = 0; i < n; i++)
            {
                cout << sequence[i] << ", ";
            }

            cout << "\n\nThe recursive formula is: f(n) = " << a << " * (n-1) + " << b << "\n\n";

            cout << "The closure formula is: f(n) = " << a << " * n + " << b << "\n\n";

            cout << "Enter nth term of sequence to find ? \n";
            cin >> nth;
            result = a * (nth - 1) + b;
            cout << "The value of the " << nth << "-th term is: " << result << "\n";
        }
        else
        {
            cout << "you have entered wrong series\n";
        }
    }
};

int main()
{
    Series s;
    s.setSequence();
    s.getRecursiveAndClosure();
}
