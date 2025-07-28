//leetcode: 2104. Sum of Subarray Ranges
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextMin(vector<int>& nums) {
        stack<int> st;
        vector<int>ans(nums.size(), -1);
        st.push(-1);
        for(int i=nums.size()-1; i>=0; i--) {
            while(!st.empty() && st.top() != -1 && nums[st.top()] > nums[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevMin(vector<int>& nums) {
        stack<int> st;
        vector<int>ans(nums.size(), -1);
        st.push(-1);
        for(int i=0; i<nums.size(); i++) {
            while(!st.empty() && st.top()!=-1 && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMin(vector<int>& nums) {
        auto prev = prevMin(nums);
        auto next = nextMin(nums);
        long long sum = 0;
        for(int i=0; i<nums.size(); i++) {
            long long previ = prev[i];
            long long nexti = next[i] == -1 ? nums.size() : next[i];
            long long left = i-previ;
            long long right = nexti-i;

            sum += left*right*nums[i];
        }
        return sum;
    }

    vector<int> nextMax(vector<int>& nums) {
        stack<int> st;
        vector<int>ans(nums.size(), -1);
        st.push(-1);
        for(int i=nums.size()-1; i>=0; i--) {
            while(!st.empty() && st.top() != -1 && nums[st.top()] < nums[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevMax(vector<int>& nums) {
        stack<int> st;
        vector<int>ans(nums.size(), -1);
        st.push(-1);
        for(int i=0; i<nums.size(); i++) {
            while(!st.empty() && st.top()!=-1 && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMax(vector<int>& nums) {
        auto prev = prevMax(nums);
        auto next = nextMax(nums);
        long long sum = 0;
        for(int i=0; i<nums.size(); i++) {
            long long previ = prev[i];
            long long nexti = next[i] == -1 ? nums.size() : next[i];
            long long left = i-previ;
            long long right = nexti-i;

            sum += left*right*nums[i];
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        auto sumofMaximum = sumSubarrayMax(nums);
        auto sumofMinimum = sumSubarrayMin(nums);
        // sabka range nikal ke sum krenge wo bhi equal hi aayega
        // sum of sabka max and sum of saare subarray ka min, then undono ka subtraction
        //same aayega;
        return sumofMaximum - sumofMinimum;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3};
    cout << "Sum of Subarray Ranges: " << obj.subArrayRanges(nums) << endl;
    return 0;
}
