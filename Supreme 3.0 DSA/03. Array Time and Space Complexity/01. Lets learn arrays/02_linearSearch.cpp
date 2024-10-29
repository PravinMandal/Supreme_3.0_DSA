#include<iostream>
using namespace std;

bool FindTarget(int arr[] , int size , int target)
{
    for(int i=0 ; i<size ; i++)
    {
        if(arr[i] == target)
        {
            
            return true;
        }
        
    }
    return false;
}

int main()
{
    int arr[50];
    int size;
    int target;
    cout<<"Enter the size of array: ";
    cin>>size;
    for(int i=0 ; i<size ; i++)
    {
        cout<<"Enter the value for the index "<<i<<": ";
        cin>>arr[i];
    }
    cout<<"Enter the target number: ";
    cin>>target;
    bool ans= FindTarget(arr,size,target);
    cout<<ans;

    return 0;
}