//leetcode: 1406. Stone Game III

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveUsingRec(vector<int>& stoneValue, int idx, bool alice) {
        if(idx >= stoneValue.size()) return 0; // Base case: no stones left

        int ans = alice ? INT_MIN : INT_MAX;
        int sum = 0;

        // Try taking 1 to 3 stones
        for(int i=0; i<3; i++) {
            if(idx+i < stoneValue.size())
                sum += stoneValue[idx+i];

            if(alice) {
                // Alice tries to maximize her score
                ans = max(ans, sum + solveUsingRec(stoneValue, idx+i+1, !alice));
            } else {
                // Bob tries to minimize Alice's score
                ans = min(ans, solveUsingRec(stoneValue, idx+i+1, !alice));
            }
        }

        return ans;
    }
    
    int solveUsingMem(vector<int>& stoneValue, int idx, bool alice, vector<vector<int>>& dp) {
        if(idx >= stoneValue.size()) return 0;

        // Return stored value if already computed
        if(dp[idx][alice] != -1) return dp[idx][alice];

        int ans = alice ? INT_MIN : INT_MAX;
        int sum = 0;

        for(int i=0; i<3; i++) {
            if(idx+i < stoneValue.size())
                sum += stoneValue[idx+i];

            if(alice) {
                ans = max(ans, sum + solveUsingMem(stoneValue, idx+i+1, !alice, dp));
            } else {
                ans = min(ans, solveUsingMem(stoneValue, idx+i+1, !alice, dp));
            }
        }

        // Store result
        dp[idx][alice] = ans;

        return ans;
    }

    int solveUsingTab(vector<int>& stoneValue) {
        // dp[idx][alice] stores best score Alice can achieve from idx with turn
        vector<vector<int>> dp(stoneValue.size()+5, vector<int> (2, 0));

        // Bottom-up calculation
        for(int idx = stoneValue.size()-1; idx>=0; idx--) {
            for(int alice=0; alice<=1; alice++) {

                int ans = alice ? INT_MIN : INT_MAX;
                int sum = 0;

                for(int i=0; i<3; i++) {
                    if(idx+i < stoneValue.size())
                        sum += stoneValue[idx+i];

                    if(alice) {
                        ans = max(ans, sum + dp[idx+i+1][!alice]);
                    } else {
                        ans = min(ans, dp[idx+i+1][!alice]);
                    }
                }

                dp[idx][alice] = ans;
            }
        }

        return dp[0][1]; // Start from index 0 with Alice's turn
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int totalSum = accumulate(stoneValue.begin(), stoneValue.end(), 0);

        // int aliceScore = solveUsingRec(stoneValue, 0, true);

        // vector<vector<int>> dp(stoneValue.size()+1, vector<int> (2, -1));
        // int aliceScore = solveUsingMem(stoneValue, 0, true, dp);

        int aliceScore = solveUsingTab(stoneValue);

        // Bob gets remaining score
        int bobScore = totalSum - aliceScore;

        // Decide winner
        return aliceScore > bobScore ? "Alice" : aliceScore < bobScore ? "Bob" : "Tie";
    }
};

class Solution2 {
public:
    int solveUsingRec(vector<int>& sv, int idx) {
        if(idx >= sv.size()) return 0;
        
        int ans = INT_MIN;
        int sum = 0;
        for(int i=1; i<=3; i++) {
            if(idx+i-1 >= sv.size()) break;
            sum += sv[idx+i-1];
            ans = max(ans, sum - solveUsingRec(sv, idx+i));
        }
        return ans;
    }
    
    int solveUsingMem(vector<int>& sv, int idx, vector<int>& dp) {
        if(idx >= sv.size()) return 0;
        if(dp[idx] != -1) return dp[idx];

        int ans = INT_MIN;
        int sum = 0;
        for(int i=1; i<=3; i++) {
            if(idx+i-1 >= sv.size()) break;
            sum += sv[idx+i-1];
            ans = max(ans, sum - solveUsingMem(sv, idx+i, dp));
        }
        dp[idx] = ans;
        return ans;
    }

    int solveUsingTab(vector<int>& sv) {
        vector<int> dp(sv.size()+1, 0);

        for(int idx=sv.size()-1; idx>=0; idx--) {
            int ans = INT_MIN;
            int sum = 0;
            for(int i=1; i<=3; i++) {
                if(idx+i-1 >= sv.size()) break;
                sum += sv[idx+i-1];
                ans = max(ans, sum - dp[idx+i]);
            }
            dp[idx] = ans;
        }
        return dp[0];
    }

    string stoneGameIII(vector<int>& stoneValue) {
        // int ans = solveUsingRec(stoneValue, 0);

        // vector<int> dp(stoneValue.size()+1, -1);
        // int ans = solveUsingMem(stoneValue, 0, dp);

        int ans = solveUsingTab(stoneValue);

        
        return ans>0 ? "Alice" : ans<0 ? "Bob" : "Tie";
    }
};

int main() {
    Solution2 obj;

    // Hardcoded test cases
    vector<int> stones1 = {1, 2, 3, 7};
    vector<int> stones2 = {1, 2, 3, -9};
    vector<int> stones3 = {1, 2, 3, 6};

    cout << "Test Case 1 Output: " << obj.stoneGameIII(stones1) << endl;
    cout << "Test Case 2 Output: " << obj.stoneGameIII(stones2) << endl;
    cout << "Test Case 3 Output: " << obj.stoneGameIII(stones3) << endl;

    return 0;
}