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

void ConvertIntoUpperCase(char arr[] , int size)
{
    int len= charlength(arr,size);
    for(int i=0 ; i<len ; i++)
    {
        char ch= arr[i];
        //agar lower case letter hai tabhi convert kro
        if( ch>='a'&& ch<='z')
        {
        ch=ch -'a'+'A';
        }
        arr[i]=ch;
    }
}


void ConvertIntoLowerCase(char arr[] , int size)
{
    int len= charlength(arr,size);
    for(int i=0 ; i<len ; i++)
    {
        char ch= arr[i];
        //agar lower case letter hai tabhi convert kro
        if( ch>='A'&& ch<='Z')
        {
        ch=ch -'A'+'a';
        }
        arr[i]=ch;
    }
}

int main()
{
    int name;
    char arr[1000];
    int size=1000;
    cout<<"Enter the name: ";
    cin>>arr;
    // ConvertIntoUpperCase(arr,size);
    ConvertIntoLowerCase(arr,size);
    cout<<arr;

    return 0;
}