//leetcode: 1910. Remove All Occurrences of a Substring
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) != s.npos) {
            s.erase(s.find(part), part.size());
        }
        return s;
    }
};

class Solution2 {
public:
    void removeOccRE(string& s, string& part) {
        if(s.find(part) != string::npos) {
            // 'part' exist krta hai s mai
            int foundIndex = s.find(part);
            string left = s.substr(0, foundIndex);
            string right = s.substr(foundIndex + part.size(), s.size());
            s = left + right;

            //direct erase bhi kr skte the
            // s.erase(s.find(part), part.size());

            removeOccRE(s, part);
        }
        else {
            return;
        }
    }
    string removeOccurrences(string s, string part) {
        removeOccRE(s, part);
        return s;
    }
};

int main() {
    Solution sol;

    // Hardcoded testcase
    string s = "daabcbaabcbc";
    string part = "abc";

    string result = sol.removeOccurrences(s, part);
    cout << "Result after removing occurrences: " << result << endl;

    return 0;
}
