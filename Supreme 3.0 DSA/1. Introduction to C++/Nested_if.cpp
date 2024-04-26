#include<iostream>
using namespace std;

int main()
{
    float height,weight;

    cout<<"Enter your height:- ";
    cin>>height;
   

    if(height>=5)
    {
        cout<<"Enter your weight:- ";
        cin>>weight;

        if(weight>=65)
        {
            cout<<"Tu thik hai bhai";

        }
        else
        {
            cout<<"Bhai tujhse na ho payega";
        }
    }
    
    else
    {
        cout<<"complan dila du";
    }


    return 0;
}