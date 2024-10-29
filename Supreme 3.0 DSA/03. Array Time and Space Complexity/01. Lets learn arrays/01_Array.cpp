#include<iostream>
using namespace std;

bool findtarget(int arr[] , int size ,int targetValue )
{
    
    for(int i=0 ; i<size ; i++)
    {
       if (arr[i]==targetValue)
       {
        return true;
       }

    }
    return false;
}

int main ()
{
    int size;
    int arr[50];
    cout<<"Enter number of element: ";
    cin>>size;

    for(int i=0 ; i<size ; i++)
    {
        cout<<"Enter the input value for index "<<i << endl;
        cin>> arr[i];

    }
    int targetValue;
    cout <<"Enter target value: ";
    cin>>targetValue;
    findtarget(arr, size , targetValue);
    bool ans= findtarget (arr , size , targetValue) ;
    cout<<ans;



    return 0;
}