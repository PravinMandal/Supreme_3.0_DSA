//leetcode: 375. Guess Number Higher or Lower II
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int solveUsingRec(int s, int e) {
        //base case
        if(s>=e) return 0;
        
        int ans = INT_MAX;
        for(int i=s; i<e; i++) {
            ans = min(ans, max(i+solveUsingRec(s, i-1), i+solveUsingRec(i+1, e)));
        }
        return ans;
    }

    //Memoisation
    int solveUsingMem(int s, int e, vector<vector<int>>& dp) {
        //base case
        if(s>=e) return 0;

        if(dp[s][e] != -1) {
            return dp[s][e];
        }

        int ans = INT_MAX;
        for(int i=s; i<e; i++) {
            ans = min(ans, i+ max(solveUsingMem(s, i-1, dp),solveUsingMem(i+1, e, dp)));
        }
        dp[s][e] = ans;
        return dp[s][e];
    }

    //tabulation
    int solveUsingTab(int n) {
        vector<vector<int>> dp(n+10, vector<int>(n+10, 0));

        for(int s=n; s>=1; s--) {
            for(int e=s; e<=n; e++) {
                if(s>=e) {
                    continue;
                }
                else{
                    int ans = INT_MAX;
                    for(int i=s; i<e; i++) {
                        ans = min(ans, i+max(dp[s][i-1], dp[i+1][e]));
                    }
                    dp[s][e] = ans;
                }
                
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        //rec
        // int ans = solveUsingRec(1,n);

        //Memoisation
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // int ans = solveUsingMem(1,n, dp);

        //Tabulation
        int ans = solveUsingTab(n);

        return ans;
    }
};

int main() {
    Solution s;
    int n = 10; // you can change this value to test other inputs
    cout << "Minimum amount of money required to guarantee a win from 1 to " << n << ": " << s.getMoneyAmount(n) << endl;
    return 0;
}
