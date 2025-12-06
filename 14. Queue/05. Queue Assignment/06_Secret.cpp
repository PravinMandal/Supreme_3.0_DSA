//leetcode: 2327 - Number of People Aware of a Secret
//NS

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1000000007;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        int curr = 0; //active spreders
        int ans = 1; //persons who know the secret

        queue<pair<int, int>> delayQ, forgetQ;
        delayQ.push({1,1});   // (day, count)
        forgetQ.push({1,1});  // (day, count)

        for(int i=1; i<=n; i++) {
            // i -> current day

            // step1 : activate spreaders after delay days
            if(!delayQ.empty() && delayQ.front().first + delay <= i) {
                auto front = delayQ.front();
                delayQ.pop();
                curr = (curr + front.second) % mod; // becoming active spreaders
            }

            // step2 : remove people who forget the secret
            if(!forgetQ.empty() && forgetQ.front().first + forget <= i) {
                auto front = forgetQ.front();
                forgetQ.pop();
                curr = (curr - front.second + mod) % mod; // they stop spreading
                ans = (ans - front.second + mod) % mod;   // also remove from total aware count
            }

            // new spread happens if there are active spreaders
            if(curr > 0) {
                ans = (ans + curr) % mod; // people learn the secret today

                // store the newly added spreaders in queues
                delayQ.push({i, curr});  // they start spreading after delay days
                forgetQ.push({i, curr}); // they will forget after forget days
            }
        }
        return ans % mod;
    }
};

// ---------------- MAIN FUNCTION WITH HARDCODED TEST CASES ----------------
int main() {
    Solution sol;

    // Hardcoded testcases
    cout << sol.peopleAwareOfSecret(6, 2, 4) << endl;  // expected output: 5
    cout << sol.peopleAwareOfSecret(4, 1, 3) << endl;  // expected output: 6
    cout << sol.peopleAwareOfSecret(10, 2, 5) << endl; // sample scenario
    cout << sol.peopleAwareOfSecret(1, 1, 2) << endl;  // only 1 person, output: 1

    return 0;
}
