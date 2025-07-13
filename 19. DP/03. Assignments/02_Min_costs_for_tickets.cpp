//leetcode: 983. Minimum Cost For Tickets
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solveUsingRec(vector<int>& days, vector<int>& costs, int i) {
        //base case
        if(i>=days.size()) return 0;

        // 1 day pass
        int cost1 = costs[0] + solveUsingRec(days, costs, i+1);

        //7 day pass
        int j = i;
        int passEndDay = days[j] + 7-1;
        while(j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost7 = costs[1] + solveUsingRec(days, costs, j);

        //30 day pass
        j = i;
        passEndDay = days[j] + 30-1;
        while(j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost30 = costs[2] + solveUsingRec(days, costs, j);

        return min(cost1, min(cost7, cost30));
    }

    int solveUsingMem(vector<int>& days, vector<int>& costs, int i, vector<int>& dp) {
        //base case
        if(i>=days.size()) return 0;

        if(dp[i] != -1) {
            return dp[i];
        }
        // 1 day pass
        int cost1 = costs[0] + solveUsingMem(days, costs, i+1, dp);

        //7 day pass
        int j = i;
        int passEndDay = days[j] + 7-1;
        while(j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost7 = costs[1] + solveUsingMem(days, costs, j, dp);

        //30 day pass
        j = i;
        passEndDay = days[j] + 30-1;
        while(j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost30 = costs[2] + solveUsingMem(days, costs, j, dp);

        dp[i] = min(cost1, min(cost7, cost30));
        return dp[i];
    }

    int solveUsingTab(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, 0);
        dp[n] = 0;

        for(int i=n-1; i>=0; i--) {
            // 1 day pass
            int cost1 = costs[0] + dp[i+1];

            //7 day pass
            int j = i;
            int passEndDay = days[j] + 7-1;
            while(j < days.size() && days[j] <= passEndDay) {
                j++;
            }
            int cost7 = costs[1] + dp[j];

            //30 day pass
            j = i;
            passEndDay = days[j] + 30-1;
            while(j < days.size() && days[j] <= passEndDay) {
                j++;
            }
            int cost30 = costs[2] + dp[j];

            dp[i] = min(cost1, min(cost7, cost30));
        }
        return dp[0];
    }

    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        //recursion
        // return solveUsingRec(days, costs, 0);

        //memoisation
        int n = days.size();
        vector<int> dp(n+1, -1);
        // return solveUsingMem(days, costs, 0, dp);

        //Tabulation
        return solveUsingTab(days, costs);
    }
};

// main function added for testing
int main() {
    Solution sol;

    // Sample Input: travel days and costs
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};

    int result = sol.mincostTickets(days, costs);

    cout << "Minimum cost for tickets: " << result << endl;

    return 0;
}
