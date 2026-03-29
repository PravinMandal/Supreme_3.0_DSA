//leetcode: 1655. Distribute Repeating Integers

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Backtracking function:
    // Try to satisfy each quantity[i] using available frequencies
    bool solve(unordered_map<int, int>& freq, vector<int>& quantity, int i) {

        // If all customers are satisfied → return true
        if(i >= quantity.size()) return true;

        // Try assigning current quantity[i] to any number group
        // mp ko pass by reference krna warna mp mai jo change kr rhe hai wo freq mai refelect nhi hoga
        for(auto& mp : freq) {

            int num = mp.first;
            int times = mp.second;

            // If this number has enough frequency
            if(times >= quantity[i]) {

                // Assign quantity[i] to this number
                mp.second -= quantity[i];

                // Recurse for next customer
                bool ans = solve(freq, quantity, i+1);

                // If successful → return true immediately
                if(ans) return true;

                // Backtrack: restore frequency
                mp.second += quantity[i];
            }
        }

        // If no assignment works → return false
        return false;
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {

        // Build frequency map
        unordered_map<int, int> freq;
        for(int i : nums) freq[i]++;

        // quantity ko descending order mai sort kr diya
        // agar quantity ka sabse bade element jitna kisiki freq hi nhi hogi toh false hoga
        // toh ye ab jaldi detect ho jayega
        sort(quantity.rbegin(), quantity.rend());

        // Start backtracking
        return solve(freq, quantity, 0);
    }
};

int main() {

    // Hardcoded test case
    vector<int> nums = {1,1,2,2};
    vector<int> quantity = {2,2};

    Solution obj;

    bool result = obj.canDistribute(nums, quantity);

    if(result) cout << "Distribution possible" << endl;
    else cout << "Distribution not possible" << endl;

    return 0;
}