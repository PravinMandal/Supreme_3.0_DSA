//leetcode: 5 Longest Palindromic Substring
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPalindrome(string& s, int i, int j) {
        if(i >= j) return true;
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        string ans = "";
        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {
                if(checkPalindrome(s, i, j)) {
                    string t = s.substr(i, j - i + 1);
                    ans = t.size() > ans.size() ? t : ans;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded test cases
    vector<string> testCases = {
        "babad",   // expected: "bab" or "aba"
        "cbbd",    // expected: "bb"
        "a",       // expected: "a"
        "ac",      // expected: "a" or "c"
        "forgeeksskeegfor" // expected: "geeksskeeg"
    };

    for (string test : testCases) {
        cout << "Input: " << test << "\n";
        cout << "Longest Palindromic Substring: " 
             << sol.longestPalindrome(test) << "\n\n";
    }

    return 0;
}
