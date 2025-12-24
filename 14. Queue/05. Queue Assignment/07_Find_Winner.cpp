//leetcode: 1823 - Find the Winner of the Circular Game

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> nums;

        // initialize players from 1 to n
        for(int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        int i = 0;

        // eliminate players until only one remains
        while(nums.size() != 1) {
            // move (k-1) steps ahead in circular manner
            i = (i + k - 1) % nums.size();

            // remove the eliminated player
            nums.erase(nums.begin() + i);
        }

        // last remaining player is the winner
        return nums[0];
    }
};

class Solution2 {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;

        // push all players into the queue
        for(int i = 1; i <= n; i++) {
            q.push(i);
        }

        int count = 0;

        // simulate the game until only one player remains
        while(q.size() > 1) {
            count++;
            int front = q.front();
            q.pop();

            if(count != k) {
                // player survives this round, move to back of queue
                q.push(front);
            }

            if(count == k) {
                // kth player is eliminated, reset count
                count = 0;
            }
        }

        // the last remaining player is the winner
        return q.front();
    }
};

// ---------------------- MAIN FUNCTION (HARDCODED TESTING) ----------------------
int main() {
    Solution2 sol;

    // Hardcoded test cases
    cout << sol.findTheWinner(5, 2) << endl;  // Expected: 3
    cout << sol.findTheWinner(6, 5) << endl;  // Expected: 1
    cout << sol.findTheWinner(1, 1) << endl;  // Expected: 1
    cout << sol.findTheWinner(10, 3) << endl; // Example scenario

    return 0;
}
