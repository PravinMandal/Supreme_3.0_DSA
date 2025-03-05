//gfg: set Kth bit
#include <iostream>
using namespace std;

class Solution {
public:
    int setKthBit(int n, int k) {
        //hume numeber aaya 10 uska binary 1010
        // Kth bit mtlb right se left mai Kth, is example mai k=2
        // 0 bit se chalu hota h toh k=2 bit mtlb right se 0 hai
        //toh usse 1 krna h
        // 1110 bann jayega
        
        int mask = 1 << k;
        int ans = n | mask;
        return ans;
        
        //mask = 100 bann gya
        //1010 ko 100 se | (or) kr diye toh wo 1110 bann gya
    }
};

int main() {
    Solution sol;
    int n = 10;  // Binary of 10: 1010
    int k = 2;   // k=2 (starting count from 0, rightmost bit is 0th)
    
    int result = sol.setKthBit(n, k);
    cout << "The result of setting " << k << "th bit of " << n << " is: " << result << endl;
    
    return 0;
}
