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

bool CheckPalindrome(char arr[] , int size)
{
    int len=charlength(arr,size);
    int i=0;
    int j=len-1;
    while(i<=j)
    {
        if(arr[i]==arr[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    //yaha tak pohoch gya matlab saare case check kr liya and koi different char nhi mila 
    //mtlb palindrome hai
    return true;
}

int main()
{
    int name;
    char arr[1000];
    int size=1000;
    cout<<"Enter the word: ";
    cin>>arr;
    cout<<"Palindrome or not: "<< CheckPalindrome(arr,size)<<endl;


    

    return 0;
}