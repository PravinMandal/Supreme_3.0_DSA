//leetcode: 493. Reverse Pairs

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // This function merges two sorted halves and also counts reverse pairs
    void merge(vector<int>& arr, int s, int e, int mid, int& ans) {

        int leftLen = mid-s+1;
        int rightLen = e-mid;

        vector<int> leftArr;
        vector<int> rightArr;
        
        // Copy left half
        for(int i=s; i<=mid; i++) {
            leftArr.push_back(arr[i]);
        }

        // Copy right half
        for(int i=mid+1; i<=e; i++) {
            rightArr.push_back(arr[i]);
        }

        // ---------------- REVERSE PAIR LOGIC ----------------
        // Count pairs such that:
        // leftArr[i] > 2 * rightArr[j]
        // Since both arrays are sorted, we can use two pointers
        int j2 = 0;

        for(int i=0; i<leftLen; i++) {

            // Move j2 while condition satisfies
            // 2LL ensures no integer overflow
            while(j2<rightLen && leftArr[i] > 2LL * rightArr[j2]) {
                j2++;
            }

            // All elements from 0 to j2-1 satisfy condition
            ans += j2;
        }
        
        // ---------------- NORMAL MERGE SORT MERGE ----------------
        vector<int> sortedArr;

        int i = 0;
        int j = 0;

        // Merge two sorted arrays
        while(i<leftLen && j<rightLen) {
            if(leftArr[i] <= rightArr[j]) {
                sortedArr.push_back(leftArr[i]);
                i++;
            } else {
                sortedArr.push_back(rightArr[j]);
                j++;
            }
        }
        
        // Add remaining elements
        while(i<leftLen) {
            sortedArr.push_back(leftArr[i]);
            i++;
        }

        while(j<rightLen) {
            sortedArr.push_back(rightArr[j]);
            j++;
        }
        
        // Copy back to original array
        i = 0;
        for(int k=s; k<=e; k++) {
            arr[k] = sortedArr[i];
            i++;
        }
    }

    // Standard merge sort
    void mergeSort(vector<int>& arr, int s, int e, int& ans) {

        // Base case
        if(s>=e) return;

        int mid = s + (e-s)/2;

        // Sort left half
        mergeSort(arr,s, mid, ans);

        // Sort right half
        mergeSort(arr, mid+1, e, ans);

        // Merge and count reverse pairs
        merge(arr, s, e, mid, ans);
    }

    int reversePairs(vector<int>& arr) {

        int ans = 0;

        int s = 0;
        int e = arr.size()-1;

        // Start merge sort
        mergeSort(arr, s, e, ans);

        return ans;
    }
};

int main() {

    // Hardcoded test case
    vector<int> arr = {1, 3, 2, 3, 1};

    Solution obj;

    int result = obj.reversePairs(arr);

    cout << "Number of reverse pairs: " << result << endl;

    return 0;
}