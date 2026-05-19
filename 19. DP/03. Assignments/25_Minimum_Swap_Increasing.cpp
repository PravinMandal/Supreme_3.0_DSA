//leetcode: 801. Minimum Swaps To Make Sequences Increasing

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int INF = 1e9;
public:
    int solveUsingRec(vector<int>& nums1, vector<int>& nums2, int i) {
        //base case
        if(i>=nums1.size()) return 0; // All positions processed

        int ans = INT_MAX;

        // No swap case
        // Current elements already maintain strictly increasing order
        if(i==0 || ((nums1[i] > nums1[i-1]) && (nums2[i] > nums2[i-1]))) {
            ans = solveUsingRec(nums1, nums2, i+1);
        } 

        // Swap case
        // Check whether swapping current pair keeps both arrays increasing
        if(i==0 || nums1[i]>nums2[i-1] && nums2[i]>nums1[i-1]) {

            // Temporarily swap current elements
            swap(nums1[i], nums2[i]);

            // 1 swap + solve remaining
            ans = min(ans, 1 + solveUsingRec(nums1, nums2, i+1));

            // Backtrack
            swap(nums1[i], nums2[i]);
        }

        return ans;
    }

    int solveUsingMem(vector<int>& nums1, vector<int>& nums2, int i, bool swapped, vector<vector<int>>& dp) {
        //base case
        if(i>=nums1.size()) return 0;

        // Return memoized answer
        if(dp[i][swapped] != -1) return dp[i][swapped];

        int ans = INT_MAX;

        //no swap
        if(i==0 || ((nums1[i] > nums1[i-1]) && (nums2[i] > nums2[i-1]))) {
            ans = solveUsingMem(nums1, nums2, i+1, 0, dp);
        } 

        // swapped
        if(i==0 || nums1[i]>nums2[i-1] && nums2[i]>nums1[i-1]) {

            // Try swapping current elements
            swap(nums1[i], nums2[i]);

            ans = min(ans, 1 + solveUsingMem(nums1, nums2, i+1, 1, dp));

            // Restore original values
            swap(nums1[i], nums2[i]);
        }

        dp[i][swapped] = ans;

        return ans;
    }

    int solveUsingTab(vector<int>& nums1, vector<int>& nums2) {

        /*
            dp[i][swapped]

            i = current index
            swapped = whether previous index was swapped

            This matters because previous values change if swap happened.
        */
        vector<vector<int>> dp(nums1.size()+1, vector<int>(2, 0));

        for(int i=nums1.size()-1; i>=0; i--) {
            for(int swapped=1; swapped>=0; swapped--) {

                int prev1 = -1;
                int prev2 = -1;

                // Determine previous values
                if(i>0) {
                    prev1 = nums1[i-1];
                    prev2 = nums2[i-1];

                    // If previous index was swapped,
                    // previous values must be swapped too
                    if(swapped) 
                        swap(prev1, prev2);
                }

                int ans = INT_MAX;

                //no swap
                if(i==0 || ((nums1[i] > prev1) && (nums2[i] > prev2))) {
                    ans = dp[i+1][0];
                } 

                // swapped
                if(i==0 || nums1[i]>prev2 && nums2[i]>prev1) {

                    // Temporary swap only for logic consistency
                    swap(nums1[i], nums2[i]);

                    ans = min(ans, 1 + dp[i+1][1]);

                    // Restore
                    swap(nums1[i], nums2[i]);
                }

                dp[i][swapped] = ans;
            }
        }

        return dp[0][0];
    }
    
    int solveUsingTabSO(vector<int>& nums1, vector<int>& nums2) {
        // vector<vector<int>> dp(nums1.size()+1, vector<int>(2, 0));

        // Space optimized DP
        vector<int> curr(2, 0);
        vector<int> prev(2, 0);

        for(int i=nums1.size()-1; i>=0; i--) {
            for(int swapped=1; swapped>=0; swapped--) {

                int prev1 = -1;
                int prev2 = -1;

                if(i>0) {
                    prev1 = nums1[i-1];
                    prev2 = nums2[i-1];

                    if(swapped) 
                        swap(prev1, prev2);
                }

                int ans = INT_MAX;

                //no swap
                if(i==0 || ((nums1[i] > prev1) && (nums2[i] > prev2))) {
                    ans = prev[0];
                } 

                // swapped
                if(i==0 || nums1[i]>prev2 && nums2[i]>prev1) {

                    swap(nums1[i], nums2[i]);

                    ans = min(ans, 1 + prev[1]);

                    swap(nums1[i], nums2[i]);
                }

                curr[swapped] = ans;
            }

            //shifting
            prev = curr;
        }

        return prev[0];
    }


    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // return solveUsingRec(nums1, nums2, 0);

        // vector<vector<int>> dp(nums1.size()+1, vector<int>(2, -1));
        // return solveUsingMem(nums1, nums2, 0, false, dp);

        // return solveUsingTab(nums1, nums2);

        return solveUsingTabSO(nums1, nums2);
    }
};

