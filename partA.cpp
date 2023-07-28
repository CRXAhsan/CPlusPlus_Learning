#include <iostream>
using namespace std;

class Relation
{
private:
    int matrix[10][10];
    int row = 0, coulmn = 0;
    int count = 0;

public:
    void setMatrix()
    {
        cout << "Determine the matrix rows & coulmns \n";
        cout << "Enter Rows : ";
        cin >> row;
        cout << "Enter Coulmns : ";
        cin >> coulmn;
        cout << "You have To enter in 0 & 1 form\n";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < coulmn; j++)
            {
                cin >> matrix[i][j];
            }
        }
    }

    void getMatrix()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < coulmn; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
        //<-------------------------reflexive and irireflexive -------------------------->
        if (row == coulmn)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < coulmn; j++)
                {
                    if (i == j)
                    {
                        if (matrix[i][j] == 1)
                        {
                            count++;
                        }
                    }
                }
            }
        }
        if (count == row)
        {
            cout << "The Relation is Reflixive\n";
        }
        else
        {
            cout << "The Relation is Ir-reflixive\n";
        }

        //<------------------------for symetric antisymmetric------------------------>
        int transpose[10][10];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < coulmn; j++)
            {
                if (matrix[i][j] == matrix[j][i])
                {
                    count++;
                }
            }
        }
        if (count++ == ((row * coulmn) + row))
        {
            cout << "The relation is Symmetric\n";
        }
        else
        {
            cout << "The relation is Anti-Symmetric\n";
        }

        //<-----------------------transistive------------------------------------>

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < coulmn; j++)
            {
                for (int k = 0; k < coulmn; k++)
                {
                    if ((i != j && j != k) && (matrix[i][j] == 1 && matrix[j][k] == 1 && matrix[i][k] == 1))
                    {
                        count++;
                    }
                }
            }
        }
        if (count > 1)
        {
            cout << "The realtion is Transitive\n";
        }
        else
        {
            cout << "The realtion is not Transitive\n";
        }
    }
};

int main()
{
    Relation r1;
    r1.setMatrix();
    r1.getMatrix();
}
