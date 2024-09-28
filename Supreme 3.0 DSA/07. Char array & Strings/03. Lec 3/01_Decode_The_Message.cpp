#include<iostream>
#include<unordered_map>
using namespace std;
string DecodeTheMessage(string key, string message)
{
    unordered_map<char,char>mapping;
    char start='a';
    int index=0;
    char space=' ';
    mapping[space]=space;
    while(start<='z' && index<key.length())
    {
        char currentChar=key[index];
        if(mapping.find(currentChar) != mapping.end())
        {
            //mtlb ye wala char pehle se hi hai toh map nhi krna h
            index++;
        }
        else
        {
            mapping[currentChar]=start;
            index++;
            start++;
        }
    }


    string ans="";
    for(int i=0; i<message.length() ; i++)
    {
        
        char mappedChar=mapping[message[i]];
        ans.push_back(mappedChar);
    }

    return ans;

    
}


int main()
{
    string key="the quick brown fox jumps over the lazy dog";
    string message="vkbs bs t suepuv";
    string ans=DecodeTheMessage(key,message);
    cout<<"The message is: "<<ans<<endl;


    return 0;
}