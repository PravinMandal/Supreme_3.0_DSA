//leetcode: 125. Valid Palindrome
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(string& s, int i, int j) {
        if(i>=j) return true;

        bool ans = true;
        if(!isalnum(s[i])) {
            ans = solve(s, i+1, j);
        }
        else if(!isalnum(s[j])) {
            ans = solve(s, i, j-1);
        }
        else if(tolower(s[i]) != tolower(s[j])) {
            ans = false;
        } 
        else {
            ans = solve(s, i+1, j-1);
        }
        return ans;
    }
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;

        bool ans = solve(s, i, j);
        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded testcases
    string s1 = "A man, a plan, a canal: Panama";
    cout << (sol.isPalindrome(s1) ? "true" : "false") << endl;  // Expected: true

    string s2 = "race a car";
    cout << (sol.isPalindrome(s2) ? "true" : "false") << endl;  // Expected: false

    string s3 = " ";
    cout << (sol.isPalindrome(s3) ? "true" : "false") << endl;  // Expected: true

    return 0;
}
