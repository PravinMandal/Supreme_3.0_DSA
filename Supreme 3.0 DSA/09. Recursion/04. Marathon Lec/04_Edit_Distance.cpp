//very important
//leetcode 72. Edit Distance
//Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
// You have the following three operations permitted on a word:
// Insert a character
// Delete a character
// Replace a character

#include<iostream>
using namespace std;

int minDistance(string& a,string& b,int i,int j){
    //base case
    if(i>=a.length()){
        //word1 wali string end ho gyi
        //yani word1 ki length may be word2 se chhoti h
        return b.length() - j;
    }
    else if(j>=b.length()){
        //word2 wali string end ho gyi
        //yaani word1 ki length may be greater ho word2 se 
        return a.length() - i;
    }

    int ans=0;
    if(a[i]==b[j]){
        //match
        ans=0+minDistance(a,b,i+1,j+1);
    }
    else{
        //not match
        //operations perform kro

        //insert
        int option1=1+minDistance(a,b,i,j+1);

        //remove
        int option2=1+minDistance(a,b,i+1,j);

        //replace
        int option3=1+minDistance(a,b,i+1,j+1);

        ans=min(option1,min(option2,option3));


    }
    return ans;
}
int main(){

    string word1="horse";
    string word2="ros";
    int i=0;
    int j=0;
    int ans=minDistance(word1,word2,i,j);
    cout<<ans;
    return 0;
}
