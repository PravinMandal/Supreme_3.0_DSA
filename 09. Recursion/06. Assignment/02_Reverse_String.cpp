//leetcode: 344. Reverse String
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<char>& str, int s, int e) {
        if(s>=e) return;

        swap(str[s], str[e]);
        solve(str, s+1, e-1);
    }
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size()-1;
        solve(s, start, end);
    }
};

int main() {
    Solution sol;

    // Hardcoded testcases
    vector<char> s1 = {'h','e','l','l','o'};
    sol.reverseString(s1);
    for(char c : s1) cout << c;  
    cout << endl;  // Expected: "olleh"

    vector<char> s2 = {'H','a','n','n','a','h'};
    sol.reverseString(s2);
    for(char c : s2) cout << c;
    cout << endl;  // Expected: "hannaH"

    return 0;
}
