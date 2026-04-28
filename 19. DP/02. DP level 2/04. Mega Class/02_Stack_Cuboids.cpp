//leetcode: 1691. Maximum Height by Stacking Cuboids
//1th index se sort krke try kiye hai, rather than 0th index

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& c1, const vector<int>& c2) {
        if(c1[1] == c2[1]) {
            if(c1[2] == c2[2]) {
                return c1[0] < c2[0];
            }
            return c1[2] < c2[2];
        }
        return c1[1] < c2[1];
    }

    bool isSafeToPlace(vector<int>& c1, vector<int>& c2) {
        //agar ye dono pass by reference krte hai toh submit bhi ho jaata h
        //TLE nahi maarta
        //but still dp se toh krna pdega
        return (c1[0]<=c2[0] && c1[1]<=c2[1] && c1[2]<=c2[2]);
    }

    int solveUsingRec(vector<vector<int>>& cuboids, int prev, int curr) {
        //base case
        if(curr >= cuboids.size()) {
            return 0;
        }

        int incl = 0;
        if(prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr])) {
            incl = cuboids[curr][2] + solveUsingRec(cuboids, curr, curr+1);
        }
        int excl = 0 + solveUsingRec(cuboids, prev, curr+1);
        int ans = max(incl, excl);
        return ans;
    }

    //2D DP
    int solveUsingMem(vector<vector<int>>& cuboids, int prev, int curr, vector<vector<int>>& dp) {
        //base case
        if(curr >= cuboids.size()) {
            return 0;
        }

        if(dp[prev+1][curr] != -1) {
            return dp[prev+1][curr];
        }

        int incl = 0;
        if(prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr])) {
            //prev -1 hai toh dp mai store nhi kr payenge toh sabme +1 krdo
            incl = cuboids[curr][2] + solveUsingMem(cuboids, curr, curr+1, dp);
        }
        int excl = 0 + solveUsingMem(cuboids, prev, curr+1, dp);
        dp[prev+1][curr] = max(incl, excl);
        return dp[prev+1][curr];
    }

    //Tabulation
    int solveUsingTab(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int curr=n-1; curr >= 0; curr--) {
            for(int prev = curr-1; prev >= -1; prev--) {
                int incl = 0;
                if((prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr]))) {
                    //prev -1 hai toh dp mai store nhi kr payenge toh sabme +1 krdo
                    incl = cuboids[curr][2] + dp[curr+1][curr+1];
                }
                int excl = 0 + dp[prev+1][curr+1];
                dp[prev+1][curr] = max(incl, excl);
            }
        }
        return dp[-1+1][0];
    }

    //TabulationSO
    int solveUsingTabSO(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        vector<int>currRow(n+1, 0);
        vector<int>prevRow(n+1, 0);
        
        for(int curr = n-1; curr >= 0; curr--) {
            for(int prev = curr-1; prev >= -1; prev--) {
                int incl = 0;
                if((prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr]))) {
                    incl = cuboids[curr][2] + prevRow[curr+1];
                }
                int excl = 0 + prevRow[prev+1];
                currRow[prev+1] = max(incl, excl);
            }
            //shifting
            prevRow = currRow;
        }
        return currRow[-1+1];
    }

    //TabulationSO2
    int solveUsingTabSO2(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        vector<int>currRow(n+1, 0);
        
        for(int curr = n-1; curr >= 0; curr--) {
            for(int prev = -1; prev >= curr-1; prev++) {
                int incl = 0;
                if((prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr]))) {
                    incl = cuboids[curr][2] + currRow[curr+1];
                }
                int excl = 0 + currRow[prev+1];
                currRow[prev+1] = max(incl, excl);
            }
        }
        return currRow[-1+1];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        //hum sort kr dete h poore cuboid ko 
        for(auto &cuboid: cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }

        //0th index se sort kr rhe h toh chal rha hai but 1th index se nhi
        //1th index se sort krte hai and 1th, 2th index dono cuboid ka agar same rha
        //toh randomly hota hai, but 0th index bhi consider hona chahiye
        // isse solve krne ke liye aachese comparator likhna pdega
        sort(cuboids.begin(), cuboids.end(), compare);

        int prev = -1;
        int curr = 0;

        //Memoisation
        vector<vector<int>> dp(cuboids.size()+10, vector<int>(cuboids.size()+10, -1));

        // return solveUsingMem(cuboids, prev, curr, dp);

        //Tabulation
        // return solveUsingTab(cuboids);

        //TabulationSO
        return solveUsingTabSO(cuboids);

        //TabulationSO2
        // return solveUsingTabSO2(cuboids);
    }
};

int main() {

    // Hardcoded test case
    vector<vector<int>> cuboids = {
        {50,45,20},
        {95,37,53},
        {45,23,12}
    };

    Solution obj;

    int result = obj.maxHeight(cuboids);

    cout << "Maximum stack height: " << result << endl;

    return 0;
}