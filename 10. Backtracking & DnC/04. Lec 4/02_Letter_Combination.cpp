//leetcode:- 17. Letter Combinations of a Phone Number
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    void solve(string digits,vector<string>&ans, string& output, unordered_map<char,string>&mapping,int i){
    //base case
    if(i>=digits.length()){
        
        ans.push_back(output);
        
        return;
    }

    char digit=digits[i];
    string newstring=mapping[digit];

    for(char ch:newstring){
        output.push_back(ch);
        solve(digits,ans,output,mapping,i+1);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string output="";
        unordered_map<char,string> mapping;
        mapping['2'] = "abc";
        mapping['3'] = "def";
        mapping['4'] = "ghi";
        mapping['5'] = "jkl";
        mapping['6'] = "mno";
        mapping['7'] = "pqrs";
        mapping['8'] = "tuv";
        mapping['9'] = "wxyz";

        if(digits==output){
            return ans;
        }
        int i=0;

        solve(digits,ans,output,mapping,i);

        return ans;
    }
};

int main(){

Solution solution;
    string digits;

    cout << "Enter a digit string (2-9): ";
    cin >> digits;

    vector<string> combinations = solution.letterCombinations(digits);

    cout << "Letter combinations are:\n";
    for (const string& combination : combinations) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}