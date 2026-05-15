//leetcode: 122. Best Time to Buy and Sell Stock II

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solveUsingRec(vector<int>& prices, int i, int buy) {
        if(i>=prices.size()) return 0; // Base case: no days left

        int profit = 0;

        if(buy) {
            //buy

            // Option 1: Buy stock today
            int profit1 = -prices[i] + solveUsingRec(prices, i+1, 0);

            // Option 2: Skip buying
            int profit2 = 0 + solveUsingRec(prices, i+1, 1);

            profit = max(profit1, profit2);

        } else {
            //sell

            // Option 1: Sell stock today
            int profit1 = prices[i] + solveUsingRec(prices, i+1, 1);

            // Option 2: Skip selling
            int profit2 = 0 + solveUsingRec(prices, i+1, 0);

            profit = max(profit1, profit2);
        }

        return profit;
    }
    
    int solveUsingMem(vector<int>& prices, int i, int buy, vector<vector<int>>& dp) {
        if(i>=prices.size()) return 0;

        // Return cached result
        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;

        if(buy) {
            //buy

            int profit1 = -prices[i] + solveUsingMem(prices, i+1, 0, dp);
            int profit2 = 0 + solveUsingMem(prices, i+1, 1, dp);

            profit = max(profit1, profit2);

        } else {
            //sell

            int profit1 = prices[i] + solveUsingMem(prices, i+1, 1, dp);
            int profit2 = 0 + solveUsingMem(prices, i+1, 0, dp);

            profit = max(profit1, profit2);
        }

        dp[i][buy] = profit;

        return profit;
    }

    int solveUsingTab(vector<int>& prices) {

        // dp[i][buy] = max profit from day i with buy/sell state
        vector<vector<int>> dp(prices.size()+1, vector<int> (2, 0));

        for(int i=prices.size()-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {

                int profit = 0;

                if(buy) {
                    //buy

                    int profit1 = -prices[i] + dp[i+1][0];
                    int profit2 = 0 + dp[i+1][1];

                    profit = max(profit1, profit2);

                } else {
                    //sell

                    int profit1 = prices[i] + dp[i+1][1];
                    int profit2 = 0 + dp[i+1][0];

                    profit = max(profit1, profit2);
                }

                dp[i][buy] = profit;
            }
        }

        return dp[0][1];
    }
    
    int solveUsingTabSO(vector<int>& prices) {

        // vector<vector<int>> dp(prices.size()+1, vector<int> (2, 0));

        // Space optimized DP
        vector<int> curr(2, 0);
        vector<int> prev(2, 0);

        for(int i=prices.size()-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {

                int profit = 0;

                if(buy) {
                    //buy

                    int profit1 = -prices[i] + prev[0];
                    int profit2 = 0 + prev[1];

                    profit = max(profit1, profit2);

                } else {
                    //sell

                    int profit1 = prices[i] + prev[1];
                    int profit2 = 0 + prev[0];

                    profit = max(profit1, profit2);
                }

                curr[buy] = profit;
            }

            //shifting
            prev = curr;
        }

        return prev[1];
    }
    
    
    int maxProfit(vector<int>& prices) {
        // return solveUsingRec(prices, 0, true);

        // vector<vector<int>> dp(prices.size()+1, vector<int> (2, -1));
        // return solveUsingMem(prices, 0, true, dp);

        // return solveUsingTab(prices);
        return solveUsingTabSO(prices);
    }
};

int main() {

    Solution obj;

    // Hardcoded test cases
    vector<int> prices1 = {7,1,5,3,6,4};
    vector<int> prices2 = {1,2,3,4,5};
    vector<int> prices3 = {7,6,4,3,1};

    cout << "Test Case 1 Output: " << obj.maxProfit(prices1) << endl;
    cout << "Test Case 2 Output: " << obj.maxProfit(prices2) << endl;
    cout << "Test Case 3 Output: " << obj.maxProfit(prices3) << endl;

    return 0;
}