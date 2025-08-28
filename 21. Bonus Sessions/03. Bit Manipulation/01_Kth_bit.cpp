//gfg: Check whether K-th bit is set or not

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool checkKthBit(int n, int k) {
        int mask = 1<<k;
        int ans = n&mask;
        
        if(ans == 0) return false;
        else return true;
    }
};

int main() {
    // Hardcoded test cases instead of cin
    Solution obj;

    int n1 = 5, k1 = 0; // 5 in binary = 101, 0th bit is set
    cout << "checkKthBit(" << n1 << ", " << k1 << ") = " 
         << (obj.checkKthBit(n1, k1) ? "true" : "false") << endl;

    int n2 = 5, k2 = 1; // 5 in binary = 101, 1st bit is not set
    cout << "checkKthBit(" << n2 << ", " << k2 << ") = " 
         << (obj.checkKthBit(n2, k2) ? "true" : "false") << endl;

    int n3 = 8, k3 = 3; // 8 in binary = 1000, 3rd bit is set
    cout << "checkKthBit(" << n3 << ", " << k3 << ") = " 
         << (obj.checkKthBit(n3, k3) ? "true" : "false") << endl;

    return 0;
}
