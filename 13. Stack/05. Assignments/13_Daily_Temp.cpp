//leetcode: 739 - Daily Temperatures

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findNextGreater(vector<int>& ans, vector<int>& temp) {
        stack<int> st;
        st.push(INT_MAX);
        for(int i=temp.size()-1; i>=0; i--) {
            int element = temp[i];
            while(!st.empty()&& st.top() != INT_MAX && temp[st.top()] <= element) {
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i);
        }

        for(int i=0; i<ans.size(); i++) {
            if(ans[i] == INT_MAX) {
                ans[i] = -1;
            }
        }
        reverse(ans.begin(), ans.end());
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> nextGreater;
        findNextGreater(nextGreater, temperatures);
        vector<int> ans;
        
        for(int i=0; i<temperatures.size(); i++) {
            if(nextGreater[i] == -1) {
                ans.push_back(0);
            } else {
                ans.push_back(nextGreater[i] - i);
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> st;   // stores indices of unresolved temperatures

        for(int i = 0; i < temperatures.size(); i++) {

            // While current temperature is hotter than the one on top of stack
            // we found the next warmer day for that index
            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                ans[st.top()] = i - st.top();  // number of days waited
                st.pop();
            }

            // push current index to stack
            st.push(i);
        }

        // All remaining indices will stay 0 (no warmer future day)
        return ans;
    }
};

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    Solution2 sol;

    // Hardcoded test case
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    // Expected output: [1,1,4,2,1,1,0,0]

    vector<int> result = sol.dailyTemperatures(temperatures);

    cout << "Result: ";
    for(int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
