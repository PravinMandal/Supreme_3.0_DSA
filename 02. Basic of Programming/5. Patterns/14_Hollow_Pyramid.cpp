#include<iostream>
using namespace std;


void hollowpyramid(int n)
{
    for(int row=0 ; row<n ; row++)
    {
        for(int col=0 ; col<n-row-1 ; col++)
        cout<<" ";
        for(int col=0 ; col<row+1 ; col++)
        {
            if(col==0 || row==n-1 || col==row)
            cout<<"* ";
            else
            cout<<"  ";
        }
        cout<<endl;
    }
}
void invertedhollowpyramid(int n)
{
    for(int row=0 ; row<n ; row++)
    {
        for( int col=0 ; col<row ; col++)
        cout<<" ";
        for( int col=0 ; col<n-row ; col++)
        {
            if(row==0 || col==0 || col==n-row-1)
            cout<<"* ";
            else
            cout<<"  ";
        }
        cout<<endl;
    }
}
void hollowdiamond(int n)
{
    hollowpyramid(n);
    invertedhollowpyramid(n);
}

int main()
{
    int n;
    cout<<"Enter the length of pyramid:-";
    cin>>n;

    hollowdiamond(n);


    return 0;
}