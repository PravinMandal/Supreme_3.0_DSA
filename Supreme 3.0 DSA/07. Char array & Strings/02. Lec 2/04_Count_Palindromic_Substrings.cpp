// isme hume number of palindrome substring find krne hai
// ek string diya rhega uske andar kitne possible palindrome banenge
#include<iostream>
using namespace std;

int expandAroundCentre(string s,int i,int j)
{
    int count=0;
    while(s[i]==s[j] && i>=0 && j<s.length())
    {
        count++;
        i--;
        j++;
    }
    return count;
}


int countSubstring(string s)
{
    int totalcount=0;
    for(int centre=0 ; centre<s.length() ; centre++ )
    {
        //odd
        int i=centre;
        int j=centre;
        int oddPalSubStringkaCount=expandAroundCentre(s,i,j);
        //even
        i=centre;
        j=centre+1;
        int evenPalSubStringkaCount=expandAroundCentre(s,i,j);
        totalcount=totalcount+oddPalSubStringkaCount+evenPalSubStringkaCount;
    }
    return totalcount;
}


int main()
{   
    string s="babbar";
    int ans=countSubstring(s);
    cout<<"Number of palindrome Substring: "<<ans;
    


    return 0;
}