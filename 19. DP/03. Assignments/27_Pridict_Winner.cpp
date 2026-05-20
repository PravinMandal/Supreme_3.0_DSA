//leetcode: 486. Predict the Winner

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveUsingRec(vector<int>& nums, int i, int j, bool player1) {
        if(i>j) return 0; // Base case: no numbers left

        int ans = 0;

        if(player1) {

            // Player 1 tries to maximize score
            // Option 1: Pick left number
            // Option 2: Pick right number
            ans = max(nums[i] + solveUsingRec(nums, i+1, j, 0), nums[j] + solveUsingRec(nums, i, j-1, 0));

        } else {

            // Player 2 plays optimally and tries to minimize Player 1's final score
            ans = min(solveUsingRec(nums, i+1, j, 1), solveUsingRec(nums, i, j-1, 1));
        }

        return ans;
    }

    int solveUsingMem(vector<int>& nums, int i, int j, bool player1, vector<vector<vector<int>>>& dp) {
        if(i>j) return 0; // Base case

        // Return memoized result
        if(dp[i][j][player1] != -1) return dp[i][j][player1];

        int ans = 0;

        if(player1) {

            // Player 1 maximizes score
            ans = max(nums[i] + solveUsingMem(nums, i+1, j, 0, dp), nums[j] + solveUsingMem(nums, i, j-1, 0, dp));

        } else {

            // Player 2 minimizes Player 1 score
            ans = min(solveUsingMem(nums, i+1, j, 1, dp), solveUsingMem(nums, i, j-1, 1, dp));
        }

        dp[i][j][player1] = ans;

        return ans;
    }

    int solveUsingTab(vector<int>& nums) {

        /*
            dp[i][j][player1]

            i = left index
            j = right index (+1 shifted indexing used here)
            player1 = whose turn
        */
        vector<vector<vector<int>>> dp(nums.size()+1, vector<vector<int>> (nums.size()+1, vector<int>(2, 0)));

        for(int i=nums.size()-1; i>=0; i--) {
            for(int j=0; j<nums.size(); j++) {

                if(i>j) continue;

                for(int player1=0; player1<=1; player1++) {

                    int ans = 0;

                    if(player1) {

                        // j-1 ho rha hai toh saare dp mai j+1 krna pdega warna -1 thodi koi index hota hai
                        // Player 1 chooses best scoring move
                        ans = max(nums[i] + dp[i+1][j+1][0] , nums[j] + dp[i][j][0]);

                    } else {

                        // Player 2 chooses move that minimizes Player 1 score
                        ans = min(dp[i+1][j+1][1], dp[i][j][1]);
                    }

                    dp[i][j+1][player1] = ans;
                }
            }
        }

        return dp[0][nums.size()-1+1][1];
    }

    int solveUsingTabSO(vector<int>& nums) {
        // vector<vector<vector<int>>> dp(nums.size()+1, vector<vector<int>> (nums.size()+1, vector<int>(2, 0)));

        // Space optimized DP
        vector<vector<int>> curr(nums.size()+1, vector<int>(2, 0));
        vector<vector<int>> prev(nums.size()+1, vector<int>(2, 0));

        for(int i=nums.size()-1; i>=0; i--) {
            for(int j=0; j<nums.size(); j++) {

                if(i>j) continue;

                for(int player1=0; player1<=1; player1++) {

                    int ans = 0;

                    if(player1) {

                        // j-1 ho rha hai toh saare dp mai j+1 krna pdega warna -1 thodi koi index hota hai
                        // Choose best move for Player 1
                        ans = max(nums[i] + prev[j+1][0] , nums[j] + curr[j][0]);

                    } else {

                        // Choose move that hurts Player 1 most
                        ans = min(prev[j+1][1], curr[j][1]);
                    }

                    curr[j+1][player1] = ans;
                }
            }

            prev = curr;
        }

        return prev[nums.size()-1+1][1];
    }

    bool predictTheWinner(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        //just float mai chale jaa rha tha isiliye int mai sahi comparision nhi ho paa rha tha
        // return solveUsingRec(nums, 0, nums.size()-1, 1)/1.0 >= (totalSum/2.0); 
        // return 2 * solveUsingRec(nums, 0, nums.size()-1, 1) >= (totalSum); 

        // vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>> (nums.size(), vector<int>(2, -1)));
        // return 2 * solveUsingMem(nums, 0, nums.size()-1, 1, dp) >= (totalSum); 

        // return 2 * solveUsingTab(nums) >= (totalSum); 
        return 2 * solveUsingTabSO(nums) >= (totalSum); 
    }
};

