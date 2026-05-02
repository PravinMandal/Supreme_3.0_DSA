//leetcode: 877. Stone Game

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, int> solveUsingRec(vector<int>& piles, int i, int j, bool turn) {
        if(i>=j) return {0, 0}; // Base case: no valid range left

        int alice = 0;
        int bob = 0;

        if(turn) {
            // Alice's turn: she tries to maximize her score
            // She can pick either left or right pile
            alice += max(
                (piles[i] + solveUsingRec(piles, i+1, j, 0).first), 
                (piles[j] + solveUsingRec(piles, i, j-1, 0).first)
            );
        } else {
            // Bob's turn: he tries to maximize his score
            bob += max(
                (piles[i] + solveUsingRec(piles, i+1, j, 1).second), 
                (piles[j] + solveUsingRec(piles, i, j-1, 1).second)
            );
        }

        return {alice, bob}; // Return scores of Alice and Bob
    }
    
    pair<int, int> solveUsingMem(vector<int>& piles, int i, int j, bool turn, unordered_map<int, unordered_map<int, pair<int, int>>>& dp) {
        if(i>=j) return {0, 0};

        // Check if result already computed
        if(dp[i].count(j) != 0) return dp[i][j];

        int alice = 0;
        int bob = 0;

        if(turn) {
            // Alice chooses best option
            alice += max(
                (piles[i] + solveUsingMem(piles, i+1, j, 0, dp).first), 
                (piles[j] + solveUsingMem(piles, i, j-1, 0, dp).first)
            );
        } else {
            // Bob chooses best option
            bob += max(
                (piles[i] + solveUsingMem(piles, i+1, j, 1, dp).second), 
                (piles[j] + solveUsingMem(piles, i, j-1, 1, dp).second)
            );
        }

        // Store result
        dp[i][j] = {alice, bob};

        return {alice, bob};
    }

    bool stoneGame(vector<int>& piles) {
        // auto ans = solveUsingRec(piles, 0, piles.size()-1, 1);

        unordered_map<int, unordered_map<int, pair<int, int>>> dp;

        // Use memoization to optimize
        auto ans = solveUsingMem(piles, 0, piles.size()-1, 1, dp);

        // Alice wins if her score is greater than Bob's
        return ans.first > ans.second;
    }
};

class Solution2 {
public:
    bool stoneGame(vector<int>& piles) {
        // there will be at least one way by which alice will win
        // that means, we should just return true;
        // because problem is asking, is there any way that alice can win.
        return true;
    }
};

int main() {
    Solution2 obj;

    // Hardcoded test cases
    vector<int> piles1 = {5, 3, 4, 5};
    vector<int> piles2 = {3, 7, 2, 3};

    cout << "Test Case 1 Output: " << obj.stoneGame(piles1) << endl;
    cout << "Test Case 2 Output: " << obj.stoneGame(piles2) << endl;

    return 0;
}