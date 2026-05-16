//leetcode: 309. Best Time to Buy and Sell Stock with Cooldown

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
            // After selling, one cooldown day, so move to i+2
            int profit1 = prices[i] + solveUsingRec(prices, i+2, 1);

            // Option 2: Skip selling
            int profit2 = 0 + solveUsingRec(prices, i+1, 0);

            profit = max(profit1, profit2);
        }

        return profit;
    }
    
    int solveUsingMem(vector<int>& prices, int i, int buy, vector<vector<int>>& dp) {
        if(i>=prices.size()) return 0; // Base case

        // Return memoized result
        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;

        if(buy) {
            //buy

            int profit1 = -prices[i] + solveUsingMem(prices, i+1, 0, dp);
            int profit2 = 0 + solveUsingMem(prices, i+1, 1, dp);

            profit = max(profit1, profit2);

        } else {
            //sell

            int profit1 = prices[i] + solveUsingMem(prices, i+2, 1, dp);
            int profit2 = 0 + solveUsingMem(prices, i+1, 0, dp);

            profit = max(profit1, profit2);
        }

        dp[i][buy] = profit;

        return profit;
    }

    int solveUsingTab(vector<int>& prices) {

        // Extra size +2 because selling accesses i+2
        vector<vector<int>> dp(prices.size()+2, vector<int> (2, 0));

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

                    int profit1 = prices[i] + dp[i+2][1];
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
        vector<int> prevPlus(2, 0);

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

                    // prevPlus stores state for i+2 because of cooldown
                    int profit1 = prices[i] + prevPlus[1];
                    int profit2 = 0 + prev[0];

                    profit = max(profit1, profit2);
                }

                curr[buy] = profit;
            }

            //shifting
            prevPlus = prev;
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
    vector<int> prices1 = {1, 2, 3, 0, 2};
    vector<int> prices2 = {1};
    vector<int> prices3 = {6, 1, 3, 2, 4, 7};

    cout << "Test Case 1 Output: " << obj.maxProfit(prices1) << endl;
    cout << "Test Case 2 Output: " << obj.maxProfit(prices2) << endl;
    cout << "Test Case 3 Output: " << obj.maxProfit(prices3) << endl;

    return 0;
}