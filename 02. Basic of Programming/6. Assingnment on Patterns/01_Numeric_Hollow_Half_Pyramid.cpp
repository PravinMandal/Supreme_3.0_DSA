#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the length of pyramid: ";
    cin>>n;
    for(int i=0 ; i<n ; i++ )
    {
        for(int j=0 ; j<i+1 ; j++)
        {
            if(i==n-1 || i==j || j==0 )
            {
                cout<<j+1<<" ";
            }
            
            else
            {
                cout<<"  ";
            }
        }
        cout<<endl;
        
    }
    

    return 0;
}