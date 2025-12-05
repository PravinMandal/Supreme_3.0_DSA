// leetcode: 933 - Number of Recent Calls

#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
    vector<int> arr;
public:
    RecentCounter() {
        // constructor
    }
    
    int ping(int t) {
        arr.push_back(t);
        int count = 0;

        // iterate from the end since only recent values matter
        for(int i = arr.size()-1; i >= 0; i--) {

            // count requests within the 3000ms window
            if(arr[i] >= t-3000 && arr[i] <= t) {
                count++;
            } else {
                // break early because previous values will be even smaller
                break;
            }
        }
        return count;
    }
};


class RecentCounter2 {
    queue<int> q;
public:
    RecentCounter2() {
        
    }
    
    int ping(int t) {
        q.push(t);
        // pop invalid request, older than t-3000
        while(q.front() < t-3000) q.pop();
        return q.size();
    }
};



// ------------------- MAIN FUNCTION (HARDCODED TESTS) -------------------
int main() {
    RecentCounter2 rc;

    // Test cases manually defined instead of cin
    cout << rc.ping(1)    << endl;  // Output: 1
    cout << rc.ping(100)  << endl;  // Output: 2
    cout << rc.ping(3001) << endl;  // Output: 3
    cout << rc.ping(3002) << endl;  // Output: 3

    return 0;
}
