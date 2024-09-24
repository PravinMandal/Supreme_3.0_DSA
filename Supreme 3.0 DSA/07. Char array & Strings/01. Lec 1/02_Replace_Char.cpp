#include<iostream>
using namespace std;

void replaceCharacter(char originalChar , char newchar , char arr[] , int size )
{
    for(int i=0 ; i<size ; i++)
    {
        if(arr[i] == originalChar)
        {
            arr[i]= newchar;
        }
    }
}

int main()
{
    char arr[1000];
    cout<<"Enter the sentence: ";
    cin>>arr;
    replaceCharacter('@' , ' ' , arr , 1000);
    cout<<arr;



    return 0;
}