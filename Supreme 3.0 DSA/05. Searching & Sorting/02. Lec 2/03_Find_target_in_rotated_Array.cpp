//isme kya krna h ki rotated array hoga( mtlb pivot array type hoga) usme target find out krna hai

#include<iostream>
using namespace std;

int FindPivotIndex( int arr[])
{
    
    //pivot 90 hai iss case mai
    int n=9;
    int s=0;
    int e=n-1;
    int ansIndex=-1;

    int mid=s+(e-s)/2;

    while(s<=e)
    {
        if(s==e)
        {
            ansIndex=s;
        }
        if( mid+1<n ,arr[mid]>arr[mid+1])
        {
            ansIndex=mid;
        }
        if(arr[mid] < arr[s])
        {
            //mtlb wo pivot ke aage hai
            //mtlb piche jaana h
            e=mid-1;
        }
        else
        {
            //abhi wo pivot ke left mai hai 
            s=mid+1;

        }
        //ye mai bhul jaata hu
        mid=s+(e-s)/2;
    }
    return ansIndex;
}

int BinarySearch(int arr[] , int target , int s , int e)
{
    int n=9;
    

    int mid=s+(e-s)/2;

    while(s<=e)
    {
        
        if(arr[mid]==target)
        {
            return mid;
            break;
        }
        else if(target< arr[mid])
        {
            e=mid-1;
        }
        else if(target > arr[mid])
        {
            s=mid+1;
        }

        mid=s+(e-s)/2;

    }
    return -1;
}

int main()
{
     int arr[]={60,70,80,90,10,20,30,40,50};
      int n=9;
      int s=0;
      int e=n-1;
      int target= 90;

     int PivotIndex= FindPivotIndex(arr);
     
     
        if( target >= arr[s] && target<= arr [PivotIndex])
        {
            int ans=BinarySearch(arr, target , s , PivotIndex);
            cout<<"Found it Target index value is: "<<ans;
            

        }

        else 
        {
            int ans= BinarySearch(arr,target, PivotIndex , e);
            cout<<"Found it Target indexs value iss: "<<ans;
            
            
        }
        
      
    return 0;
}