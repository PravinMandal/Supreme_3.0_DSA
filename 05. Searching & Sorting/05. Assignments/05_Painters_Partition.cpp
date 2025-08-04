//gfg: Painter's Partition Problem (Minimize maximum time to complete jobs)

#include <iostream>
#include <vector>
#include <numeric> // for accumulate
using namespace std;

class Solution {
  public:
    bool isPossible(vector<int>& arr, int k, int mid) {
        int size = arr.size();
        int Timesum = 0;
        int p = 1; // number of painters
        for(int i = 0; i < size; i++) {
            if(arr[i] > mid) return false;
            if(Timesum + arr[i] > mid) {
                p++;
                Timesum = arr[i];
                if(p > k) return false;
            }
            else {
                Timesum += arr[i];
            }
        }
        return true;
    }

    int minTime(vector<int>& arr, int k) {
        int s = 0;
        int e = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;

        while(s <= e) {
            int mid = s + ((e - s) >> 1);
            if(isPossible(arr, k, mid)) {
                ans = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return ans;
    }
};

// Driver code
int main() {
    vector<int> jobTimes = {10, 20, 30, 40}; // time to paint each board
    int painters = 2; // number of painters

    Solution sol;
    int result = sol.minTime(jobTimes, painters);

    cout << "Minimum time to paint all boards: " << result << endl;

    return 0;
}
