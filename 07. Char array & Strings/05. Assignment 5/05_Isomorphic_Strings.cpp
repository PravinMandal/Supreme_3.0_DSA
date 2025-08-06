// leetcode: 205. Isomorphic Strings

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // Helper function to check one-way mapping
    bool mapping(string& s, string& t) {
        unordered_map<char, char> mapping;

        for(int i = 0; i < s.length(); i++) {
            if(mapping.count(s[i]) == 0) {
                mapping[s[i]] = t[i];  // create a mapping
            } else if(mapping[s[i]] != t[i]) {
                return false;  // mismatch in mapping
            }
        }
        return true;
    }

    // Main function to check if both strings are isomorphic
    bool isIsomorphic(string s, string t) {
        bool ans1 = mapping(s, t);
        bool ans2 = mapping(t, s);
        return (ans1 && ans2);
    }
};

int main() {
    Solution sol;

    // Sample testcases from Leetcode
    vector<pair<string, string>> testCases = {
        {"egg", "add"},      // true
        {"foo", "bar"},      // false
        {"paper", "title"},  // true
        {"badc", "baba"},    // false
        {"ab", "aa"},        // false
        {"", ""}             // true
    };

    for (auto& test : testCases) {
        string s = test.first;
        string t = test.second;
        bool result = sol.isIsomorphic(s, t);
        cout << "Input: s = \"" << s << "\", t = \"" << t << "\" => Output: " << (result ? "true" : "false") << endl;
    }

    return 0;
}
