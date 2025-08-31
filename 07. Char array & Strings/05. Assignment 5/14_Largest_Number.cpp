//leetcode: 179. Largest Number
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool compare(int num1, int num2) {
        string s1 = to_string(num1);
        string s2 = to_string(num2);
        return s1 + s2 > s2 + s1; 
        // ye breakthrough condition hai
        // ki kisko upar rakhna hai
        // Example:
        // 8308 vs 830  → "8308830" vs "8308308"
        // 432 vs 43243 → "43243243" vs "43243432"
        // jisme s1+s2 bada ho, wahi upar aayega
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);

        if (nums[0] == 0) return "0"; // sab 0 hone ka case handle

        string ans = "";
        for (int num : nums) {
            ans += to_string(num);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 30, 34, 5, 9};
    cout << "Largest Number: " << sol.largestNumber(nums) << endl;

    vector<int> nums2 = {10, 2};
    cout << "Largest Number: " << sol.largestNumber(nums2) << endl;

    vector<int> nums3 = {0, 0};
    cout << "Largest Number: " << sol.largestNumber(nums3) << endl;

    return 0;
}
