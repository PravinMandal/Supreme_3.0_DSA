//leetcode: 8. String to Integer (atoi)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int StringtoInt(string& s, int i) {
        long long int ans = 0;
        for(int j=i; j<s.length(); j++) {
            if(!(s[j] >= '0' && s[j] <= '9')) return ans;
            ans = ans * 10 + (s[j] - '0');
            if(ans > INT_MAX) return (long long)INT_MAX + 1;
        }
        return ans;
    }

    int myAtoi(string s) {
        long long int ans=0;
        bool isNeg = false;
        int i=0;

        while((!isalpha(s[i])) && (!(s[i] >= '0' && s[i] <= '9'))) {
            if((s[i] == '+') || (s[i] == '-')) {
                if(s[i] == '-') {
                    isNeg = true;
                }
                i++;
                break;
            }
            else if(s[i] == ' ') i++;
            else {
                return 0;
            }
        }
        ans = StringtoInt(s, i);
        if(isNeg) {
           ans = 0-ans;
        } 
        if(ans > INT_MAX) return INT_MAX;
        else if(ans < INT_MIN) return INT_MIN;
        else return ans;
    }
};

class Solution2 {
public:
    int myAtoi(string s) {
        int ans=0, i=0, sign=1;

        while(s[i] == ' ') i++;
        if(i<s.size() && (s[i] == '-' || s[i] == '+')) {
            sign = s[i] == '+' ? 1 : -1;
            i++;
        }
        while(i<s.size() && isdigit(s[i])) {
            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && s[i] > '7')) {
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            ans = ans * 10 + (s[i] - '0');
            i++;
        }
        return ans*sign;
    }
};


int main() {
    Solution2 sol;

    // Hardcoded testcases
    vector<string> testcases = {
        "42",              // normal number
        "   -42",          // with leading spaces and negative
        "4193 with words", // number followed by words
        "words and 987",   // invalid start
        "-91283472332",    // less than INT_MIN
        "91283472332",     // greater than INT_MAX
        "+1",              // positive sign
        "00000-42a1234"    // tricky case
    };

    for(string s : testcases) {
        cout << "Input: \"" << s << "\" -> Output: " << sol.myAtoi(s) << endl;
    }

    return 0;
}
