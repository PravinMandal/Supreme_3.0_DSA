//leetcode: 473. Matchsticks to Square
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool solve(vector<int>& matchsticks, vector<int>& sides, int i) {
        // Base case
        if (i == matchsticks.size()) {
            bool ans = sides[0] == 0 && sides[1] == 0 && sides[2] == 0 && sides[3] == 0;
            return ans;
        }

        for (int j = 0; j < sides.size(); j++) {
            if (matchsticks[i] <= sides[j]) {
                sides[j] -= matchsticks[i];
                bool ans = solve(matchsticks, sides, i + 1);
                if (ans == true) return true;
                sides[j] += matchsticks[i]; // Backtracking
            }
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4) return false;
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) return false;
        int sidesum = sum / 4;

        vector<int> sides(4, sidesum);

        sort(matchsticks.rbegin(), matchsticks.rend()); // Sort in descending order
        // This reduces unnecessary recursive calls
        return solve(matchsticks, sides, 0);
    }
};

int main() {
    Solution solution;
    vector<int> matchsticks = {1, 1, 2, 2, 2}; // Example input

    if (solution.makesquare(matchsticks)) {
        cout << "Yes, you can form a square with the matchsticks." << endl;
    } else {
        cout << "No, you cannot form a square with the matchsticks." << endl;
    }

    return 0;
}
