#include<iostream>
#include<math.h>
using namespace std;

int findMax(int arr[], int size)
{
    int maxNumber= arr[0] ;
    for(int i=0 ; i<size ; i++)
    {
        maxNumber=max(maxNumber, arr[i]);

    }
    return maxNumber;
}
int findMin(int arr[], int size)
{
    int minNumber=arr[0];
    for(int i=0 ; i<size ; i++)
    {
        minNumber=min(minNumber,arr[i]);
    }
    return minNumber;
}


int main()
{
    
    int arr[50];
    int size;
    int target;
    cout<<"Enter the size of array: ";
    cin>>size;
    for(int i=0 ; i<size ; i++)
    {
        cout<<"Enter the value for the index "<<i<<": ";
        cin>>arr[i];
    }
    int ansmax=findMax(arr,size);
    int ansmin=findMin(arr,size);
    cout<<"the max number is: "<<ansmax<<endl;
    cout<<"the min number is: "<<ansmin<<endl;

    return 0;
    

}