#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solveUsingRec(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;

        int ans = solveUsingRec(n-1) + solveUsingRec(n-2);
        return ans;
    }

    //Now lets solve using DP
    //1D dp array banakr usme ans store krlo
    int solveUsingDP(int n, vector<int>& ans) {
        if(n == 0) return 0;
        if(n == 1) return 1;

        //if ans pehle se hai then aage extra process mt kro and return krdo
        if(ans[n] != -1) {
            return ans[n];
        }

        ans[n] = solveUsingDP(n-1, ans) + solveUsingDP(n-2, ans);
        return ans[n];
    }

    int solveUsingTabulation(int n) {
        //step 1: Create a dp array
        vector<int> dp(n+1, -1);
        
        //step 2: analyze base case and update dp array
        dp[0] = 0;
        //agar n == 0 hai mtlb array 1 dabbe ka banega mtlb bss dp[0] ke liye
        //aur iske baad hi hum dp[1] ko access kr rhe h, toh code fat jayega
        //isiye ye condition lagaya
        if(n == 0) return 0;
        dp[1] = 1;

        //check the parameters and reverse it and run a loop 
        //recursion : n->0
        //reverse: 0->n

        for(int i=2; i<=n; i++) {
            //copy paste
            dp[i] = dp[i-1] + dp[i-2];
        }
        //answer return
        return dp[n];
    }

    int solveUsingTabSpaceOptimized(int n) {
        //step 1: Create a dp array
        // vector<int> dp(n+1, -1);
        
        //step 2: analyze base case and update dp array
        if(n == 0) return 0;
        if(n == 1) return 1;
        // dp[0] = 0;
        //agar n == 0 hai mtlb array 1 dabbe ka banega mtlb bss dp[0] ke liye
        //aur iske baad hi hum dp[1] ko access kr rhe h, toh code fat jayega
        //isiye ye condition lagaya
        // dp[1] = 1;
        int prev = 0;
        int curr = 1;
        //check the parameters and reverse it and run a loop 
        //recursion : n->0
        //reverse: 0->n

        for(int i=2; i<=n; i++) {
            int ans = prev + curr;
            prev = curr;
            curr = ans;
        }
        //answer return
        return curr;
    }

    int fib(int n) {
        // vector<int> ans(n+1, -1);
        // int ans = solveUsingRec(n);
        // int DPans = solveUsingDP(n, ans);
        // return solveUsingTabulation(n);
        return solveUsingTabSpaceOptimized(n);
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter n (to find nth Fibonacci number): ";
    cin >> n;

    cout << "Fibonacci number at position " << n << " is: " << sol.fib(n) << endl;

    return 0;
}
