//leetcode: 76 Minimum Window Substring

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) return ""; // no ans

        // in dono ka use krke, substr se mai ans string return kr skta hu
        int ansIndex = -1;
        int ansLen = INT_MAX;

        //below 2 map reflect the current windows of the string s
        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;

        for(char ch : t) {
            tMap[ch]++;
        }

        int start = 0;
        int end = 0;
        int count = 0; //count tracks total matched character in the window

        while(end < s.length()) {
            char ch = s[end];
            //update krna h sMap me, kyuki sMap "s" wali string
            //ki window mai kon kon se char hai unko track krne ke liye banaya h
            sMap[ch]++;

            //possibility hai ki ye char "t" ke andar ho ya na ho
            //agar ye char t string mai bhi hai,
            //toh isko matched char ke andar count krna hoga
            if(sMap[ch] <= tMap[ch]) {
                count++;
            }

            //ab ye bhi ho skta h ki count i.e. total number of matched char exactly
            // "t" ke length ke equal ho
            //iska mtlb ek aisi window mil gyi jisme "t" ke saare char present hai
            if(count == t.length()) {
                //ab minimize krna h

                while(sMap[s[start]] > tMap[s[start]]) {
                    sMap[s[start]]--;
                    start++;
                }
                //ans store
                int windowKiLength = end-start+1;
                if(windowKiLength < ansLen) {
                    ansLen = windowKiLength;
                    ansIndex = start;
                }
            }
            //jab valid ans nhi milta toh expand krte hai
            end++;
        }

        if(ansIndex == -1) return "";
        else return s.substr(ansIndex, ansLen);
    }
};

int main() {
    // Hardcoded test case instead of cin
    string s = "ADOBECODEBANC";
    string t = "ABC";

    Solution obj;
    string result = obj.minWindow(s, t);

    cout << "Minimum window substring = " << result << endl;

    return 0;
}
