//leetcode: 242. Valid Anagram

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, int> freq; // to store frequency of characters
        
        for(int i = 0; i < s.length(); i++) {
            freq[s[i]]++; // increment frequency for s
            freq[t[i]]--; // decrement frequency for t
        }

        // check if all frequencies are zero
        for(pair<char, int> i : freq) {
            if(i.second != 0) return false;
        }

        return true; // strings are anagrams
    }
};

// Driver code
int main() {
    string s = "anagram";
    string t = "nagaram";

    Solution sol;
    bool result = sol.isAnagram(s, t);

    if(result)
        cout << "The strings are anagrams." << endl;
    else
        cout << "The strings are NOT anagrams." << endl;

    return 0;
}
