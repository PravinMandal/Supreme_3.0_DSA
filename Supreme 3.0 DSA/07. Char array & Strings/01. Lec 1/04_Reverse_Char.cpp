#include<iostream>
using namespace std;

int charlength(char arr[] , int n)
{
    int count=0;
    int i=0;
    while(arr[i] != '\0' )
    {
        count++;
        i++;
        
    }
    return count;
}

void ReverseChar(char arr[], int n)
{
    int len=charlength(arr,n);
    int i=0;
    int j=len-1;
    while(i<=j)
    {
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}

int main()
{
    int name;
    char arr[1000];
    int size=1000;
    cout<<"Enter the name: ";
    cin>>arr;
    cout<<"Befor: "<< arr<<endl;
    ReverseChar(arr,size);
    cout<<"After: "<< arr<<endl;
    

    return 0;
}