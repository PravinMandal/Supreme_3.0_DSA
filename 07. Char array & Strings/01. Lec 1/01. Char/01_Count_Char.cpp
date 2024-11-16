#include<iostream>
#include<vector>
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

int main()
{
    int name;
    char arr[1000];
    int size=1000;
    cout<<"Enter the name: ";
    cin>>arr;
    cout<<"Length of the char is: "<< charlength(arr,size)<<endl;

    return 0;
}