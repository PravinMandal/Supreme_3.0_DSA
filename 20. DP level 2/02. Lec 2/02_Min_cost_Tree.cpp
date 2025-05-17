//leetcode: 1130. Minimum Cost Tree From Leaf Values
#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

class Solution {
public:
    int solveUsingRec(vector<int>& arr, map<pair<int,int>, int>&maxi, int s, int e) {
        //base case
        if(s>=e) return 0;

        int ans = INT_MAX;
        for(int i=s; i<e; i++) {
            int leftRangekaMax = maxi[{s,i}];
            int rightRangekaMax = maxi[{i+1, e}];
            int NonLeafValue = leftRangekaMax * rightRangekaMax;
            ans = min(ans, NonLeafValue + solveUsingRec(arr, maxi, s, i) + solveUsingRec(arr, maxi, i+1, e));
        }
        return ans;
    }

    //Memoisation
    int solveUsingMem(vector<int>& arr, map<pair<int,int>, int>&maxi, int s, int e, vector<vector<int>>& dp) {
        //base case
        if(s>=e) return 0;

        if(dp[s][e] != -1) {
            return dp[s][e];
        }

        int ans = INT_MAX;
        for(int i=s; i<e; i++) {
            int leftRangekaMax = maxi[{s,i}];
            int rightRangekaMax = maxi[{i+1, e}];
            int NonLeafValue = leftRangekaMax * rightRangekaMax;
            ans = min(ans, NonLeafValue + solveUsingMem(arr, maxi, s, i, dp) + solveUsingMem(arr, maxi, i+1, e, dp));
        }
        dp[s][e] = ans;
        return dp[s][e];
    }

    //Tabulation
    int solveUsingTab(vector<int>& arr, map<pair<int,int>, int>&maxi, int s, int e) {
        vector<vector<int>> dp(e+10, vector<int>(e+10, 0));

        for(int strt=e; strt>=0; strt--) {
            for(int end=s; end<=e; end++) {
                if(strt>=end) {
                        continue;
                }
                else {
                    int ans = INT_MAX;
                    for(int i=strt; i<end; i++) {
                            int leftRangekaMax = maxi[{strt,i}];
                            int rightRangekaMax = maxi[{i+1, end}];
                            int NonLeafValue = leftRangekaMax * rightRangekaMax;
                            ans = min(ans, NonLeafValue + dp[strt][i] + dp[i+1][end]);
                }
                dp[strt][end] = ans;
                }
            }
        }
        return dp[0][e];
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        map<pair<int,int> , int> maxi;

        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(i == j) {
                    maxi[{i,j}] = arr[i];
                }
                else {
                    maxi[{i,j}] = max(maxi[{i,j-1}], arr[j]);
                }
            }
        }

        int s=0;
        int e=n-1;

        //Recursion
        // int ans = solveUsingRec(arr, maxi, s, e);

        //Memoisation
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // int ans = solveUsingMem(arr, maxi, s, e, dp);

        //Tabulation
        int ans = solveUsingTab(arr, maxi, s, e);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {6, 2, 4}; // you can change this to test different inputs
    cout << "Minimum cost to build tree from leaf values: " << sol.mctFromLeafValues(arr) << endl;
    return 0;
}
