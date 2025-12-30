//leetcode: 29 Divide Two Integers

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case when dividing INT_MIN by -1
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Convert both numbers to positive long values to avoid overflow
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;

        // Determine the sign of the final result
        int sign = (divisor > 0) ^ (dividend > 0) ? -1 : 1;

        // Repeatedly subtract the largest shifted divisor possible
        while(dvd >= dvs) {
            long temp = dvs, m = 1;

            // Find the largest multiple of divisor (using left shifts)
            // that can be subtracted from dividend
            while((temp << 1) <= dvd) {
                temp <<= 1;
                m <<= 1;
            }

            // Subtract the found multiple and add to answer
            dvd -= temp;
            ans += m;
        }

        // Apply sign and return the final quotient
        return ans * sign;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case 1
    int dividend1 = 10;
    int divisor1 = 3;
    cout << "Result of " << dividend1 << " / " << divisor1 << " = "
         << sol.divide(dividend1, divisor1) << endl;

    // Hardcoded test case 2
    int dividend2 = 7;
    int divisor2 = -3;
    cout << "Result of " << dividend2 << " / " << divisor2 << " = "
         << sol.divide(dividend2, divisor2) << endl;

    // Hardcoded test case 3 (edge case)
    int dividend3 = INT_MIN;
    int divisor3 = -1;
    cout << "Result of " << dividend3 << " / " << divisor3 << " = "
         << sol.divide(dividend3, divisor3) << endl;

    return 0;
}
