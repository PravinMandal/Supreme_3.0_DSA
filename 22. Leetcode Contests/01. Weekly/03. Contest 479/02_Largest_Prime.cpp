//leetcode (contest) - Largest Prime Reachable by Prime Summation
//Q2. Largest Prime from Consecutive Prime Sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPrime(int n) {
        vector<bool> isPrime(n+1, true);
        isPrime[0] = isPrime[1] = false;

        // Sieve of Eratosthenes to mark primes
        for(int i=2; i*i <= n; i++) {
            if(isPrime[i]) {
                for(int j = i*i; j<=n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int ans = 0;
        int sum = 0;
        int i = 0;

        // keep adding primes & check if sum itself becomes prime
        while(i <= n) {
            if(isPrime[i] == true && sum + i <= n) { 
                sum += i;
                if(sum > n) break;

                if(isPrime[sum]) ans = sum;  // update whenever sum is prime
            }
            i++;
        }
        return ans;
    }
};

// ---------------------- MAIN FUNCTION (HARDCODED TESTING) ----------------------
int main() {
    Solution sol;

    // Hardcoded test cases
    cout << sol.largestPrime(10) << endl;   // Example: primes = 2,3,5 → sum becomes 5
    cout << sol.largestPrime(50) << endl;   // Expected some valid prime sum
    cout << sol.largestPrime(100) << endl;  // Try a bigger range
    cout << sol.largestPrime(5) << endl;    // small input case

    return 0;
}
