//leetcode: 415. Add Strings
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(string& num1, string& num2, int& carry, string& ans, int i) {
        if((i>=num1.size()) && (i>=num2.size() && carry==0)) return;

        int numof1 = i<num1.size() ? num1[i]-'0' : 0;
        int numof2 = i<num2.size() ? num2[i]-'0' : 0;
        int sum = numof1 + numof2 + carry;
        ans.push_back((sum%10)+'0');
        carry = sum/10;
        solve(num1, num2, carry, ans, i+1);
    }
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0;
        int i=0;
        string ans = "";
        solve(num1, num2, carry, ans, i);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded testcases
    string num1 = "456", num2 = "77";
    cout << sol.addStrings(num1, num2) << endl;  // Expected: 533

    string num3 = "0", num4 = "0";
    cout << sol.addStrings(num3, num4) << endl;  // Expected: 0

    string num5 = "999", num6 = "999";
    cout << sol.addStrings(num5, num6) << endl;  // Expected: 1998

    return 0;
}
