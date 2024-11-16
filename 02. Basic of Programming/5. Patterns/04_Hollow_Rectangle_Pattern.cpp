#include <iostream>
using namespace std;

int main()
{
    int length, width;

    cout << "Enter length of Hollow Rectangle:- ";
    cin >> length;
    cout << "Enter Width of Hollow Rectangle:- ";
    cin >> width;

    for (int row = 0; row < width; row++)
    {
        for (int col = 0; col < length; col++)
        {
            if (row == 0 || row == width - 1 || col == 0 || col == length - 1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }

            // if( row==0 ||row==width-1)
            // {
            //     cout<<"* ";
            // }
            // else
            // {
            //     if( col==0 || col== length-1)
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