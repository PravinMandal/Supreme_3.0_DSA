//leetcode: 735 - Asteroid Collision

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;

        for(int i : asteroids) {
            if(i > 0) {
                // positive asteroid → right direction → safe to push
                st.push(i);
            }
            else {
                // negative asteroid → moving left, so collision possible
                bool flag = 0;  // flag to mark if same-size collision happened

                // resolve collisions
                while(!st.empty() && st.top() > 0 && st.top() <= abs(i)) {

                    if(st.top() == abs(i)) {
                        // equal size → both explode
                        flag = 1;
                        st.pop();
                        break;
                    }
                    st.pop();   // top asteroid is smaller → destroy it
                }

                // If no asteroid destroyed our current left-moving asteroid
                if(st.empty() || st.top() < 0) {
                    if(!flag) {
                        st.push(i); // push only if it survived
                    }
                }
            }
        }

        // Build final answer from stack
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    Solution sol;

    // Hardcoded test cases
    vector<vector<int>> tests = {
        {5, 10, -5},            // Output: {5, 10}
        {8, -8},                // Output: {}
        {10, 2, -5},            // Output: {10}
        {-2, -1, 1, 2},         // Output: {-2, -1, 1, 2}
        {1, -1, -2, 5, -5},     // Output: {-2}
        {3, 4, -9},             // Output: {-9}
        {1, 3, 2, -3}           // Output: {1}
    };

    for(auto &test : tests) {
        vector<int> res = sol.asteroidCollision(test);
        cout << "Input: ";
        for(int x : test) cout << x << " ";
        cout << " --> Output: ";
        for(int x : res) cout << x << " ";
        cout << endl;
    }

    return 0;
}
