#include<iostream>
using namespace std;

void fullpyramid(int n)
{
    for(int row=0 ; row<n ; row++)
    {
        for(int col=0 ; col< n-row-1; col++)
        {
            cout<<" ";

        }
        for(int col=0 ; col < row+1 ; col++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}

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

void diamond(int n)
{
    fullpyramid(n);
    inversefullpyramid(n);
}

int main()
{
    int n;
cout<<"Length of Pyaramid:- ";   
cin>>n;

diamond(n);

    return 0;
}