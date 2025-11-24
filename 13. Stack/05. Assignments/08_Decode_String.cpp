//leetcode: 394 - Decode String

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        for(char ch : s) {
            if(ch != ']') {
                //num, char or '[' hi hoga
                st.push(ch);
            }
            else {
                //']' hai

                // Step 1: Extract substring inside brackets
                string str = "";
                while(st.top() != '[') {
                    str.push_back(st.top());
                    st.pop();
                }
                st.pop(); //'['
                reverse(str.begin(), str.end()); //string bhi sidha ho gya

                // Step 2: Extract the number before '['
                string num = "";
                while(!st.empty() && isdigit(st.top())) {
                    num.push_back(st.top());
                    st.pop();
                }
                reverse(num.begin(), num.end());
                int n = stoi(num); //number of time jo repeat krna hai
                
                // Step 3: Repeat the substring n times
                string temp = "";
                for(int i=0; i<n; i++) {
                    temp = temp + str;
                }

                // Step 4: Push expanded substring back into stack
                for(char chh : temp) {
                    st.push(chh);
                }
            }
        }

        // Step 5: Construct final answer by unloading the stack
        string ans = "";
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// ---------------------- MAIN FUNCTION ----------------------
int main() {

    Solution sol;

    // Hardcoded test cases
    vector<string> tests = {
        "3[a]2[bc]",        // "aaabcbc"
        "3[a2[c]]",         // "accaccacc"
        "2[abc]3[cd]ef",    // "abcabccdcdcdef"
        "10[a]",            // "aaaaaaaaaa"
        "3[z]2[2[y]pq]"     // "zzzyypqyypq"
    };

    for(string s : tests) {
        cout << "Input: " << s 
             << " → Output: " << sol.decodeString(s) << endl;
    }

    return 0;
}
