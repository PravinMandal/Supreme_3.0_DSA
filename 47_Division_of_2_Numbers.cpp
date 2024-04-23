#include<iostream>
using namespace std;
int main()
{
    float a,b,c;
    cout<<"Enter 2 Numbers:- "<<endl;
    cin>>a>>b;
    if(b==0)
    {
        cout<<"Division by 0 cannot be done "<<endl;

    }
    else
    {
        c=a/b;
        cout<<"Division of the given number is:- "<<c<<endl;
    }
 return 0;
}