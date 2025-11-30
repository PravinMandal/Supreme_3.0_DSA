//leetcode: 32 - Longest Valid Parentheses

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);  // starting base index

        int maxLen = 0;

        for(int i=0; i<s.size(); i++) {
            char ch = s[i];

            if(ch == '(') {
                st.push(i);      // push index of '('
            }
            else {
                // ch == ')'
                st.pop();        // try matching with previous '('

                if(st.empty()) {
                    // jaise koi galat ')' aaya, -1 ko pop kr dega → empty ho jayega
                    // toh ab yaha se new base index push krna hoga
                    st.push(i);
                }
                else {
                    // valid substring mil chuki → length calculate
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    Solution sol;

    // Hardcoded test cases
    vector<string> tests = {
        "(()",        // Expected: 2
        ")()())",     // Expected: 4
        "",           // Expected: 0
        "())((())",   // Expected: 4
        "()(()",      // Expected: 2
        "((()))",     // Expected: 6
        ")()())()()(", // Expected: 4
    };

    for(string s : tests) {
        cout << "Input: \"" << s 
             << "\" --> Output: " << sol.longestValidParentheses(s) << endl;
    }

    return 0;
}
