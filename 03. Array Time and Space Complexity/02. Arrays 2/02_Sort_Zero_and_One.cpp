#include<iostream>
using namespace std;

void SortZeroOne(int arr[] , int n)
{
    //counting zero and one
    int countZero=0;
    int countOne=0;
    for(int i=0 ; i<n ; i++)
    {
        if(arr[i]==0)
        {
            countZero++;
        }
        else if(arr[i]==1)
        {
            countOne++;
        }
    }

    //inserting

    // fill(arr , arr+countZero , 0);
    // fill(arr+countOne , arr+n , 1);

    for(int i=0 ; i<countZero ; i++)
    {
        arr[i]=0;
    }
    for(int i=countOne ; i<n ;i++)
    {
        arr[i]=1;
    }
    
}


void TwoPointerMethod(int arr[] , int n){
    int i=0;
    int j=n-1;
    while(i<j){
        if(arr[i]==0){
            i++;
        }
        if(arr[j]==1){
            j--;
        }

        if(arr[i]==1 && arr[j]==0){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
}

int main()
{
    int arr[]={1,1,0,1,0,0,1,0,1,1};
    int size=10;

    // SortZeroOne(arr,size);

    // for(int i=0 ; i<size ; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

    cout<<endl;

    TwoPointerMethod(arr,size);
    for(int i=0 ; i<size ; i++)
    {
        cout<<arr[i]<<" ";
    }




    return 0;
}