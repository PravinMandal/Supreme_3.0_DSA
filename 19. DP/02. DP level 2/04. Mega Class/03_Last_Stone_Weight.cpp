//leetcode: 1049. Last Stone Weight II

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalSum = 0;

    // Pure recursion (explores all + and - assignments)
    int solveUsingRec(vector<int>& stones, int i, int sum) {
        if(i>=stones.size()) {
            if(sum<0) return 0-sum; // negative values nhi lena, INT_MAX bhi daal skte hai
            return sum;
        }
        int pos = solveUsingRec(stones, i+1, sum+stones[i]);
        int neg = solveUsingRec(stones, i+1, sum-stones[i]);
        return min(pos, neg);
    }
    
    // Memoization: dp[i][sum + totalSum] stores best answer
    int solveUsingMem(vector<int>& stones, int i, int sum, vector<vector<int>>& dp) {
        if(i>=stones.size()) {
            if(sum<0) return 0-sum; // negative values nhi lena, INT_MAX bhi daal skte hai
            return sum;
        }
        if(dp[i][sum+totalSum] != -1) return dp[i][sum+totalSum];
        int pos = solveUsingMem(stones, i+1, sum+stones[i], dp);
        int neg = solveUsingMem(stones, i+1, sum-stones[i], dp);
        return dp[i][sum+totalSum] = min(pos, neg);
    }

    // Tabulation (bottom-up DP)
    int solveUsingTab(vector<int>& stones) {

        // dp[i][s] = minimum possible absolute sum using elements from i..n-1 with current sum s
        vector<vector<int>> dp(stones.size()+1, vector<int>(2*totalSum+1, 0));

        // Base case: when i == n
        for(int sum= -totalSum; sum<=totalSum; sum++) {
            dp[stones.size()][sum+totalSum] = sum<0 ? INT_MAX : sum;
        }

        // Fill DP table from bottom
        for(int i=stones.size()-1; i>=0; i--) {
            for(int sum=totalSum; sum>=-totalSum; sum--) {

                int pos = INT_MAX, neg = INT_MIN;

                // Add current stone
                if(sum+stones[i] <= totalSum)
                    pos = dp[i+1][totalSum + sum+stones[i]];

                // Subtract current stone
                if(sum-stones[i] >= -totalSum)
                    neg = dp[i+1][totalSum + sum-stones[i]];

                // Take minimum absolute result
                dp[i][sum+totalSum] = min(pos, neg);
            }
        }

        // Starting from index 0 and sum = 0
        return dp[0][totalSum];
    }

    // Space Optimized Tabulation
    int solveUsingTabSO(vector<int>& stones) {

        // prev represents dp[i+1], curr represents dp[i]
        vector<int> prev(2*totalSum+1, 0);
        vector<int> curr(2*totalSum+1, 0);

        // Base case initialization
        for(int sum= -totalSum; sum<=totalSum; sum++) {
            prev[sum+totalSum] = sum<0 ? INT_MAX : sum;
        }

        // Fill from bottom
        for(int i=stones.size()-1; i>=0; i--) {
            for(int sum=totalSum; sum>=-totalSum; sum--) {

                int pos = INT_MAX, neg = INT_MIN;

                if(sum+stones[i] <= totalSum)
                    pos = prev[totalSum + sum+stones[i]];

                if(sum-stones[i] >= -totalSum)
                    neg = prev[totalSum + sum-stones[i]];

                curr[sum+totalSum] = min(pos, neg);
            }

            //shifting
            prev = curr;
        }

        return prev[totalSum];
    }

    int lastStoneWeightII(vector<int>& stones) {

        totalSum = 0;

        // Total sum of all stones
        totalSum = accumulate(stones.begin(), stones.end(), 0);

        // vector<vector<int>> dp(stones.size()+1, vector<int>(2*totalSum, -1));
        // return solveUsingMem(stones, 0, 0, dp);

        // return solveUsingTab(stones);

        return solveUsingTabSO(stones);
    }
};

int main() {

    // Hardcoded test case
    vector<int> stones = {2,7,4,1,8,1};

    Solution obj;

    int result = obj.lastStoneWeightII(stones);

    cout << "Minimum possible remaining weight: " << result << endl;

    return 0;
}