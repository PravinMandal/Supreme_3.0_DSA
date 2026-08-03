//gfg: Minimum Multiplications to Reach End

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(vector<int>& arr, int start, int end) {

        /*
            There are only 1000 possible states
            because every multiplication is performed modulo 1000.

            So we model the problem as a graph where:
            - Every number from 0 to 999 is a node.
            - Multiplying by any element in arr creates an edge.
        */
        const int MOD = 1000;

        // Standard BFS queue
        queue<int> q;

        /*
            ans[node] stores the minimum number of multiplications
            required to reach 'node'.

            -1 means the node has not been visited yet.
        */
        vector<int> ans(1000, -1);

        // Starting node requires 0 operations.
        ans[start] = 0;

        q.push(start);

        while(!q.empty()) {

            int front = q.front();
            q.pop();

            // As BFS explores level by level,
            // first time we reach 'end' is the shortest path.
            if(front == end)
                return ans[end];

            /*
                Try multiplying current number
                with every multiplier in the array.
            */
            for(int i : arr) {

                // Next state after multiplication
                int newNode = (front * i) % MOD;

                // Visit only if not already visited
                if(ans[newNode] == -1) {

                    ans[newNode] = ans[front] + 1;

                    q.push(newNode);
                }
            }
        }

        // End value cannot be reached.
        return -1;
    }
};

int main() {

    Solution obj;

    // ---------------- Test Case 1 ----------------
    vector<int> arr1 = {2, 5, 7};
    int start1 = 3;
    int end1 = 30;

    // ---------------- Test Case 2 ----------------
    vector<int> arr2 = {3, 4, 65};
    int start2 = 7;
    int end2 = 661;

    // ---------------- Test Case 3 ----------------
    vector<int> arr3 = {2};
    int start3 = 1;
    int end3 = 999;

    cout << "Test Case 1 Output: "
         << obj.minSteps(arr1, start1, end1) << endl;

    cout << "Test Case 2 Output: "
         << obj.minSteps(arr2, start2, end2) << endl;

    cout << "Test Case 3 Output: "
         << obj.minSteps(arr3, start3, end3) << endl;

    return 0;
}