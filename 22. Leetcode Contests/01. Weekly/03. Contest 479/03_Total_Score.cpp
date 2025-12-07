//leetcode (contest) - Total Score of All Subarrays With HP Requirement
//Q3. Total Score of Dungeon Runs

#include <bits/stdc++.h>
using namespace std;


//O(n^2), TLE
class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        long long ans = 0;
        int n = damage.size();
        for(int i=0; i<n; i++) {
            long long num = 0;
            int tempHp = hp;
            for(int j=i; j<n; j++) {
                tempHp -= damage[j];
                if(tempHp >= requirement[j]) {
                    num++;
                }
                if(tempHp <= 0) break;
            }
            ans += num;
        }
        return ans;
    }
};

class Solution2 {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n = damage.size();
        vector<long long> pref(n+1, 0);

        // prefix sum of damage array
        for(int i=0; i<n; i++) {
            pref[i+1] = pref[i] + damage[i];
        }

        long long ans = 0;

        for(int i=0; i<n; i++) {
            long long need = pref[i+1] - (hp - requirement[i]);  
            // need = minimum prefix sum index from where subarray damage is enough

            // binary search over prefix array
            int index = lower_bound(pref.begin(), pref.begin()+i+1, need) - pref.begin();

            ans += (i+1-index); // count of valid subarrays ending at i
        }
        return ans;
    }
};

// ---------------------- MAIN FUNCTION (HARDCODED TESTING) ----------------------
int main() {
    Solution2 sol;

    // Hardcoded test samples
    vector<int> damage1 = {2,4,1,3};
    vector<int> req1     = {3,5,2,6};
    cout << sol.totalScore(7, damage1, req1) << endl;  // Example output

    vector<int> damage2 = {5,2,3};
    vector<int> req2     = {4,6,1};
    cout << sol.totalScore(10, damage2, req2) << endl;

    vector<int> damage3 = {1,1,1,1,1};
    vector<int> req3     = {5,4,3,2,1};
    cout << sol.totalScore(5, damage3, req3) << endl;

    return 0;
}
