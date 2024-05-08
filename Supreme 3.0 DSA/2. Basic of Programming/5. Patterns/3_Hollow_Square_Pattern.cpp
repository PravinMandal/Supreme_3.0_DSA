#include <iostream>
using namespace std;

int main()
{
    int side;

    cout << "Enter side of a Hollow Square:- ";
    cin >> side;

    for (int row = 0; row < side; row++)
    {
        for (int col = 0; col < side; col++)
        {
            if (row == 0 || row == side - 1 || col == 0 || col == side - 1 || row == col || row + col == side - 1 || col == (side - 1) / 2 || row == (side - 1) / 2)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }

            // if( row==0 ||row==side-1)
            // {
            //     cout<<"* ";
            // }
            // else
            // {
            //     if( col==0 || col== side-1)
            //     {
            //         cout<<"* ";
            //     }
            //     else
            //     {
            //         cout<<"  ";
            //     }
            // }
        }
        cout << endl;
    }

    return 0;
}