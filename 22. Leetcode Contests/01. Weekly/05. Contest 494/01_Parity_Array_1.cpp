//leetcode: 3875. Construct Uniform Parity Array I

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        // Count how many numbers are odd and even
        int odd = 0, even = 0;

        for(int x : nums1) {
            if(x % 2 == 0) even++;
            else odd++;
        }

        // ---------------- CORE LOGIC ----------------
        // Option 1: Make all elements EVEN
        // We can:
        // - keep even numbers as they are
        // - convert odd numbers using (odd - odd = even)
        // So we need at least one odd to convert others
        bool canMakeEven = (even > 0) || (odd >= 2);

        // Option 2: Make all elements ODD
        // We can:
        // - keep odd numbers as they are
        // - convert even numbers using (even - odd = odd)
        // So we need at least one odd
        bool canMakeOdd = (odd > 0);

        // If either is possible, return true
        return canMakeEven || canMakeOdd;
    }
};

class Solution2 {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};

int main() {

    // Hardcoded test cases
    vector<int> nums1 = {1, 2, 3, 4};

    Solution2 obj;

    bool result = obj.uniformArray(nums1);

    if(result) cout << "Possible to construct uniform parity array" << endl;
    else cout << "Not possible" << endl;

    return 0;
}