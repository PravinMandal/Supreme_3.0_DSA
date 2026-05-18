//leetcode: 474. Ones and Zeroes

#include <bits/stdc++.h>
using namespace std;


//ye wala work nhi krega TLE aata hai O(MNk2)
class Solution {
public:
    int solveUsingRec(vector<string>& strs, int m, int n, int start) {
        //base case
        if(m == 0 && n == 0) return 0; // Perfect resource usage
        if(m < 0 || n < 0) return INT_MIN; // Invalid state: exceeded allowed zeroes or ones

        int ans = 0;

        // Try choosing every string starting from current index
        for(int i=start; i<strs.size(); i++) {

            int one = 0;
            int zero = 0;

            // Count ones and zeroes in current string
            for(char ch : strs[i]) {
                if(ch == '1') one++;
                else zero++;
            }

            // Include current string
            int subset = 1 + solveUsingRec(strs, m-zero, n-one, i+1);

            ans = max(ans, subset);
        }

        return ans;
    }
    
    int solveUsingMem(vector<string>& strs, int m, int n, int start, vector<vector<vector<int>>>& dp, vector<int>& onesCount) {
        //base case
        if(m == 0 && n == 0) return 0; // Exact usage
        if(m < 0 || n < 0) return INT_MIN; // Invalid state

        // Return cached answer
        if(dp[m][n][start] != -1) return dp[m][n][start];

        int ans = 0;

        for(int i=start; i<strs.size(); i++) {

            // Use precomputed ones count
            int one = onesCount[i];
            int zero = strs[i].size() - one;

            // Include current string
            int subset = 1 + solveUsingMem(strs, m-zero, n-one, i+1, dp, onesCount);

            ans = max(ans, subset);
        }

        dp[m][n][start] = ans;

        return ans;
    }

    int solveUsingTab(vector<string>& strs, int M, int N) {

        /*
            dp[m][n][start] =
            maximum subset size using:
            m zeroes available
            n ones available
            starting from index 'start'
        */
        vector<vector<vector<int>>> dp(M+1, vector<vector<int>>(N+1, vector<int>(strs.size()+1, 0)));

        for(int m=0; m<=M; m++) {
            for(int n=0; n<=N; n++) {
                for(int start=strs.size()-1; start>=0; start--) {

                    int ans = 0;

                    for(int i=start; i<strs.size(); i++) {

                        int one = 0;
                        int zero = 0;

                        // Count zeroes and ones for current string
                        for(char ch : strs[i]) {
                            if(ch == '1') one++;
                            else zero++;
                        }

                        int subset = INT_MIN;

                        // Check if current string can be included
                        if(m-zero < 0 || n-one < 0) subset = INT_MIN;
                        else subset = 1 + dp[m-zero][n-one][i+1];

                        ans = max(ans, subset);
                    }

                    dp[m][n][start] = ans;
                }
            }
        }

        return dp[M][N][0];
    }

    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(strs.size()+1, -1)));

        vector<int> onesCount;

        // Precompute number of ones in each string
        for(int i=0; i<strs.size(); i++) {

            int one = 0;

            for(int j=0; j<strs[i].size(); j++) {
                if(strs[i][j] == '1') one++;
            }

            onesCount.push_back(one);
        }

        // return solveUsingRec(strs, m, n, 0, onesCount);

        return solveUsingMem(strs, m, n, 0, dp, onesCount);

        // return solveUsingTab(strs, m, n);
    }
};


// ye wala work krta hai O(MNk)
class Solution2 {
public:
    int solveUsingRec(vector<string>& strs, int m, int n, int i, vector<int>& onesCount) {
        //base case
        if(i>=strs.size()) return 0; // No strings left to choose

        int one = onesCount[i];
        int zero = strs[i].size() - one;

        int incl = 0, excl = 0;

        // Include current string only if enough zeroes and ones are available
        if((m-zero >= 0) && (n-one >= 0)) {
            incl = 1 + solveUsingRec(strs, m-zero, n-one, i+1, onesCount);
        }

        // Exclude current string
        excl = solveUsingRec(strs, m, n, i+1, onesCount);

        // Return maximum subset size
        return max(incl, excl);
    }
    
    int solveUsingMem(vector<string>& strs, int m, int n, int i, vector<vector<vector<int>>>& dp, vector<int>& onesCount) {
        //base case
        if(i>=strs.size()) return 0;

        // Return cached result
        if(dp[m][n][i] != -1) return dp[m][n][i];

        int one = onesCount[i];
        int zero = strs[i].size() - one;

        int incl = 0, excl = 0;

        // Include current string if resources allow
        if((m-zero >= 0) && (n-one >= 0)) {
            incl = 1 + solveUsingMem(strs, m-zero, n-one, i+1, dp, onesCount);
        }

        // Skip current string
        excl = solveUsingMem(strs, m, n, i+1, dp, onesCount);

        dp[m][n][i] = max(incl, excl);

        return max(incl, excl);
    }

    int solveUsingTab(vector<string>& strs, int M, int N, vector<int>& onesCount) {

        /*
            dp[m][n][i] =
            maximum subset size using:
            m zeroes remaining
            n ones remaining
            considering strings from index i onward
        */
        vector<vector<vector<int>>> dp(M+1, vector<vector<int>>(N+1, vector<int>(strs.size()+1, 0)));

        for(int m=0; m<=M; m++) {
            for(int n=0; n<=N; n++) {
                for(int i=strs.size()-1; i>=0; i--) {

                    int one = onesCount[i];
                    int zero = strs[i].size() - one;

                    int incl = 0, excl = 0;

                    // Include current string
                    if((m-zero >= 0) && (n-one >= 0)) {
                        incl = 1 + dp[m-zero][n-one][i+1];
                    }

                    // Exclude current string
                    excl = dp[m][n][i+1];

                    dp[m][n][i] = max(incl, excl);
                }
            }
        }

        return dp[M][N][0];
    }


    int findMaxForm(vector<string>& strs, int m, int n) {


        // ye pehle hi count krke rakh lete hai taaki baad mai har baar na krna pde
        vector<int> onesCount;

        // Precompute count of '1's for each string
        for(int i=0; i<strs.size(); i++) {
            int one = 0;

            for(int j=0; j<strs[i].size(); j++) {
                if(strs[i][j] == '1') one++;
            }

            onesCount.push_back(one);
        }

        // return solveUsingRec(strs, m, n, 0, onesCount);

        // vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(strs.size()+1, -1)));
        // return solveUsingMem(strs, m, n, 0, dp, onesCount);

        return solveUsingTab(strs, m, n, onesCount);
    }
};

int main() {
    Solution2 obj;

    // Hardcoded test cases
    vector<string> strs1 = {"10","0001","111001","1","0"};
    int m1 = 5;
    int n1 = 3;

    vector<string> strs2 = {"10","0","1"};
    int m2 = 1;
    int n2 = 1;

    vector<string> strs3 = {"10","01","001","111","000"};
    int m3 = 4;
    int n3 = 3;

    cout << "Test Case 1 Output: " << obj.findMaxForm(strs1, m1, n1) << endl;
    cout << "Test Case 2 Output: " << obj.findMaxForm(strs2, m2, n2) << endl;
    cout << "Test Case 3 Output: " << obj.findMaxForm(strs3, m3, n3) << endl;

    return 0;
}