#include<iostream>
using namespace std;

pair<int,int> checkTwoSum(int arr[] , int n , int target)
{
    //assuming (-1,-1) as no answer found
    pair<int,int> ans =make_pair(-1,-1);
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(arr[i]+arr[j]==target)
            {
                ans.first=arr[i];
                ans.second=arr[j];
                return ans;
                
            }
        }
    }
    return ans;
}

void printAllTriplets(int arr[] , int n )
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            for(int k=0 ; k<n ; k++)
            {
                cout<<arr[i]<<","<<arr[j]<<","<<arr[k]<<endl;
            }
        }
    }
}
int main()
{
    int arr[]={5,10,15,20,25,30,35};
    int n=7;
    int target=60;

    pair<int,int> ans= checkTwoSum(arr,n,target);
    if(ans.first==-1 && ans.second==-1)
    {
        cout<<"pair not found"<<endl;
    }
    else
    {
        cout<<"pair found: "<<ans.first<<","<<ans.second<<endl;
    }

    // printAllTriplets(arr,n);



    return 0;
}