class Solution2 {
public:
    int solveUsingRec(vector<int>& nums, int s, int e) {
        if(s==e) return nums[s]; // Only one number left, current player takes it

        /*
            This approach stores score difference:
            current player's score - opponent's score

            So after taking one number,
            opponent will play optimally and their advantage is subtracted.
        */

        // Pick left number
        int takefromStart = nums[s] - solveUsingRec(nums, s+1, e);

        // Pick right number
        int takefromEnd = nums[e] - solveUsingRec(nums, s, e-1);

        // Choose better move
        return max(takefromStart, takefromEnd);
    }

    int solveUsingMem(vector<int>& nums, int s, int e, vector<vector<int>>& dp) {
        if(s>e) return 0; // No numbers left

        // Return memoized result
        if(dp[s][e] != -1) return dp[s][e];

        // Take left
        int takefromStart = nums[s] - solveUsingMem(nums, s+1, e, dp);

        // Take right
        int takefromEnd = nums[e] - solveUsingMem(nums, s, e-1, dp);

        dp[s][e] = max(takefromStart, takefromEnd);

        return max(takefromStart, takefromEnd);
    }

    int solveUsingTab(vector<int>& nums) {

        /*
            dp[s][e] stores maximum score difference
            (current player - opponent)

            Shifted indexing used because e-1 access happens
        */
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, 0));

        for(int s=nums.size()-1; s>=0; s--) {
            for(int e=0; e<nums.size(); e++) {

                if(s>e) continue;

                // e-1 ho rha hai, saare dp ke col mai +1 krdo

                // Pick from left
                int takefromStart = nums[s] - dp[s+1][e+1];

                // Pick from right
                int takefromEnd = nums[e] - dp[s][e-1+1];

                dp[s][e+1] = max(takefromStart, takefromEnd);
            }
        }

        return dp[0][nums.size()-1+1];
    }

    int solveUsingTabSO(vector<int>& nums) {
        // vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, 0));

        // Space optimized DP
        vector<int> curr(nums.size()+1, 0);
        vector<int> prev(nums.size()+1, 0);

        for(int s=nums.size()-1; s>=0; s--) {
            for(int e=0; e<nums.size(); e++) {

                if(s>e) continue;

                // e-1 ho rha hai, saare dp ke col mai +1 krdo

                // Pick left
                int takefromStart = nums[s] - prev[e+1];

                // Pick right
                int takefromEnd = nums[e] - curr[e];

                curr[e+1] = max(takefromStart, takefromEnd);
            }

            prev = curr;
        }

        return prev[nums.size()];
    }

    bool predictTheWinner(vector<int>& nums) {
        // return solveUsingRec(nums, 0, nums.size()-1) >= 0;

        // vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        // return solveUsingMem(nums, 0, nums.size()-1, dp) >= 0;

        // return solveUsingTab(nums)>= 0;
        return solveUsingTabSO(nums)>= 0;
    }
};

int main() {
    Solution2 obj;

    // Hardcoded test cases
    vector<int> nums1 = {1, 5, 2};
    vector<int> nums2 = {1, 5, 233, 7};
    vector<int> nums3 = {3, 9, 1, 2};

    cout << "Test Case 1 Output: " << obj.predictTheWinner(nums1) << endl;
    cout << "Test Case 2 Output: " << obj.predictTheWinner(nums2) << endl;
    cout << "Test Case 3 Output: " << obj.predictTheWinner(nums3) << endl;

    return 0;
}