class Solution2 {
public:
    int solveUsingRec(vector<int>& nums1, vector<int>& nums2, int i, int p1, int p2) {
        if(i>=nums1.size()) return 0;
        
        int swap = INT_MAX, noSwap = INT_MAX;
        // swap
        if(p1 < nums2[i] && p2 < nums1[i]) {
            swap = 1 + solveUsingRec(nums1, nums2, i+1, nums2[i], nums1[i]);
        }
        if(p1 < nums1[i] && p2 < nums2[i]) {
            noSwap = solveUsingRec(nums1, nums2, i+1, nums1[i], nums2[i]);
        }

        return min(swap, noSwap);
    }

    int solveUsingMem(vector<int>& nums1, vector<int>& nums2, int i, int p1, int p2, vector<vector<int>>& dp, int isSwapped) {
        if(i>=nums1.size()) return 0;
        if(dp[i][isSwapped] != -1) return dp[i][isSwapped];
        
        int swap = INT_MAX, noSwap = INT_MAX;
        // swap
        if(p1 < nums2[i] && p2 < nums1[i]) {
            swap = 1 + solveUsingMem(nums1, nums2, i+1, nums2[i], nums1[i], dp, 1);
        }
        if(p1 < nums1[i] && p2 < nums2[i]) {
            noSwap = solveUsingMem(nums1, nums2, i+1, nums1[i], nums2[i], dp, 0);
        }

        dp[i][isSwapped] = min(swap, noSwap);
        return min(swap, noSwap);
    }

    int solveUsingTab(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        vector<vector<int>> dp(nums1.size()+1, vector<int>(2, 0));

        for(int i=nums1.size()-1; i>=1; i--) {
            for(int isSwapped=1; isSwapped>=0; isSwapped--) {
                int p1 = nums1[i-1];
                int p2 = nums2[i-1];

                if(isSwapped)
                    swap(p1, p2);
                    
                int swapp = INT_MAX, noSwap = INT_MAX;
                // swap
                if(p1 < nums2[i] && p2 < nums1[i]) {
                    swapp = 1 + dp[i+1][1];
                }
                if(p1 < nums1[i] && p2 < nums2[i]) {
                    noSwap = dp[i+1][0];
                }

                dp[i][isSwapped] = min(swapp, noSwap);
            }
        }
        return dp[1][0];
    }

    int solveUsingTabSO(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        // vector<vector<int>> dp(nums1.size()+1, vector<int>(2, 0));
        vector<int> curr(2, 0);
        vector<int> prev(2, 0);

        for(int i=nums1.size()-1; i>=1; i--) {
            for(int isSwapped=1; isSwapped>=0; isSwapped--) {
                int p1 = nums1[i-1];
                int p2 = nums2[i-1];

                if(isSwapped)
                    swap(p1, p2);

                int swapp = INT_MAX, noSwap = INT_MAX;
                // swap
                if(p1 < nums2[i] && p2 < nums1[i]) {
                    swapp = 1 + prev[1];
                }
                if(p1 < nums1[i] && p2 < nums2[i]) {
                    noSwap = prev[0];
                }

                curr[isSwapped] = min(swapp, noSwap);
            }
            //shifting
            prev = curr;
        }
        return prev[0];
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // return solveUsingRec(nums1, nums2, 0, -1, -1);

        // vector<vector<int>> dp(nums1.size(), vector<int>(2, -1));
        // return solveUsingMem(nums1, nums2, 0, -1, -1, dp, 0);

        // return solveUsingTab(nums1, nums2);
        return solveUsingTabSO(nums1, nums2);
    }
};

int main() {
    Solution2 obj;

    // Hardcoded test cases
    vector<int> nums1_1 = {1, 3, 5, 4};
    vector<int> nums2_1 = {1, 2, 3, 7};

    vector<int> nums1_2 = {0, 3, 5, 8, 9};
    vector<int> nums2_2 = {2, 1, 4, 6, 9};

    vector<int> nums1_3 = {1, 5, 6, 8};
    vector<int> nums2_3 = {2, 3, 7, 10};

    cout << "Test Case 1 Output: " << obj.minSwap(nums1_1, nums2_1) << endl;
    cout << "Test Case 2 Output: " << obj.minSwap(nums1_2, nums2_2) << endl;
    cout << "Test Case 3 Output: " << obj.minSwap(nums1_3, nums2_3) << endl;

    return 0;
}