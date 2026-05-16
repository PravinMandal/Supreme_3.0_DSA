//leetcode: 188. Best Time to Buy and Sell Stock IV

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveUsingRec(vector<int>& prices, int i, bool buy, int k) {
        if(i>=prices.size() || k==0) return 0; // Base case: no days left or no transactions left

        int profit = 0;

        if(buy) {

            // Option 1: Buy stock today
            int buyNow = -prices[i] + solveUsingRec(prices, i+1, 0, k);

            // Option 2: Skip buying
            int buyLater = solveUsingRec(prices, i+1, 1, k);

            profit = max(buyNow, buyLater);

        } else {

            // Option 1: Sell stock today
            // Transaction count decreases only after selling
            int sellNow = prices[i] + solveUsingRec(prices, i+1, 1, k-1);

            // Option 2: Skip selling
            int sellLater = solveUsingRec(prices, i+1, 0, k);

            profit = max(sellNow, sellLater);
        }

        return profit;
    }
    
    int solveUsingMem(vector<int>& prices, int i, bool buy, int k, vector<vector<vector<int>>>& dp) {
        if(i>=prices.size() || k==0) return 0; // Base case

        // Return memoized answer
        if(dp[i][buy][k] != -1) return dp[i][buy][k];

        int profit = 0;

        if(buy) {
            int buyNow = -prices[i] + solveUsingMem(prices, i+1, 0, k, dp);
            int buyLater = solveUsingMem(prices, i+1, 1, k, dp);
            profit = max(buyNow, buyLater);
        } else {
            int sellNow = prices[i] + solveUsingMem(prices, i+1, 1, k-1, dp);
            int sellLater = solveUsingMem(prices, i+1, 0, k, dp);
            profit = max(sellNow, sellLater);
        }

        dp[i][buy][k] = profit;

        return profit;
    }

    int solveUsingTab(vector<int>& prices, int K) {
        int n = prices.size();

        // dp[i][buy][k]
        // i = current day
        // buy = buying allowed or not
        // k = remaining transactions
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(K+1, 0)));

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                for(int k=1; k<=K; k++) {

                    int profit = 0;

                    if(buy) {
                        int buyNow = -prices[i] + dp[i+1][0][k];
                        int buyLater = dp[i+1][1][k];
                        profit = max(buyNow, buyLater);
                    } else {
                        int sellNow = prices[i] + dp[i+1][1][k-1];
                        int sellLater = dp[i+1][0][k];
                        profit = max(sellNow, sellLater);
                    }

                    dp[i][buy][k] = profit;
                }
            }
        }

        return dp[0][1][K];
    }
    
    int solveUsingTabSO(vector<int>& prices, int K) {
        int n = prices.size();

        // vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(K+1, 0)));

        // Space optimized DP
        vector<vector<int>> curr(2, vector<int>(K+1, 0));
        vector<vector<int>> prev(2, vector<int>(K+1, 0));

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                for(int k=1; k<=K; k++) {

                    int profit = 0;

                    if(buy) {
                        int buyNow = -prices[i] + prev[0][k];
                        int buyLater = prev[1][k];
                        profit = max(buyNow, buyLater);
                    } else {
                        int sellNow = prices[i] + prev[1][k-1];
                        int sellLater = prev[0][k];
                        profit = max(sellNow, sellLater);
                    }

                    curr[buy][k] = profit;
                }

                prev = curr;
            }
        }

        return prev[1][K];
    }


    int maxProfit(int k, vector<int>& prices) {
        // return solveUsingRec(prices, 0, 1, k);

        // vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k, -1)));
        // return solveUsingRec(prices, 0, 1, k);

        // return solveUsingTab(prices, k);
        return solveUsingTabSO(prices, k);
    }
};

int main() {
    Solution obj;

    // Hardcoded test cases
    vector<int> prices1 = {2, 4, 1};
    vector<int> prices2 = {3, 2, 6, 5, 0, 3};
    vector<int> prices3 = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};

    cout << "Test Case 1 Output: " << obj.maxProfit(2, prices1) << endl;
    cout << "Test Case 2 Output: " << obj.maxProfit(2, prices2) << endl;
    cout << "Test Case 3 Output: " << obj.maxProfit(3, prices3) << endl;

    return 0;
}