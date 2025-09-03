//gfg: Factorials of large numbers
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> factorial(int n) {
        vector<int> ans;
        ans.push_back(1);
        int carry = 0;
        
        for(int i=2; i<=n; i++) {
            for(int j=0; j<ans.size(); j++) {
                int x = ans[j]*i + carry;
                ans[j] = x%10;
                carry = x/10;
            }
            while(carry){
                ans.push_back(carry%10);
                carry /= 10;
            }
            carry = 0;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded testcase
    int n = 10; // Factorial of 10 = 3628800
    vector<int> result = sol.factorial(n);

    for(int digit : result) {
        cout << digit;
    }
    cout << endl;

    return 0;
}
