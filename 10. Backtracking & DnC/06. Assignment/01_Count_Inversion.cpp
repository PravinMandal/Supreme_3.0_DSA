//gfg: Count Inversions

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    // This function merges two sorted halves and counts inversions
    void merge(vector<int>& arr, int s, int e, int mid, int& ans) {

        // Length of left and right subarrays
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
        
        vector<int> sortedArr;

        int i = 0;
        int j = 0;

        // Merge two sorted arrays
        while(i<leftLen && j<rightLen) {

            if(leftArr[i] <= rightArr[j]) {
                sortedArr.push_back(leftArr[i]);
                i++;
            } else {

                //main Inversion Logic
                //answer wo hoga ki kitne steps lgenge ek array ko sorted banane ke liye
                //kitne inversions krne pdenge
                //toh agar ek element jo left mai bada hai right wale ek element se
                // but left toh sorted hai toh jo left element hai uske saare element jo abhi curr right ka element hai se bade honge
                // isiliye ye formula bana
                // ans -> kitne swap lgenge arr ko sorted banane ke liye
                // bubble sort mai easily pta chal jayega
                // but merge sort mai aise krna pdega jo niche ka formula hai kyuki merge sort, bubble sort se fast hai
                // merge sort sbko swap krte nhi baithta toh ye jo niche ka formula hai isse ans nikal jayega
                // easy hai tune khud hi nikala ye formula, on you own , just think in future carefully

                // Key idea:
                // Since leftArr is sorted, all remaining elements from index i to end
                // will be greater than rightArr[j], so each forms an inversion
                ans += (leftLen-i);

                sortedArr.push_back(rightArr[j]);
                j++;
            }
        }
        
        // Add remaining elements from left array
        while(i<leftLen) {
            sortedArr.push_back(leftArr[i]);
            i++;
        }

        // Add remaining elements from right array
        while(j<rightLen) {
            sortedArr.push_back(rightArr[j]);
            j++;
        }
        
        // Copy sorted array back to original array
        i = 0;
        for(int k=s; k<=e; k++) {
            arr[k] = sortedArr[i];
            i++;
        }
    }

    // Standard merge sort with inversion counting
    void mergeSort(vector<int>& arr, int s, int e, int& ans) {

        // Base case
        if(s>=e) return;

        int mid = s + (e-s)/2;

        // Sort left half
        mergeSort(arr,s, mid, ans);

        // Sort right half
        mergeSort(arr, mid+1, e, ans);

        // Merge both halves and count inversions
        merge(arr, s, e, mid, ans);
    }

    int inversionCount(vector<int> &arr) {

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
    vector<int> arr = {5, 3, 2, 4, 1};

    Solution obj;

    int result = obj.inversionCount(arr);

    cout << "Number of inversions: " << result << endl;

    return 0;
}