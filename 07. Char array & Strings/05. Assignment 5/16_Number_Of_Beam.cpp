//leetcode: 2125. Number of Laser Beams in a Bank
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> beams;

        // Step 1: Count lasers (1s) in each row
        for(string laser : bank) {
            int count = 0;
            for(char ch : laser) {
                int num = ch - '0';
                if(num == 1) {
                    count++;
                }
            }
            if(count != 0)
                beams.push_back(count);
        }

        // Step 2: Each row's beams = lasers in current row * lasers in next row
        int ans = 0;
        for(int i = 0; i < beams.size(); i++) {
            if(i+1 < beams.size())
                ans += beams[i] * beams[i+1];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> bank = {"011001","000000","010100","001000"};

    cout << sol.numberOfBeams(bank) << endl; // Expected output: 8
    return 0;
}
