//leetcode: 917. Reverse Only Letters

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution1 {
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

class Solution2 {
public:
    string reverseOnlyLetters(string s) {
        int i = 0;                  // left pointer starting from the beginning
        int j = s.size() - 1;       // right pointer starting from the end

        // run loop until two pointers meet or cross each other
        while(i <= j) {
            // checking whether character at i is NOT a letter
            // if it's not a letter, then simply move i forward
            // if((!(s[i] >= 'a' && s[i] <= 'z')) && (!(s[i] >= 'A' && s[i] <= 'Z'))) i++;
            // else if((!(s[j] >= 'a' && s[j] <= 'z')) && (!(s[j] >= 'A' && s[j] <= 'Z'))) j--;

            // simpler way using inbuilt function isalpha()
            if(!isalpha(s[i])) i++;        // if s[i] is not a letter, move i ahead
            else if(!isalpha(s[j])) j--;   // if s[j] is not a letter, move j back
            else {
                // if both s[i] and s[j] are letters, then swap them
                swap(s[i], s[j]);
                // after swapping, move both pointers
                i++;
                j--;
            }
        }
        return s;  // final string with only letters reversed
    }
};

// Driver code
int main() {
    string input = "a-bC-dEf-ghIj";
    
    Solution2 sol;
    string output = sol.reverseOnlyLetters(input);

    cout << "Original String: a-bC-dEf-ghIj" << endl;
    cout << "Reversed Letters: " << output << endl;

    return 0;
}
