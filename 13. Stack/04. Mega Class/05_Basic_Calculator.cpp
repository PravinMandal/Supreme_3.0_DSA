//leetcode: 224. Basic Calculator
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        int result = 0;
        int sign = 1;

        for(char ch:s) {
            if(ch>='0' && ch<='9') {
                num = num*10 + (ch-'0');
            }
            else if(ch == '+') {
                //ab tak ka sab sort krdo, mtlb iske pehle ke operation krdo, mtlb ab tak ka kaam khatam krdo
                result += sign*num;
                num = 0;
                sign = 1;
            }
            else if(ch == '-') {
                //ab tak ka sab sort krdo
                result += sign*num;
                num = 0;
                sign = -1;
            }
            else if(ch =='(') {
                //push the curr result and sign onto the stack
                st.push(result);
                st.push(sign); //ab tak ki expression ka ans store kr diya h
                result = 0;
                sign = 1;
            }
            else if(ch ==')') {
                //ab tak ka sort kro
                result += sign*num;
                num = 0;
                //pop the sign and result jo store hua tha
                sign = st.top();
                st.pop();
                result *= sign;
                result += st.top();
                st.pop();
                sign = 1;
            }
        }
        result += sign*num;//add the last remaining number to result
        return result;
    }
};

int main() {
    Solution sol;
    string s = "1 + (2 - (3 + (4 - 5)))";  // You can change this input as needed
    int result = sol.calculate(s);
    cout << "Result: " << result << endl;
    return 0;
}
