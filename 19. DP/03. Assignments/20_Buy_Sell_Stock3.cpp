//leetcode: 123. Best Time to Buy and Sell Stock III

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveUsingRec(vector<int>& prices, int i, int transactions, int buy) {
        if(i>=prices.size() || transactions >= 2) return 0; // Base case: no days left or transaction limit reached

        int profit = 0;

        if(buy) {

            // Option 1: Buy stock today
            int buyNow = -prices[i] + solveUsingRec(prices, i+1, transactions, 0);

            // Option 2: Buy later
            int buyLater = solveUsingRec(prices, i+1, transactions, 1);

            profit = max(buyNow, buyLater);

        } else {

            // Option 1: Sell stock today
            int sellNow = prices[i] + solveUsingRec(prices, i+1, transactions+1, 1);

            // Option 2: Sell later
            int sellLater = solveUsingRec(prices, i+1, transactions, 0);

            profit = max(sellNow, sellLater);
        }

        return profit;
    }
    
    int solveUsingMem(vector<int>& prices, int i, int transactions, int buy, unordered_map<int, unordered_map<int, unordered_map<int, int>>>& dp) {
        if(i>=prices.size() || transactions >= 2) return 0;

        // Return cached answer
        if(dp.count(i) && dp[i].count(transactions) && dp[i][transactions].count(buy)) return dp[i][transactions][buy];

        int profit = 0;

        if(buy) {
            int buyNow = -prices[i] + solveUsingMem(prices, i+1, transactions, 0, dp);
            int buyLater = solveUsingMem(prices, i+1, transactions, 1, dp);
            profit = max(buyNow, buyLater);
        } else {
            int sellNow = prices[i] + solveUsingMem(prices, i+1, transactions+1, 1, dp);
            int sellLater = solveUsingMem(prices, i+1, transactions, 0, dp);
            profit = max(sellNow, sellLater);
        }

        dp[i][transactions][buy] = profit;
        return profit;
    }

    int solveUsingMem(vector<int>& prices, int i, int transactions, int buy, vector<vector<vector<int>>>& dp) {
        if(i>=prices.size() || transactions >= 2) return 0;

        // Return memoized answer
        if(dp[i][transactions][buy] != -1) return dp[i][transactions][buy];

        int profit = 0;

        if(buy) {
            int buyNow = -prices[i] + solveUsingMem(prices, i+1, transactions, 0, dp);
            int buyLater = solveUsingMem(prices, i+1, transactions, 1, dp);
            profit = max(buyNow, buyLater);
        } else {
            int sellNow = prices[i] + solveUsingMem(prices, i+1, transactions+1, 1, dp);
            int sellLater = solveUsingMem(prices, i+1, transactions, 0, dp);
            profit = max(sellNow, sellLater);
        }

        dp[i][transactions][buy] = profit;
        return profit;
    }

    int solveUsingTab(vector<int>& prices) {

        // dp[i][transactions][buy]
        // i = current day
        // transactions = completed sell transactions
        // buy = whether buying is allowed
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(4, vector<int>(2, 0)));

        for(int i=prices.size()-1; i>=0; i--) {
            for(int transactions=1; transactions>=0; transactions--) {
                for(int buy=0; buy<=1; buy++) {
                    
                    int profit = 0;

                    if(buy) {
                        int buyNow = -prices[i] + dp[i+1][transactions][0];
                        int buyLater = dp[i+1][transactions][1];
                        profit = max(buyNow, buyLater);
                    } else {
                        int sellNow = prices[i] + dp[i+1][transactions+1][1];
                        int sellLater = dp[i+1][transactions][0];
                        profit = max(sellNow, sellLater);
                    }

                    dp[i][transactions][buy] = profit;
                }
            }
        }

        return dp[0][0][1];
    }
    
    int solveUsingTabSO(vector<int>& prices) {
        // vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(4, vector<int>(2, 0)));

        // Space optimized version
        vector<vector<int>> curr(4, vector<int>(2, 0));
        vector<vector<int>> prev(4, vector<int>(2, 0));

        for(int i=prices.size()-1; i>=0; i--) {
            for(int transactions=1; transactions>=0; transactions--) {
                for(int buy=0; buy<=1; buy++) {
                    
                    int profit = 0;

                    if(buy) {
                        int buyNow = -prices[i] + prev[transactions][0];
                        int buyLater = prev[transactions][1];
                        profit = max(buyNow, buyLater);
                    } else {
                        int sellNow = prices[i] + prev[transactions+1][1];
                        int sellLater = prev[transactions][0];
                        profit = max(sellNow, sellLater);
                    }

                    curr[transactions][buy] = profit;
                }

                prev = curr;
            }
        }

        return prev[0][1];
    }

    int solveUsingTabSO2(vector<int>& prices) {

        // Constant space optimized mathematical DP
        int buy1 = INT_MIN;
        int sell1 = 0;
        int buy2 = INT_MIN;
        int sell2 = 0;

        for (int price : prices) {

            // Best after first buy
            buy1 = max(buy1, -price);

            // Best after first sell
            sell1 = max(sell1, buy1 + price);

            // Best after second buy
            buy2 = max(buy2, sell1 - price);

            // Best after second sell
            sell2 = max(sell2, buy2 + price);
        }

        return sell2;
    }

    int maxProfit(vector<int>& prices) {
        // return solveUsingRec(prices, 0, 0, true);

        // unordered_map<int, unordered_map<int, unordered_map<int, int>>> dp;
        // return solveUsingMem(prices, 0, 0, true, dp);

        // vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(3, vector<int>(2, -1)));
        // return solveUsingMem(prices, 0, 0, true, dp);

        // return solveUsingTab(prices);

        return solveUsingTabSO(prices);
        
        // return solveUsingTabSO2(prices);
    }
};

int main() {
    Solution obj;

    // Hardcoded test cases
    vector<int> prices1 = {3,3,5,0,0,3,1,4};
    vector<int> prices2 = {1,2,3,4,5};
    vector<int> prices3 = {7,6,4,3,1};

    cout << "Test Case 1 Output: " << obj.maxProfit(prices1) << endl;
    cout << "Test Case 2 Output: " << obj.maxProfit(prices2) << endl;
    cout << "Test Case 3 Output: " << obj.maxProfit(prices3) << endl;

    return 0;
}