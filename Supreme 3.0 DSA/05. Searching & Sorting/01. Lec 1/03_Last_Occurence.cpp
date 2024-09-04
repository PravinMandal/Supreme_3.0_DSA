#include<iostream>
using namespace std;

void lastOccurence(int arr[], int target , int n , int &ansIndex)
{
    int s=0;
    int e=n-1;
    int mid= s+(e-s)/2;
    

    while(s<=e)
    {
        if(arr[mid]==target)
        {
            ansIndex=mid;
            //store then compute
            s=mid+1;
        }
        else if(target < arr[mid])
        {
            e=mid-1;
        }
        else if( target > arr[mid])
        {
            s=mid+1;
        }
        //ye mai bhul jaata hu
        mid=s+(e-s)/2;
    }
}

int main()
{
    int arr[]={10,20,20,20,20,20,20,20,90};
    int n=9;
    int ansIndex=-1;
   
    int target=20;

    lastOccurence(arr,target,n,ansIndex);
    cout<< "Index of last occurence is: "<< ansIndex<<endl;



    return 0;
}