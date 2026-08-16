//leetcode: 2029. Stone Game IX

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        // Count how many stones have each possible remainder
        // when divided by 3.
        vector<int> count(3, 0);

        for(int i : stones)
            count[i%3]++;

        /*
            Stones with remainder 0 do not change the current
            remainder of the running sum.

            If the number of remainder-0 stones is even,
            Alice needs at least one stone from both remainder
            1 and remainder 2 to have a winning strategy.
        */
        if(count[0] % 2 == 0)
            return (count[1] >= 1) && (count[2] >= 1);

        /*
            If the number of remainder-0 stones is odd,
            the difference between remainder-1 and remainder-2
            stones determines whether Alice can force a win.

            A difference greater than 2 is required.
        */
        return abs(count[1] - count[2]) > 2;
    }
};

int main() {

    Solution obj;

    // Hardcoded Test Case 1
    vector<int> stones1 = {2, 1};

    // Hardcoded Test Case 2
    vector<int> stones2 = {2};

    // Hardcoded Test Case 3
    vector<int> stones3 = {5, 1, 2, 4, 3};

    // Hardcoded Test Case 4
    vector<int> stones4 = {1, 1, 1, 1};

    cout << "Test Case 1 Output: " << obj.stoneGameIX(stones1) << endl;
    cout << "Test Case 2 Output: " << obj.stoneGameIX(stones2) << endl;
    cout << "Test Case 3 Output: " << obj.stoneGameIX(stones3) << endl;
    cout << "Test Case 4 Output: " << obj.stoneGameIX(stones4) << endl;

    return 0;
}