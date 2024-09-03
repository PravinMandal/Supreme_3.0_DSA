#include<iostream>
using namespace std;

void FindfirstOccurence(int arr[], int target, int n ,int &ansIndex )
{
    int s=0;
    int e=n-1;
    // binary search humesha sorted array ka hi hoga
    int mid= s+(e-s)/2;

    while( s<=e)
    {
        if( arr[mid]== target)
        {
            //ans found, may or may not be the first occurence
            //ab first occurence ke liye left mai find krna pdega
            //abhi hum isse store kar lete h baad mai agar isse bhi kam index value pr target mila
            //toh usse store kr lenge
            ansIndex=mid; // store and compute stratergy
            //ab left mai find krna hai

            e=mid-1;
        }
        else if( arr[mid] > target)
        {
            e=mid-1;
        }
        else if( arr[mid] < target)
        {
            s=mid+1;
        }
        //ye mai humesha bhool jaata hu
        mid=s+(e-s)/2;
    }

    
}

int main()
{
    //first occurence mtlb target value konse sbse kam index number par aaya
    
    int arr[]= {10,20,20,20,20,20,30,40,50,60,70};
    int n=11;
    int target=20;
    int ansIndex= -1;
    //-1 aaya mtlb target nhi mila
    FindfirstOccurence(arr,target,n,ansIndex);
    cout<<"Index of First Occurence is: "<<ansIndex<<endl;
    
    return 0;
}