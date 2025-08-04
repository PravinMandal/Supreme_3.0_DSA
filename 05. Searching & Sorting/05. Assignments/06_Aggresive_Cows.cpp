//gfg: Aggressive Cows (Maximum minimum distance between cows)

#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

class Solution {
  public:
    bool isPossible(vector<int>& stalls, int k, int mid) {
        int size = stalls.size();
        int c = 1; // first cow placed at first stall
        int pos = stalls[0]; // last cow placed position

        for(int i = 1; i < size; i++) {
            if(stalls[i] - pos >= mid) {
                //place next cow if the distance is at least mid
                c++;
                pos = stalls[i];
                if(c == k) return true; // all cows placed
            }
        }
        return false; // not able to place all cows
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end()); // sort stall positions
        
        int size = stalls.size();
        int s = 0; // minimum possible distance
        int e = stalls[size - 1] - stalls[0]; // maximum possible distance
        int ans = -1;

        while(s <= e) {
            int mid = s + ((e - s) >> 1);

            if(isPossible(stalls, k, mid)) {
                // if it's possible to place cows with at least 'mid' distance
                ans = mid;
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        return ans; // maximum of all minimum distances found
    }
};

// Driver code
int main() {
    vector<int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;

    Solution sol;
    int result = sol.aggressiveCows(stalls, cows);

    cout << "Maximum minimum distance between cows: " << result << endl;

    return 0;
}
