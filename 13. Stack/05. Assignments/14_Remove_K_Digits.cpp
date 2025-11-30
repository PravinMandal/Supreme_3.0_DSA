//leetcode: 402 - Remove K Digits

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length() <= k) return "0";  // if digits ≤ k → whole number removed

        stack<char> st;
        string ans = "";

        for(char ch : num) {
            // Remove digits from stack while they are greater than current digit
            // This ensures smallest possible number (monotonic stack)
            while(!st.empty() && st.top() > ch && k > 0 ) {
                st.pop();
                k--;
            }
            st.push(ch);
        }

        // k abhi bhi bacha reh gya
        while(k--) {
            st.pop();
        }

        // Build final answer from stack
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        int i = 0;
        while(i < ans.size() && ans[i] == '0') {
            i++;
        }
        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    Solution sol;

    // Hardcoded test cases
    vector<pair<string,int>> tests = {
        {"1432219", 3},   // Expected: "1219"
        {"10200", 1},     // Expected: "200"
        {"10", 2},        // Expected: "0"
        {"123456", 3},    // Expected: "123"
        {"7654321", 3}    // Expected: "4321"
    };

    for(auto &t : tests) {
        cout << "Input: num = " << t.first << ", k = " << t.second 
             << " --> Output: " << sol.removeKdigits(t.first, t.second) << endl;
    }

    return 0;
}
