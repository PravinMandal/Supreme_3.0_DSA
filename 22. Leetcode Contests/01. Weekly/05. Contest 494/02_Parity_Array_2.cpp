//leetcode: 3876. Construct Uniform Parity Array II

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int odds = 0;
        int evens = 0;

        // Count number of odd and even elements
        for(int i : nums1) {
            if((i&1) == 1) odds++;
            else evens++;
        }

        // If all numbers are already same parity → always possible
        if(odds == 0 || evens == 0) return true;

        // Sort the array to bring smallest element at index 0
        sort(nums1.begin(),nums1.end());

        // Core idea:
        // If smallest element is odd → we can use it to convert all others to odd
        // because (even - odd = odd)
        // If smallest is even → cannot guarantee conversion for all
        return nums1[0]&1 == 1; //odd
    }
};

int main() {

    // Hardcoded test cases
    vector<int> nums1 = {2, 4, 1, 6};

    Solution obj;

    bool result = obj.uniformArray(nums1);

    if(result) cout << "Possible to construct uniform parity array" << endl;
    else cout << "Not possible" << endl;

    return 0;
}