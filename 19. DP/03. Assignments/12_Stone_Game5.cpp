//leetcode: 1563. Stone Game V

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveUsingRec(vector<int>& stoneValue, vector<int>& prevSum, int s, int e) {
        if(s==e) return 0; // Only one stone left, no split possible
        
        int alice = 0;

        // Try every possible split point
        for(int mid=s; mid<=e; mid++) {

            // Sum of left partition [s...mid]
            int leftSum = prevSum[mid] - (s-1 >=0 ? prevSum[s-1] : 0);

            // Sum of right partition [mid+1...e]
            int rightSum = prevSum[e] - prevSum[mid];

            if(leftSum == rightSum) {

                /*
                    If both partitions are equal,
                    Alice can choose the better side.
                */
                alice = max(alice, leftSum + max(solveUsingRec(stoneValue, prevSum, s, mid), solveUsingRec(stoneValue, prevSum, mid+1, e)));

            } else if(leftSum > rightSum) {

                /*
                    Bob removes larger partition.
                    Alice gets smaller partition's sum.
                    Continue only on smaller side.
                */
                alice = max(alice, rightSum + solveUsingRec(stoneValue, prevSum, mid+1, e));

            } else {

                /*
                    Left side is smaller.
                    Alice continues on left partition.
                */
                alice = max(alice, leftSum + solveUsingRec(stoneValue, prevSum, s, mid));
            }
        }

        return alice;
    }

    int solveUsingMem(vector<int>& stoneValue, vector<int>& prevSum, int s, int e, vector<vector<int>>& dp) {
        if(s==e) return 0; // Base case

        // Return memoized result
        if(dp[s][e] != -1) return dp[s][e];
        
        int alice = 0;

        for(int mid=s; mid<=e; mid++) {

            int leftSum = prevSum[mid] - (s-1 >=0 ? prevSum[s-1] : 0);
            int rightSum = prevSum[e] - prevSum[mid];

            if(leftSum == rightSum) {

                alice = max(alice, leftSum + max(solveUsingMem(stoneValue, prevSum, s, mid, dp), solveUsingMem(stoneValue, prevSum, mid+1, e, dp)));

            } else if(leftSum > rightSum) {

                alice = max(alice, rightSum + solveUsingMem(stoneValue, prevSum, mid+1, e, dp));

            } else {

                alice = max(alice, leftSum + solveUsingMem(stoneValue, prevSum, s, mid, dp));
            }
        }

        dp[s][e] = alice;

        return alice;
    }

    int solveUsingTab(vector<int>& stoneValue, vector<int>& prevSum) {
        int n = stoneValue.size();

        /*
            dp[s][e] = maximum score Alice can get
            from subarray stoneValue[s...e]
        */
        vector<vector<int>> dp(stoneValue.size()+1, vector<int> (stoneValue.size()+1, 0));

        for(int s=n-1; s>=0; s--) {
            for(int e=s; e<n; e++) {

                int alice = 0;

                // Try every split point
                for(int mid=s; mid<=e; mid++) {

                    int leftSum = prevSum[mid] - (s-1 >=0 ? prevSum[s-1] : 0);
                    int rightSum = prevSum[e] - prevSum[mid];

                    if(leftSum == rightSum) {

                        // Equal sums: choose better side
                        alice = max(alice, leftSum + max(dp[s][mid], dp[mid+1][e]));

                    } else if(leftSum > rightSum) {

                        // Continue on right side
                        alice = max(alice, rightSum + dp[mid+1][e]);

                    } else {

                        // Continue on left side
                        alice = max(alice, leftSum + dp[s][mid]);
                    }
                }

                dp[s][e] = alice;
            }
        }

        return dp[0][n-1];
    }
    
    int stoneGameV(vector<int>& stoneValue) {

        // Prefix sum array for O(1) range sum calculation
        vector<int> prevSum;

        int sum = 0;

        for(int i : stoneValue) {
            sum += i;
            prevSum.push_back(sum);
        }

        // return solveUsingRec(stoneValue, prevSum, 0, stoneValue.size()-1);

        // vector<vector<int>> dp(stoneValue.size()+1, vector<int> (stoneValue.size()+1, -1));
        // return solveUsingMem(stoneValue, prevSum, 0, stoneValue.size()-1, dp);

        return solveUsingTab(stoneValue, prevSum);
    }
};

int main() {
    Solution obj;

    // Hardcoded test cases
    vector<int> stoneValue1 = {6, 2, 3, 4, 5, 5};
    vector<int> stoneValue2 = {7, 7, 7, 7, 7, 7, 7};
    vector<int> stoneValue3 = {4};

    cout << "Test Case 1 Output: " << obj.stoneGameV(stoneValue1) << endl;
    cout << "Test Case 2 Output: " << obj.stoneGameV(stoneValue2) << endl;
    cout << "Test Case 3 Output: " << obj.stoneGameV(stoneValue3) << endl;

    return 0;
}