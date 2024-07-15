#include<iostream>
using namespace std;

int main()
{
    int n; 
    cout<<"Enter the size of pattern: ";
    cin>>n;
    int k=1;
    int c=(2*n-1);

    for(int i=0 ; i<(c) ; i++)
    {
        for(int j=0 ; j<k ; j++)
        {
            cout<<"* ";
          

        }
        if(i<(c/2))
           { k++;
           }
           else 
           {
            k--;
           }
        cout<<endl;

    }

    return 0;
}