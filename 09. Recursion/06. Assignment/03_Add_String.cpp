//leetcode: 415. Add Strings
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(string& num1, string& num2, string& ans, int p1, int p2, int carry) {
        //base case
        if(p1 < 0 && p2 < 0 && carry == 0) return;

        int first = (p1 >= 0) ? num1[p1]-'0' : 0;
        int second = (p2 >= 0) ? num2[p2]-'0' : 0;
        int sum = first + second + carry;
        carry = sum/10;
        ans.push_back((sum%10)+'0');
        solve(num1, num2, ans, p1-1, p2-1, carry);
    }
    string addStrings(string num1, string num2) {
        int p1 = num1.size()-1;
        int p2 = num2.size()-1;
        int carry = 0;
        string ans = "";
        solve(num1, num2, ans, p1, p2, carry);
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
