//gfg: Count the Reversals

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countMinReversals(string s) {
        //odd number of elements, mtlb pairs bann hi nhi skta 
        if(s.size() & 1) return -1;
        
        stack<char> st;
        for(char ch : s) {
            if(st.empty() || ch == '{') {
                st.push(ch);
            } else {
                // matlab ch == '}' hai;
                if(st.top() == '{') {
                    st.pop();
                }
                else {
                    st.push(ch);
                }
            }
        }
        
        int ans = 0;
        while(!st.empty()) {
            // do hi condition baachegi
            // {{, }} or,
            // }{
            //yahi ho skta hai stack mai
            
            char first = st.top(); st.pop();
            char second = st.top(); st.pop();
            // string total = {first, second};

            // if(total == "{{" || total == "}}") {
            //     //ek reverse krenge toh pair bann jayega
            //     ans++;
            // } else {
            //     //}{ , 2 reversal lagega
            //     ans += 2;
            // }

            // ✅ explanation: if both same (‘{{’ or ‘}}’) → 1 reversal,
            // otherwise (‘}{’) → 2 reversals required
            (first == second) ? ans += 1 : ans += 2;
        }
        return ans;
    }
};

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    // Hardcoded test cases
    vector<string> tests = {
        "}{{}}{{{",   // Expected output: 3
        "{{{{",       // Expected output: 2
        "{{{{}}",     // Expected output: 1
        "{{{{}}}}",   // Expected output: 0
        "}{}{}{",     // Expected output: 2
    };

    Solution sol;
    for (string s : tests) {
        cout << "Input: " << s << " -> Minimum reversals needed: " 
             << sol.countMinReversals(s) << endl;
    }

    return 0;
}
