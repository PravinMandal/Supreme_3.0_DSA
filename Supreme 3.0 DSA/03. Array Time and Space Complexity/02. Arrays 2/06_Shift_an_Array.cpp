#include<iostream>
using namespace std;

void ShiftAnArray(int arr[] , int size , int n)
{
     n=n%size;
    if(n==0)
    {
        //no need to do anything
        return ; 
    }

    //temp variable create kr rhe h jidr store krenge erase hone wale numbers ko

    int index=0;
    int temp[10000];
    for(int i=size-n ; i<size ; i++)
    {
        temp[index]= arr[i];
        index++;
    }
    //idhr hum shift kr rhe h array ko
    for(int i=size-1 ; i>=0 ; i--)
    {
        arr[i]=arr[i-n];
    }
    //yaha pr erase hue number ko temp variable se fetch krke wapas add kr rhe h array mai
    for(int i=0 ; i<n ; i++)
    {
        arr[i]=temp[i];
    }
    
}

int main()
{

    int arr[]={10,20,30,40,50,60};
    int size =6;

    //number of shift --> n
    int n=4;

    cout<<"Before"<<endl;
    for(int i=0 ; i<size ; i++)
    {
        cout<<arr[i]<<", ";
    }
    cout<<endl;

    ShiftAnArray(arr,size,n);

    cout<<"After"<<endl;
    for(int i=0 ; i<size ; i++)
    {
        cout<<arr[i]<<", ";
    }


    return 0; 
}