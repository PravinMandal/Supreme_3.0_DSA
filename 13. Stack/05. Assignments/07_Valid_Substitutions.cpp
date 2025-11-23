//leetcode: 1003 - Check If Word Is Valid After Substitutions

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.length()%3 != 0) return 0;
        int j = s.size()/3;
        for(int i=0; i<j; i++) {
            int index = s.find("abc");
            if(index != -1) {
                s.erase(index, 3);
            } else {
                break;
            }
        }
        return (s.empty()) ? 1:0;
    }
};

class Solution2 {
public:
    bool isValid(string s) {
        if(s.size() == 0) return true;
        int index = s.find("abc");
        if(index != string::npos) {
            string left = s.substr(0, index);
            string right = s.substr(index+3, s.size());
            return isValid(left+right);
        }
        return false;
    }
};

class Solution3 {
public:
    bool isValid(string s) {
        if(s[0] != 'a') return false;
        stack<char> st;
        for(char ch : s) {
            if(ch == 'a') {
                st.push(ch);
            }
            else if (ch == 'b') {
                if(!st.empty() && st.top() == 'a') {
                    st.push(ch);
                } else return false;
            }
            else {
                //ch == 'c'
                if(!st.empty() && st.top() == 'b') {
                    st.pop();
                    if(!st.empty() && st.top() == 'a') {
                        st.pop();
                    }
                } else return false;
            }
        }
        return (st.empty()) ? true : false;
    }
};

// ---------------------- MAIN FUNCTION ----------------------
int main() {

    // Hardcoded test cases for demonstration
    vector<string> tests = {
        "abc",          // valid → true
        "aabcbc",       // valid → true (aabcbc → abc → "")
        "abcabc",       // valid → true
        "abccba",       // invalid → false
        "cababc",       // invalid → false
        "abcabcabc",    // valid → true
        "aabbcc"        // invalid → false
    };

    Solution3 sol;

    for(string s : tests) {
        cout << "Input: " << s
             << " -> Output: " << (sol.isValid(s) ? "true" : "false")
             << endl;
    }

    return 0;
}
