//leetcode: 658. Find K Closest Elements
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowerbound(vector<int>& arr, int x) {
        int s=0;
        int e=arr.size()-1;
        int ans = e; //-1 se nhi krenge kyuki nhi mila toh end rakh denge as a closest
        while(s<=e) {
            int mid = s + ((e-s)>>1);
            if(arr[mid] >= x) {
                ans = mid;
                e = mid-1;
            }
            else {
                s = mid+1;
            }
        }
        return ans;
    }
    vector<int> bs_Method(vector<int>& arr, int k, int x) {
        int h = lowerbound(arr, x);
        int l = h-1;
        while(k--) {
            if(l<0) {
                h++;
            }
            else if(h >= arr.size()) {
                l--;
            }
            else if(x-arr[l] > arr[h]-x) {
                h++;
            }
            else {
                l--;
            }
        }
        return vector<int>(arr.begin()+l+1, arr.begin()+h);
    }

    vector<int> twoptrMethod(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size()-1;

        while(right-left >= k) {
            if(abs(arr[left] -x) > abs(arr[right] - x)) {
                left++;
            }
            else {
                right--;
            }
        }
        vector<int>ans(arr.begin()+left, arr.begin()+right+1);
        return ans;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return bs_Method(arr, k, x);
    }
};

int main() {
    Solution sol;

    // Hardcoded testcase
    vector<int> arr = {1,2,3,4,5};
    int k = 4;
    int x = 3;

    vector<int> result = sol.findClosestElements(arr, k, x);

    cout << "Closest elements: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
