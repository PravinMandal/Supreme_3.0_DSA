#include<iostream>
using namespace std;

void pattern(int n)
{
    for(int i=0 ; i<n ; i++)
    {
        char p;
        for(int j=0 ; j<i+1 ; j++)
        {
        
        p='A'+j;
        cout<<p;
        }
        for(p=p-1 ; p > 'A'-1; p--)
        {
            cout<<p;
        }

        cout<<endl;
    }
    
}


int main()
{
    int n;
    cout<<"Enter size of pattern :-";
    cin>>n;
    pattern(n);


    return 0;
}