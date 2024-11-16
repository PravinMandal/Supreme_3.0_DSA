#include<iostream>
using namespace std;

void printextreme(int arr[], int size)
{
    int i=0;
    int j=size-1;
    while(i<=j)
    {
        
       cout<<arr[i]<<" ";
        i++;
        
       if(j>i)
       { cout<<arr[j]<<" ";
        j--;
       }
       
    }

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
    printextreme(arr,size);

    return 0;
}