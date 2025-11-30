//leetcode: 921 - Minimum Add to Make Parentheses Valid

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;

        for(char ch : s) {

            if(ch == '(') {
                st.push('(');
            }
            else {
                // ch == ')'
                if(!st.empty() && st.top() == '(') {
                    st.pop();                    // valid pair mil gya
                }
                else {
                    st.push(')');                // extra ')' → push
                }
            }
        }

        return st.size(); // jitne unmatched brackets, utne add krne padenge
    }
};

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    Solution sol;

    // Hardcoded test cases
    vector<string> tests = {
        "())",        // Expected: 1
        "(((",        // Expected: 3
        "()()",       // Expected: 0
        "(()))(",     // Expected: 2
        ")(",         // Expected: 2
        ")",          // Expected: 1
    };

    for(string &t : tests) {
        cout << "Input: \"" << t 
             << "\" --> Output: " << sol.minAddToMakeValid(t) << endl;
    }

    return 0;
}
