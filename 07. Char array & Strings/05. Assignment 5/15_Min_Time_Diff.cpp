//leetcode: 539. Minimum Time Difference
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;

        //step 1: hours se minutes mai convert kro and store krlo
        for(string str : timePoints) {
            int strminut = 0;
            strminut = (stoi(str.substr(0,2))) * 60;
            strminut += stoi(str.substr(3,2)) ;
            minutes.push_back(strminut);
        }

        //ab bss minimum time difference nikalna hai
        int ans = INT_MAX;
        sort(minutes.begin(), minutes.end());
        for(int i=1; i<minutes.size(); i++) {
            int normalDiff = minutes[i] - minutes[i-1];
            int Diff = (1440 - minutes[i]) + (minutes[i-1]);
            ans = min(ans, min(normalDiff, Diff));
        }

        //last case: first and last element ka;
        int n = minutes.size() -1;
        int Diff = (1440 - minutes[n]) + (minutes[0]);

        ans = min(ans, Diff);

        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case 1
    vector<string> timePoints1 = {"23:59","00:00"};
    cout << "Minimum difference (Test 1): " 
         << sol.findMinDifference(timePoints1) << endl;

    // Hardcoded test case 2
    vector<string> timePoints2 = {"01:01","02:01","03:00"};
    cout << "Minimum difference (Test 2): " 
         << sol.findMinDifference(timePoints2) << endl;

    // Hardcoded test case 3
    vector<string> timePoints3 = {"05:31","22:08","00:35"};
    cout << "Minimum difference (Test 3): " 
         << sol.findMinDifference(timePoints3) << endl;

    return 0;
}
