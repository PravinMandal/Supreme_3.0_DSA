//leetcode: 1047 - Remove All Adjacent Duplicates In String

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st; // Stack to hold characters as we process them
        string str;

        // Traverse each character in the string
        for (char ch : s) {
            // If stack is empty or top is not equal to current char → push it
            if (st.empty() || st.top() != ch) {
                st.push(ch);
            }
            else {
                // If top of stack equals current char, pop it (remove duplicate)
                st.pop();
            }
        }

        // Pop all remaining characters from stack to form the final string
        while (!st.empty()) {
            str.push_back(st.top());
            st.pop();
        }

        // Reverse to restore correct order (since stack reverses it)
        reverse(str.begin(), str.end());
        return str;
    }
};

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    // Hardcoded test case
    // Input: "abbaca"
    // Output: "ca" (because "abba" removes to "", leaving "ca")
    string input = "abbaca";
    
    Solution sol;
    string result = sol.removeDuplicates(input);
    
    cout << "Original String: " << input << endl;
    cout << "After Removing Adjacent Duplicates: " << result << endl;

    return 0;
}
