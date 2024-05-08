#include<iostream>
using namespace std;

int main()
{
    int length, width;

    cout<<"Enter length of Rectangle:- ";
    cin>>length;

    cout<<"Enter width of rectangle:- ";
    cin>>width;

    for(int row=0 ; row< width ; row++ )
    {
        for(int col=0; col< length ; col++ )
        {
            cout<<"* ";
        }
        cout<<endl;
    }





    return 0;
}