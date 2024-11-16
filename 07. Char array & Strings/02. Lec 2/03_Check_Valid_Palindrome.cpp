// iss question mai hume kya krna h ki hume ek string milega wo palindrome ho bhi skta h nhi bhi agar nhi hai 
// toh hum ek character remove kr skte h max and phir check krna h palindrome h ki nhi

#include<iostream>
using namespace std;

bool checkPalindrome(string str , int s , int e)
{
    while(s<=e)
    {
    if(str[s] != str[e])
    {
        return false;
    }
    else
    {
        s++;
        e--;
    }
    }
    //yaha tak pohoch gya matlab ek baar bhi aisa case nhi aaya jisme str[s] != str[e]
    //mtlb palindrome hai
    return true;
}

bool validPalindrome(string s)
{
    int n=s.length();
    int i=0;
    int j=n-1;
    while(i<=j)
    {
        if(s[i]==s[j])
        {
            i++;
            j--;
        }
        else
        {
            //i and j equal nhi aaya
            // ab dono mai se koi ek delete krke dekna h ki palindrome bann rha h ki nhi
            // kisi ek ko delete krke bann gya mtlb we succeded
            bool ansone=checkPalindrome(s,i+1,j);// isme 'i' wale ko delete kr diya i+1 kr diye toh i skip ho gya
            
            bool anstwo=checkPalindrome(s,i,j-1);// isme 'j' wale ko skip kr diye 
            bool finalans= ansone||anstwo;// dono mai se kisi bhi case mai agar bann gya mtlb palindrome bann skta h ek char delete krke
            return finalans;
        }
    }

}


int main()
{

    string s="abcdedecba";
    bool ans=validPalindrome(s);
    if(ans==1)
    {
        cout<<"palindrome bann skta h";
    }
    else
    {
        cout<<"palindrome nhi bann skta ek char delete krke";
    }


    return 0;
}