#include<iostream>
using namespace std;

void SortZeroOne(int arr[] , int n)
{
    //counting zero and one
    int countZero=0;
    int coutOne=0;
    for(int i=0 ; i<n ; i++)
    {
        if(arr[i]==0)
        {
            countZero++;
        }
        else if(arr[i]==1)
        {
            coutOne++;
        }
    }

    //inserting

    // fill(arr , arr+countZero , 0);
    // fill(arr+coutOne , arr+n , 1);

    for(int i=0 ; i<countZero ; i++)
    {
        arr[i]=0;
    }
    for(int i=countZero ; i<n ;i++)
    {
        arr[i]=1;
    }
    



}

int main()
{
    int arr[]={1,1,0,1,0,0,1};
    int size=7;

    SortZeroOne(arr,size);

    for(int i=0 ; i<size ; i++)
    {
        cout<<arr[i]<<" ";
    }




    return 0;
}