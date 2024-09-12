#include<iostream>
using namespace std;

int uniquenumber( int arr[] , int n)
{
    int ans=0;
    for(int i=0 ;i<n ; i++)
    {
         ans= ans^arr[i];
    }
    return ans;
}

int main()
{
    int arr[]={2,2,3,4,4};
    int size=5;

    
    int ans= uniquenumber(arr , size);
    cout<<"Unique number is : "<<ans;
    



    return 0;
}