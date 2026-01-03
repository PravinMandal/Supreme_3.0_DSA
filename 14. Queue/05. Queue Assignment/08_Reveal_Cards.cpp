//leetcode: 950 - Reveal Cards In Increasing Order

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int> q;
        vector<int> ans(deck.size());

        // put indices of ans into q
        for(int i=0; i<ans.size(); i++) q.push(i);

        // reverse simulation + filling using sorted deck
        for(int i=0; i<deck.size(); i++) {

            // 1. Reveal: place current smallest card at correct index
            int front = q.front(); 
            q.pop();
            ans[front] = deck[i];

            // 2. Move next index to the back of queue (simulation of reveal process)
            if(!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        
        return ans;
    }
};

// ---------------------- MAIN FUNCTION (HARDCODED TESTING) ----------------------
int main() {
    Solution sol;

    // Hardcoded test cases
    vector<int> deck1 = {17,13,11,2,3,5,7};
    // Expected output: [2,13,3,11,5,17,7]
    vector<int> res1 = sol.deckRevealedIncreasing(deck1);

    vector<int> deck2 = {1,1000};
    // Expected output: [1,1000]
    vector<int> res2 = sol.deckRevealedIncreasing(deck2);

    auto print = [&](vector<int>& v) {
        for(int x : v) cout << x << " ";
        cout << endl;
    };

    print(res1);
    print(res2);

    return 0;
}
