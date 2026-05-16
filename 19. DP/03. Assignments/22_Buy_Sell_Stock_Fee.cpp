//leetcode: 714. Best Time to Buy and Sell Stock with Transaction Fee

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveUsingRec(vector<int>& prices, int i, int buy, int& fee) {
        if(i>=prices.size()) return 0; // Base case: no days left

        int profit = 0;

        if(buy) {

            // Option 1: Buy stock today
            // Fee is paid while buying in this implementation
            int buyNow = -(prices[i] + fee) + solveUsingRec(prices, i+1, 0, fee);

            // Option 2: Skip buying
            int buyLater = solveUsingRec(prices, i+1, 1, fee);

            profit = max(buyNow, buyLater);

        } else {

            // Option 1: Sell stock today
            int sellNow = prices[i] + solveUsingRec(prices, i+1, 1, fee);

            // Option 2: Skip selling
            int sellLater = solveUsingRec(prices, i+1, 0, fee);

            profit = max(sellNow, sellLater);
        }

        return profit;
    }
    
    int solveUsingMem(vector<int>& prices, int i, int buy, int& fee, vector<vector<int>>& dp) {
        if(i>=prices.size()) return 0; // Base case

        // Return memoized result
        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;

        if(buy) {

            int buyNow = -(prices[i] + fee) + solveUsingMem(prices, i+1, 0, fee, dp);
            int buyLater = solveUsingMem(prices, i+1, 1, fee, dp);

            profit = max(buyNow, buyLater);

        } else {

            int sellNow = prices[i] + solveUsingMem(prices, i+1, 1, fee, dp);
            int sellLater = solveUsingMem(prices, i+1, 0, fee, dp);

            profit = max(sellNow, sellLater);
        }

        // Store computed answer
        dp[i][buy] = profit;

        return profit;
    }

    int solveUsingTab(vector<int>& prices, int& fee) {

        // dp[i][buy]
        // i = current day
        // buy = whether buying is allowed
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));

        for(int i=prices.size()-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {

                int profit = 0;

                if(buy) {

                    int buyNow = -(prices[i] + fee) + dp[i+1][0];
                    int buyLater = dp[i+1][1];

                    profit = max(buyNow, buyLater);

                } else {

                    int sellNow = prices[i] + dp[i+1][1];
                    int sellLater = dp[i+1][0];

                    profit = max(sellNow, sellLater);
                }

                dp[i][buy] = profit;
            }
        }

        return dp[0][1];
    }
    
    int solveUsingTabSO(vector<int>& prices, int& fee) {
        // vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));

        // Space optimized DP
        vector<int> curr(2, 0);
        vector<int> prev(2, 0);

        for(int i=prices.size()-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {

                int profit = 0;

                if(buy) {

                    int buyNow = -(prices[i] + fee) + prev[0];
                    int buyLater = prev[1];

                    profit = max(buyNow, buyLater);

                } else {

                    int sellNow = prices[i] + prev[1];
                    int sellLater = prev[0];

                    profit = max(sellNow, sellLater);
                }

                curr[buy] = profit;
            }

            prev = curr;
        }

        return prev[1];
    }

    
    int maxProfit(vector<int>& prices, int fee) {
        // return solveUsingRec(prices, 0, 1, fee);

        // vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        // return solveUsingMem(prices, 0, 1, fee, dp);

        // return solveUsingTab(prices, fee);

        return solveUsingTabSO(prices, fee);
    }
};

int main() {
    Solution obj;

    // Hardcoded test cases
    vector<int> prices1 = {1, 3, 2, 8, 4, 9};
    vector<int> prices2 = {1, 3, 7, 5, 10, 3};
    vector<int> prices3 = {9, 8, 7, 6, 5};

    int fee1 = 2;
    int fee2 = 3;
    int fee3 = 1;

    cout << "Test Case 1 Output: " << obj.maxProfit(prices1, fee1) << endl;
    cout << "Test Case 2 Output: " << obj.maxProfit(prices2, fee2) << endl;
    cout << "Test Case 3 Output: " << obj.maxProfit(prices3, fee3) << endl;

    return 0;
}