// isme hume kya krna h similar dhundna h
// for e.g: mee, gdd,vpp ....similar pattern
// e.g:  dad , gbg, mpm, zyz
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void normalise(string &str){

    char start='a';
    unordered_map<char,char> mapping;

    for(int i=0; i<str.length(); i++){
        char stringkacurrChar=str[i];
        if(mapping.find(stringkacurrChar)==mapping.end())
        {
            //yaha aa gya mtlb ye char pehle se map mai nhi h
            mapping[stringkacurrChar]=start;
            start++;
        }
    }
    //maine string ko normalize kr diya kahin na kahin map kr diya 


    for(int i=0; i<str.length(); i++){
        char mappedChar=mapping[str[i]];
        str[i]=mappedChar;
    }
    //yaha pr maine jo string aaya tha usko hi normalise kr diya / upadate kr diya

}

vector<string> FindAndReplacePattern(vector<string> &words , string pattern){
    vector<string> ans;
    //pattern ko normalise krdo 
    normalise(pattern);

    // let's traverse words --> normalise them --> check ki wo pattern ke equal h ki nhi
    for(int i=0 ; i< words.size(); i++){
        string currWord=words[i];
        normalise(currWord);
        if(currWord.compare(pattern)==0)
        {
            //if both normalise strings are equal then store kar lete h
            ans.push_back(words[i]);
        }

    }
    
    return ans;




}


int main(){

    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";

    vector<string> ans= FindAndReplacePattern(words, pattern);
    for(int i=0 ; i<ans.size() ; i++){
    cout<<"Similar strings to the pattern are: "<<ans[i]<<endl;

    }


    return 0;
}