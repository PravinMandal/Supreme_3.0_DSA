//leetcode: 121. Best Time to Buy and Sell Stock
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        priority_queue<int> pq;
        pq.push(prices[size-1]);
        vector<int> nextBiggest(size, -1);
        nextBiggest[size-1] = -1;
        // isme hum sbka nextBiggest element nikal le rhe hai
        // phir isse hume mil jayega difference (max profit)
        for(int i=size-2; i>=0; i--) {
            if(prices[i] < pq.top()) {
                nextBiggest[i] = pq.top();
            }
            else {
                nextBiggest[i] = -1;
            }
            pq.push(prices[i]);
        }

        int ans = INT_MIN;
        for(int i=0; i<size; i++) {
            ans = max(ans, nextBiggest[i] - prices[i]);
        }
        if(ans < 1) return 0;
        return ans;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int minTillNow = INT_MAX;
        int profit = 0;
        for(int i=0; i<prices.size(); i++) {
            if(prices[i] < minTillNow) {
                minTillNow = prices[i];
            }
            profit = max(profit, prices[i] - minTillNow);
        }
        return profit;
    }
};

class Solution3 {
public:
    void solve(vector<int>& prices, int& MinTillNow, int& profit, int i) {
        if(i >= prices.size()) return;
        
        if(prices[i] < MinTillNow) {
            MinTillNow = prices[i];
        }
        profit = max(profit, prices[i] - MinTillNow);
        solve(prices, MinTillNow, profit, i+1);
    }
    int maxProfit(vector<int>& prices) {
        int MinTillNow = INT_MAX;
        int profit = 0;
        int i=0;
        solve(prices, MinTillNow, profit, i);
        return profit;
    }
};

int main() {
    Solution3 sol;

    // Hardcoded testcase 1
    vector<int> prices1 = {7,1,5,3,6,4};
    cout << "Max Profit (Testcase 1): " << sol.maxProfit(prices1) << endl;

    // Hardcoded testcase 2
    vector<int> prices2 = {7,6,4,3,1};
    cout << "Max Profit (Testcase 2): " << sol.maxProfit(prices2) << endl;

    return 0;
}
