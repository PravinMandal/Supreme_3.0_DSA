//leetcode: 28. Find the Index of the First Occurrence in a String
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string haystack, string needle) {
        int index = -1;
        for(int i=0; i<haystack.length(); i++) {
            int j = i;
            while(haystack[j++] == needle[++index]) {
                if(index == needle.size() -1) {
                    return i;
                }
            }
            index = -1;
        }
        return index;
    }
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size()) return -1;
        int ans = solve(haystack, needle);
        return ans;
    }
};

int main() {
    Solution obj;

    // hardcoded testcase
    string haystack = "sadbutsad";
    string needle = "sad";

    int result = obj.strStr(haystack, needle);
    cout << "The first occurrence of \"" << needle << "\" in \"" 
         << haystack << "\" is at index: " << result << endl;

    return 0;
}
