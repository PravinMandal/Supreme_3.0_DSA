//leetcode: 151. Reverse Words in a String
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;

        int i=0;
        int n=s.size();
        while(i < n) {
            while(i<n && s[i] == ' ') i++;
            if(i>=n) break;
            int start = i;
            while(i<n && s[i] != ' ') {
                i++;
            }
            st.push(s.substr(start, i-start));
        }

        string str = "";
        while(!st.empty()) {
            str += st.top();
            st.pop();
            if(!st.empty()) str.push_back(' ');
        }
        return str;
    }
};

class Solution2 {
public:
    string reverseWords(string str) {
        int i=0; 
        int s = 0;
        int e = 0;
        int n = str.size();
        reverse(str.begin(), str.end());
        while(i<n) {
            while(i<n && str[i] == ' ') i++;
            if(i == n) break;
            while(i<n && str[i] != ' ') {
                str[e++] = str[i++];
            }
            reverse(str.begin()+s, str.begin()+e);
            str[e++] = ' ';
            s = e;
        }
        str.resize(e-1);
        return str;
    }
};

int main() {
    Solution2 sol;

    // Hardcoded testcases
    cout << "Input: \"the sky is blue\" -> Output: " 
         << sol.reverseWords("the sky is blue") << endl;

    cout << "Input: \"  hello world  \" -> Output: " 
         << sol.reverseWords("  hello world  ") << endl;

    cout << "Input: \"a good   example\" -> Output: " 
         << sol.reverseWords("a good   example") << endl;

    return 0;
}
