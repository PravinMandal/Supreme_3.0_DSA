#include<iostream>
using namespace std;

void PrintThreeSum(int arr[] , int n , int target)
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
        {
            for(int k=j+1 ; k<n ; k++)
            {
                if(arr[i]+arr[j]+arr[k]==target)
                {
                    cout<<arr[i]<<", "<<arr[j]<<", "<<arr[k]<<endl;
                }
                
            }
        }
    }
}

int main()
{
    int arr[]={10,20,30,40,50};
    int n=5;
    int target=80;

    PrintThreeSum(arr,n,target);



    return 0;
}