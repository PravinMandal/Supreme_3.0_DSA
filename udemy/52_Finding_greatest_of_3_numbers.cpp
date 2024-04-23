#include <iostream>
#include <string>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"Enter 3 Numbers:- "<<endl;
    cin>>a;

    if(a>b && a>c)
   { cout<<"The greatest number is :- "<<a<<endl;
   }
   else
   {
    if(b>c)
    {cout<<"The greatest number is :- "<<b<<endl;
    }
    else
    {
        cout<<"The greatest number is :- "<<c;
    }
   }
}