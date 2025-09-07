//contest:  Minimum Operations to Transform String
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAlll_a(string& s) {
        for(int i=0; i<s.size(); i++) {
            if(s[i] != 'a') {
                return false;
            }
        }
        return true;
    }

    int minOperations(string s) {
        bool isAll_a = isAlll_a(s);
        if(isAll_a == true) return 0;

        sort(s.begin(), s.end());
        int ans = 0;
        char prev;
        int j = 0;

        for(int i=0; i<s.size(); i++) {
            if(s[i] != 'a') {
                prev = s[i];
                j = i;
                break;
            }
        }

        for(int i=j+1; i<s.size(); i++) {
            while(i<=s.size() && s[i] == 'a') {
                i++;
            }
            if(i<=s.size()) {
                int oper = s[i] - prev;
                ans += oper;
                prev = s[i];
            }
        }

        int finalAns = ans + (123-(s[s.size()-1]));
        return finalAns;
    }
};

class Solution2 {
public:
    int minOperations(string s) {
        if(s.size() == 1 && s[0] == 'a') return 0;
        char mini = 'z';
        for(char ch : s) {
            if(ch != 'a') {
                mini = min(mini, ch); 
            }
        }
        // 123 -> Ascii value of z+1;
        // return 123 - mini;

        return 'z'+1 - mini;
    }
};

int main() {
    Solution sol;
    Solution2 sol2;

    // Hardcoded testcases
    cout << sol.minOperations("abc") << endl;   // Example test
    cout << sol.minOperations("aaa") << endl;   // Expected 0
    cout << sol.minOperations("azc") << endl;   // Example test

    cout << sol2.minOperations("abc") << endl;  // Example test
    cout << sol2.minOperations("a") << endl;    // Expected 0
    cout << sol2.minOperations("b") << endl;    // Example test

    return 0;
}
