//leetcode: 215. Kth Largest Element in an Array
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        //initial state maintain kro
        for(int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }
        //ab mere pass k element aa gye hai min heap mai
        //ab mera target ye h ki mere k size ke heap ko maintain krna h and usme k sbse bade element store krna h
        //phir mujhe top pr kth largest element mil jayega
        for(int i = k; i < nums.size(); i++) {
            if(nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        int ans = pq.top();
        return ans;
    }
};

int main() {
    // Example test case:
    // Given Array: [3, 2, 1, 5, 6, 4]
    // k = 2, so the 2nd largest element should be 5.
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    
    Solution sol;
    int kthLargest = sol.findKthLargest(nums, k);
    
    cout << "The " << k << "th largest element is: " << kthLargest << endl;
    return 0;
}
