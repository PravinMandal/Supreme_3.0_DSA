//leetcode: 917. Reverse Only Letters

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        stack<char> st;

        // Push only letters into the stack
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                st.push(ch);
            }
        }

        // Replace letters in string with top of stack
        for(int i = 0; i < s.length(); i++) {
            if(!st.empty()) {
                char ch = st.top();
                if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                    st.pop();
                    s[i] = ch;
                }
            }
        }

        return s;
    }
};

// Driver code
int main() {
    string input = "a-bC-dEf-ghIj";
    
    Solution sol;
    string output = sol.reverseOnlyLetters(input);

    cout << "Original String: a-bC-dEf-ghIj" << endl;
    cout << "Reversed Letters: " << output << endl;

    return 0;
}
