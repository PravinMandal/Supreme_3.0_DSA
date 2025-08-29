//leetcode: 14. Longest Common Prefix
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int i=0;
        while(true) {
            char curr_ch = 0;
            for(string str : strs) {
                if(i >= str.size()) {
                    curr_ch = 0;
                    break;
                }
                if(curr_ch == 0) {
                    curr_ch = str[i];
                }
                if(str[i] != curr_ch) {
                    curr_ch = 0;
                    break;
                }
            }
            if(curr_ch == 0) {
                break;
            }
            ans.push_back(curr_ch);
            i++;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<string> strs1 = {"flower","flow","flight"};
    cout << "Longest Common Prefix: " << sol.longestCommonPrefix(strs1) << endl;

    // Example 2
    vector<string> strs2 = {"dog","racecar","car"};
    cout << "Longest Common Prefix: " << sol.longestCommonPrefix(strs2) << endl;

    // Example 3
    vector<string> strs3 = {"interspecies","interstellar","interstate"};
    cout << "Longest Common Prefix: " << sol.longestCommonPrefix(strs3) << endl;

    // Example 4
    vector<string> strs4 = {"a"};
    cout << "Longest Common Prefix: " << sol.longestCommonPrefix(strs4) << endl;

    return 0;
}
