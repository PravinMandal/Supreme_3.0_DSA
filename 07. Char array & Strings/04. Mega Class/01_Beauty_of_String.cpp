//leetcode: 1781. Sum of Beauty of All Substrings
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int beauty = 0;
        unordered_map<char, int> freq;

        for(int i=0; i<s.size(); i++) {
            freq.clear();
            for(int j=i; j<s.size(); j++) {
                freq[s[j]]++;
                int mostFreq = INT_MIN;
                int leastFreq = INT_MAX;
                for(auto it : freq) {
                    mostFreq = max(mostFreq, it.second);
                    leastFreq = min(leastFreq, it.second);
                }
                beauty += mostFreq - leastFreq;
            }
        }
        return beauty;
    }
};

int main() {
    Solution sol;

    // Hardcoded testcases
    cout << "Input: \"aabcb\" -> Output: " << sol.beautySum("aabcb") << endl;
    cout << "Input: \"aabcbaa\" -> Output: " << sol.beautySum("aabcbaa") << endl;
    cout << "Input: \"xyz\" -> Output: " << sol.beautySum("xyz") << endl;
    cout << "Input: \"aaa\" -> Output: " << sol.beautySum("aaa") << endl;

    return 0;
}
