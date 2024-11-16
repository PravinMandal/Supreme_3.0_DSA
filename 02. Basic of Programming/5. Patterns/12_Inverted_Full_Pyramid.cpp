#include <iostream>
using namespace std;

void inversefullpyramid(int n)
{
    for( int row=0 ; row<n ; row++ )
    {
        for( int col=0 ; col<row ; col++)
        {
            cout<<" ";
        }
        for( int col=0 ; col<n-row ; col++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    
}

int main()
{
    int n;
    cout<<"Enter the length of pyramid :-";
    cin>>n;

    inversefullpyramid(n);


    return 0;
}