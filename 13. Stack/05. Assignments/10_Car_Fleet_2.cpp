//leetcode: 1776 - Car Fleet II

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double> ans(cars.size(), -1);
        stack<int> st; // index

        for(int i = cars.size() - 1; i >= 0; i--) {

            //check agar samne wali gaadi faster hai
            while(!st.empty() && cars[st.top()][1] >= cars[i][1]) {
                st.pop();
            }

            // Now stack top is a car ahead that is slower → collision possible
            while(!st.empty()) {
                double colTime = (double)(cars[st.top()][0] - cars[i][0]) /
                                 (cars[i][1] - cars[st.top()][1]);

                // Check if collision happens before the car ahead collides with someone else
                if(ans[st.top()] == -1 || colTime <= ans[st.top()]) {
                    ans[i] = colTime;  // valid collision time
                    break;
                }

                // Otherwise that car merges earlier; ignore it
                st.pop();
            }

            // Push current car into stack as potential collision target for cars behind
            st.push(i);
        }

        return ans;
    }
};

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    Solution sol;

    // Hardcoded Test Case 1
    // cars = {position, speed}
    vector<vector<int>> cars1 = {
        {3, 4},
        {5, 4},
        {6, 3},
        {9, 1}
    };
    // Expected: [2.00000, 1.00000, 1.50000, -1.00000]
    vector<double> result1 = sol.getCollisionTimes(cars1);

    cout << "Collision Times: ";
    for(double x : result1) cout << x << " ";
    cout << endl;

    // Hardcoded Test Case 2
    vector<vector<int>> cars2 = {
        {1, 2},
        {2, 1},
        {4, 3},
        {7, 2}
    };
    vector<double> result2 = sol.getCollisionTimes(cars2);

    cout << "Collision Times: ";
    for(double x : result2) cout << x << " ";
    cout << endl;

    return 0;
}
