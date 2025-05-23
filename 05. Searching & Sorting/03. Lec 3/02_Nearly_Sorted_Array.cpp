// Given a sorted array arr[] of size N, some elements of array are moved to either of the adjacent positions, i.e., arr[i] may be present at arr[i+1] or arr[i-1] i.e. arr[i] can only be swapped with either arr[i+1] or arr[i-1]. The task is to search for an element in this array.

// Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 40
// Output: 2
// Explanation: Output is index of 40 in given array i.e. 2

// Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 90
// Output: -1
// Explanation: -1 is returned to indicate the element is not present

#include<iostream>
using namespace std;

int BinarySearchInNearlySortedArray(int arr[],int size,int target)
{
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;

    while(s<=e)
    {
        if(target == arr[mid])
        {
            return mid;
        }
        else if(target == arr[mid-1])
        {
            return mid-1;
        }
        else if(target == arr[mid+1])
        {
            return mid+1;
        }

        if(target<arr[mid])
        {
            //left
            e=mid-2;
        }
        else
        {
            //right
            s=mid+2;
        }
        mid=s+(e-s)/2;
    

    }
    return -1;
}


int main()
{
    int arr[] =  {10, 3, 40, 20, 50, 80, 70};
    int size=7;
    int target=40;

    int ans= BinarySearchInNearlySortedArray(arr,size,target);
    cout<<"Target found on index no.: "<<ans<<endl;


    return 0;
}