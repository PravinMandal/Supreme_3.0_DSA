#include<iostream>
using namespace std;


int countZeroandOne(int arr[],int size)
{
    int countone=0;
    int countzero=0;
    for(int i=0 ; i<size ; i++)
    {
        
        if(arr[i]==1)
        {
             countone=countone+1;
        }
        else if( arr[i]==0)
        {
            countzero++;
        }

    }
    

    cout<<"Number of one's are: "<<countone<<endl;
    cout<<"Number of zero's are: "<<countzero<<endl;
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
    countZeroandOne(arr,size);

   return 0;
}