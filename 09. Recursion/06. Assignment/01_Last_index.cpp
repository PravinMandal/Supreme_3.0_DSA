// GFG : Last index of a character in the string
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(string s, char p, int i) {
        if(i < 0) return -1;
        
        if(s[i] == p) return i;
        int ans = solve(s, p, i-1);
        return ans;
    }

    int LastIndex(string s, char p) {
        int i = s.size()-1;
        int index = solve(s, p, i);
        return index;
    }
};

int main() {
    Solution sol;

    // Hardcoded testcases
    string s1 = "abcdbc";
    char p1 = 'b';
    cout << sol.LastIndex(s1, p1) << endl;  // Expected: 4

    string s2 = "aaaaa";
    char p2 = 'a';
    cout << sol.LastIndex(s2, p2) << endl;  // Expected: 4

    string s3 = "xyz";
    char p3 = 'a';
    cout << sol.LastIndex(s3, p3) << endl;  // Expected: -1

    return 0;
}
