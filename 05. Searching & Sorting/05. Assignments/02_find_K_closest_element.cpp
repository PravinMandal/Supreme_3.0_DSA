//leetcode: 658. Find K Closest Elements
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
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
};

int main() {
    Solution sol;

    // Sample input
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;

    vector<int> result = sol.findClosestElements(arr, k, x);

    cout << "Closest elements are: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
