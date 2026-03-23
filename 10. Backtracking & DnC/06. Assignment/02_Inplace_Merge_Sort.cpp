//leetcode: 912. Sort an Array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // This function merges two sorted halves IN-PLACE using GAP method
    // (Inspired by Shell Sort / Gap method)
    void mergeInplace(vector<int>& nums, int s, int e, int mid) {

        int total_len = e-s+1;

        // Initial gap = ceil(length / 2)
        int gap = ceil(total_len / 2.0);

        // Reduce gap until it becomes 0
        while(gap > 0) {

            int i = s , j = s + gap;

            // Compare elements at distance = gap
            while(j <= e) {

                // If elements are out of order, swap them
                if(nums[i] > nums[j]) {
                    swap(nums[i], nums[j]);
                }

                i++; 
                j++;
            }

            // Reduce gap
            // If gap = 1 → next should be 0 (stop)
            // Else reduce gap to ceil(gap / 2)
            gap = gap<=1 ? 0 : ceil(gap/2.0);
        }
    }

    // Standard merge sort recursion
    void mergeSort(vector<int>& nums, int s, int e) {

        // Base case
        if(s>=e) return;

        int mid = s + (e-s)/2;

        // Sort left half
        mergeSort(nums, s,mid);

        // Sort right half
        mergeSort(nums, mid+1, e);

        // Merge both halves in-place
        mergeInplace(nums, s, e, mid);
    }

    vector<int> sortArray(vector<int>& nums) {

        int s = 0;
        int e = nums.size()-1;

        // Apply merge sort
        mergeSort(nums, s, e);

        return nums;
    }
};

int main() {

    // Hardcoded test case
    vector<int> nums = {5, 2, 3, 1};

    Solution obj;

    vector<int> result = obj.sortArray(nums);

    cout << "Sorted array: ";

    for(int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}