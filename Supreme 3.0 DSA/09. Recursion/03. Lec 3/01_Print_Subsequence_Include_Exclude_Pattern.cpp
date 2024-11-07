// include/ exclude boht boht boht zyada important hai 
// 10 baar dry run kro

#include<iostream>
#include<vector>
using namespace std;

void printSubSequence(string str,int i, string output , vector<string>&ans){

    //base case
    if(i==str.length()){
        //perticular include exclude ke last tk pohoch gye h , ab jo h output string mai usse store krlo
        ans.push_back(output);
        return;
    }

    char ch=str[i];
    //include

    printSubSequence(str,i+1,output+ch,ans);


    //exclude

    printSubSequence(str,i+1,output,ans);



}


int main(){

    string str="abc";
    string output="";
    int index=0;
    vector<string>ans;

    printSubSequence(str,index,output,ans);

    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i]<<endl;
    }



    return 0;
}