//leetcode: 209 Minimum Size Subarray Sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX;
        int sum = 0;
        //dono ko starting index pr rakha hai
        int s = 0;
        int e = 0;

        while(e < nums.size()) {
            sum += nums[e];

            while(sum >= target) {
                //minmize kro, and pehle ans bhi store krlo
                len = min(len, e-s+1);
                sum -= nums[s]; // sum bhi delete krte jo, minimization process
                s++;
            }
            //yaha pohoch gya mtlb sum chhota ho gya target se
            e++;
        }

        if(len == INT_MAX) return 0;
        return len;
    }
};

int main() {
    // Hardcoded test case instead of cin
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    Solution obj;
    int result = obj.minSubArrayLen(target, nums);

    cout << "Minimum size subarray length = " << result << endl;

    return 0;
}
