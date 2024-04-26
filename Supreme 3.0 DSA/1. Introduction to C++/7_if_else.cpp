#include<iostream>
using namespace std;
int main()
{
    int marks;
    cin>>marks;
    if(marks>=90)
    {
        cout<<"Macha diya bhai!!!"<<endl;
    }
    else if(marks>=80 && marks<90)
    {
        cout<<" tera hi sahi h"<<endl;
    }
    else if (marks<80 && marks>=70)
    {
        cout<<"koi na bhai sahi hai"<<endl;
    }
    else if(marks<70 && marks>=60)
    {
        cout<<"bhai kya kar rha hai tu"<<endl;
    }
    else if(marks<60 && marks>=50)
    { 
        cout<<"ye toh tatti hai"<<endl;
    }

    return 0;
}

