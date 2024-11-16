
//first occurence mtlb target value konse sbse kam index number par aaya
#include<iostream>
using namespace std;

void FindfirstOccurence(int arr[], int target, int n ,int &ansIndex_1 ) 
// ansIndex  ko pass by reference kiya kyuki nhi kiya toh uske copy mai store hoga main jo 47 line mai h 
// usme krna h hume store 
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
            ansIndex_1=mid; // store and compute stratergy
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

void FindlastOccurence(int arr[], int target , int n , int &ansIndex_2)

{
    int s=0;
    int e=n-1;
    int mid= s+(e-s)/2;
    

    while(s<=e)
    {
        if(arr[mid]==target)
        {
            ansIndex_2=mid;
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

void FindTotalOccurence(int ansIndex_1 , int ansIndex_2)
{
    int totalOccurence;
    totalOccurence= (ansIndex_2 - ansIndex_1 + 1 ); 
    cout<<"Total Occurence are: "<< totalOccurence<<endl;
}
int main()
{
    //first occurence mtlb target value konse sbse kam index number par aaya
    
    int arr[]= {10,10,10,20,20,20,20,40,50,60,70};
    int n=11;
    int target=20;
    int ansIndex_1= -1;
    int ansIndex_2= -1;
    //-1 aaya mtlb target nhi mila
    FindfirstOccurence(arr,target,n,ansIndex_1);
    cout<<"Index of First Occurence is: "<<ansIndex_1<<endl;

    FindlastOccurence(arr,target,n,ansIndex_2);
    cout<< "Index of last occurence is: "<< ansIndex_2<<endl;

    FindTotalOccurence(ansIndex_1,ansIndex_2);
    
    return 0;
}