//leetcode:- 22. Generate Parentheses
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    void solve(vector<string>&ans,int open ,int close, string output, int n){
        //base case
        if(open+close==2*n){
            ans.push_back(output);
            return;
        }

        // open "(" utna hi kr skte h jitna bada n hai max utna hi kr skte h
        if(open<n){
            solve(ans,open+1,close,output+"(",n);
        }

        // close ")" isse hume restrict krna pdega toh open jitna rhega utna hi max close ho skta h warna close zyada ho gya toh correct nhi banega
        if(close<open){
            solve(ans,open,close+1,output+")",n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int open=0;
        int close=0;
        string output;
        solve(ans,open,close,output,n);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter the number of pairs of parentheses: ";
    cin >> n;

    Solution solution;  // Create an object of the Solution class
    vector<string> result = solution.generateParenthesis(n);  // Call the function

    cout << "Generated Parentheses Combinations:" << endl;
    for (const string& combination : result) {
        cout << combination << endl;
    }

    return 0;
}
