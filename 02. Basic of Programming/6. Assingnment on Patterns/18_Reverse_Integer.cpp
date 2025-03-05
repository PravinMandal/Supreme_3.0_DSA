//leetcode: 7. Reverse Integers
#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int initialvalue = x;
        int ans = 0;
        int remainder;
        if(x <= INT_MIN ){
            return 0;
        }
        x = abs(x);
        while(x > 0) {
            if(ans > INT_MAX / 10) {
                return 0;
            }
            remainder = x % 10;
            ans = ans * 10 + remainder;
            x = x / 10;
        }

        if(initialvalue < 0 ) {
            return 0 - ans;
        }
        else {
            return ans;
        }
    }
};

int main() {
    Solution sol;
    
    // Test cases for reverse integer
    int x1 = 123;         // Expected output: 321
    int x2 = -123;        // Expected output: -321
    int x3 = 120;         // Expected output: 21
    int x4 = 1534236469;  // Expected output: 0 (overflow case)

    cout << "Reverse of " << x1 << " is: " << sol.reverse(x1) << endl;
    cout << "Reverse of " << x2 << " is: " << sol.reverse(x2) << endl;
    cout << "Reverse of " << x3 << " is: " << sol.reverse(x3) << endl;
    cout << "Reverse of " << x4 << " is: " << sol.reverse(x4) << endl;
    
    return 0;
}
