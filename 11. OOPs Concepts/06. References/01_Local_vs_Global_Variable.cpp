#include<iostream>
using namespace std;

int x=20; //Global Variable , isse hum kahin bhi use kr skte h poore code mai kahin bhi

int main(){

    cout<<x<<endl;
    // scope ("{}") mai kbhi bhi most recent variable access hota h

    int x=30; //Local variable 
    cout<<x<<endl;

    cout<<::x<<endl; // ::x ("::") ye daal kr hum kahin bhi global variable ko use kr skte h
    ::x=35;
    cout<<::x<<endl;
    cout<<x<<endl;
    {
        int x=40;
        {
            int x=50;
            cout<<x<<endl; // scope mai jo sbse zyada local hoga wo access hoga
        }
        cout<<x<<endl;
        cout<<::x<<endl;
    }





 return 0;   
}