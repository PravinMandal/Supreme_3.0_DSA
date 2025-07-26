//leetcode: 907. Sum of Subarray Minimums
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:

    // Function to find the index of the next smaller element for every element in the array
    vector<int> nextSmallerElement(vector<int> arr) {
        stack<int> st; // Stack to keep track of indices
        st.push(-1);   // Sentinel value to handle boundary cases
        vector<int> ans(arr.size(), -1); // Initialize answer array with -1 (default if no smaller found)

        // Traverse array from right to left
        for(int i = arr.size() - 1; i >= 0; i--) {
            // Pop elements from stack until you find a smaller element
            while (!st.empty() && st.top() != -1 && arr[st.top()] > arr[i]) {
                st.pop();
            }
            // Top of the stack is the index of the next smaller element
            ans[i] = st.top();
            // Push current index onto the stack
            st.push(i);
        }

        return ans;
    }

    // Function to find the index of the previous smaller element for every element in the array
    vector<int> pervSmallerElement(vector<int>& arr) {
        stack<int> st; // Stack to keep track of indices
        st.push(-1);   // Sentinel value to handle boundary cases
        vector<int> ans(arr.size(), -1); // Initialize answer array with -1 (default if no smaller found)

        // Traverse array from left to right
        for(int i = 0; i < arr.size(); i++) {
            // Pop elements from stack until you find a smaller (or equal for strict increasing) element
            while (!st.empty() && st.top() != -1 && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            // Top of the stack is the index of the previous smaller element
            ans[i] = st.top();
            // Push current index onto the stack
            st.push(i);
        }

        return ans;
    }

    // Main function to calculate the sum of subarray minimums
    int sumSubarrayMins(vector<int>& arr) {
        auto prev = pervSmallerElement(arr);  // Get previous smaller element indices
        auto next = nextSmallerElement(arr);  // Get next smaller element indices

        long long sum = 0; // To store the final result
        const int mod = 1e9 + 7; // Modulo value to prevent overflow

        // Iterate through each element of the array
        for(int i = 0; i < arr.size(); i++) {
            // If there is no next smaller, we consider the end of array as boundary
            long long nexti = (next[i] == -1) ? arr.size() : next[i];

            // Previous smaller index
            long long previ = prev[i];

            // Number of elements to the left where current element is minimum
            long long left = i - previ;

            // Number of elements to the right where current element is minimum
            long long right = nexti - i;

            // Each arr[i] contributes arr[i] * left * right times
            // Multiply and take mod to avoid overflow
            sum = (sum + ((left * right) % mod * arr[i]) % mod) % mod;
        }

        // Return the final answer
        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 1, 2, 4};
    int result = sol.sumSubarrayMins(arr);
    cout << "Sum of subarray minimums: " << result << endl; // Expected output: 17
    return 0;
}
