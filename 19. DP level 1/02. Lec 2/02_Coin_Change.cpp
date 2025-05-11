#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int solve(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int minCoins = INT_MAX;

        for(int i=0; i<coins.size(); i++) {
            int coin = coins[i];

            if(coin<=amount) {
                int recurAns = solve(coins, amount-coin);

                if(recurAns != INT_MAX) {
                    int coinCount = 1 + recurAns;
                    minCoins = min(minCoins, coinCount);
                }
            }
        }
        return minCoins;
    }

    //1D dp
    int solveMem(vector<int>& coins, int amount, vector<int>& dp) {
        if(amount == 0) return 0;

        if(dp[amount] != -1) {
            return dp[amount];
        }
        int minCoins = INT_MAX;

        for(int i=0; i<coins.size(); i++) {
            int coin = coins[i];

            if(coin<=amount) {
                int recurAns = solveMem(coins, amount-coin, dp);

                if(recurAns != INT_MAX) {
                    int coinCount = 1 + recurAns;
                    minCoins = min(minCoins, coinCount);
                }
            }
        }
        dp[amount] = minCoins;
        return dp[amount];
    }

    int solveTab(vector<int>& coins, int amount) {
        vector<int>dp(amount+10, -1);
        dp[0] = 0;

        for(int amt=1; amt<=amount; amt++) {
            int minCoins = INT_MAX;

            for(int i=0; i<coins.size(); i++) {
                int coin = coins[i];

                if(coin<=amt) {
                    int recurAns = dp[amt-coin];

                    if(recurAns != INT_MAX) {
                        int coinCount = 1 + recurAns;
                        minCoins = min(minCoins, coinCount);
                    }
                }
            }
            dp[amt] = minCoins;
        }
        return dp[amount];
    }

    //isme space optimization nhi ho paayega

    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<int>dp(amount+10, -1);
        int ans = solveTab(coins, amount);
        if(ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // fixed input
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = sol.coinChange(coins, amount);
    cout << "Minimum number of coins required: " << result << endl;

    return 0;
}
