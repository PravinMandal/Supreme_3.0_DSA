//contest: Count Bowl Subarrays
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void leftGreater(vector<int>& nums, vector<int>& left) {
        int n = nums.size();
        stack<int> st;
        st.push(-1);
        for(int i=0; i< nums.size(); i++) {
            int element = nums[i];
            while(st.top()!= -1 && element >= nums[st.top()]) {
                st.pop();
            }
            if(st.top() == -1) {
                left[i] = -1;
            }
            else
                left[i] = st.top();
            st.push(i);
        }
    }

    void rightGreater(vector<int>& nums, vector<int>& right) {
        int n = nums.size();
        stack<int> st;
        st.push(-1);
        for(int i=n-1; i>=0; i--) {
            int element = nums[i];
            while(st.top()!= -1 && element >= nums[st.top()]) {
                st.pop();
            }
            if(st.top() == -1)
                right[i] = -1;
            else
                right[i] = st.top();
            st.push(i);
        }
    }

    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftGreaterElem(n, -1);
        vector<int>rightGreaterElem(n, -1);
        leftGreater(nums, leftGreaterElem);
        rightGreater(nums, rightGreaterElem);

        long long ans = 0;
        for(int i=0; i<n; i++) {
            if((leftGreaterElem[i] != -1) && (rightGreaterElem[i] != -1)) {
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded testcases
    vector<int> nums1 = {2, 5, 3, 1, 4};
    cout << sol.bowlSubarrays(nums1) << endl;  // Example output

    vector<int> nums2 = {5, 3, 8, 2, 6, 1, 7};
    cout << sol.bowlSubarrays(nums2) << endl;  // Example output

    vector<int> nums3 = {1, 2, 3, 4};
    cout << sol.bowlSubarrays(nums3) << endl;  // Example output

    return 0;
}
