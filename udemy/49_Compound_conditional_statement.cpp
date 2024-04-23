#include<iostream>
using namespace std;
int main()
{
    int hour;
    cout<<"Enter the hour:- ";
    cin>>hour;
    if(hour>=9 && hour<=18)
   { cout<<"This is a working hour "<<endl;
   }
   else
   {
cout<<"This is Leisure or non working hour";

   }
return 0;
}