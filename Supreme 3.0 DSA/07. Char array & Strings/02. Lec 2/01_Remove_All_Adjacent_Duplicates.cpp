#include<iostream>
using namespace std;
void removeDuplicate(string &s)
{
    string ans="";
    int len=s.length();
    for(int i=0; i<len ; i++)
    {
        int currentChar=s[i];
        if(ans.empty())
        {
            ans.push_back(currentChar);
        }
        else if(currentChar==ans.back())
        {
            ans.pop_back();
        }
        else if(currentChar!= ans.back())
        {
            ans.push_back(currentChar);
        }
    }

    int n=ans.length();
    for(int i=0 ; i<n ; i++)
    {
        cout<<ans[i]<<" ";
    }

}



int main()
{
    string s="abbaca";
    removeDuplicate(s);
    

    return 0;
}