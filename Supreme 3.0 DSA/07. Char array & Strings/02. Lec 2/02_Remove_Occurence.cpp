//isme hume kya krna h ki input mai string milega and ek pattern milega k length ka usse remove krna h main string se

#include<iostream>
using namespace std;

void removeOccurence(string full, string pattern)
{
    while(full.find(pattern) != string::npos) 
    //find function hume starting index deta h jise find krna hai
    //npos -1 deta h iska mtlb ki, As a return value, it is usually used to indicate no matches.
    {
        full.erase(full.find(pattern) , pattern.length());
    }


    int n= full.length();
    for(int i=0 ; i<n ; i++)
    {
        cout<<full[i]<<" ";
    }
}


int main()
{

    string full="daabcbaabcbc";
    string pattern="abc";
    removeOccurence(full,pattern);




    return 0;
}
