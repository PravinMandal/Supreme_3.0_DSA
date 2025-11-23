//leetcode: 901 - Online Stock Span

#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st; // Stack to store {price, index}
    int i = 0; // Keeps track of current day index

    StockSpanner() {
        // Constructor — initializes stock spanner
    }
    
    int next(int price) {
        // For the very first price, push a sentinel value
        if(i == 0) st.push({INT_MAX, -1});

        // Pop all previous prices that are less than or equal to current price
        // because the current price covers their span as well
        while (st.top().first <= price) {
            st.pop();
        }

        // The top of the stack now represents the previous higher price
        pair<int, int> top = st.top();

        // Calculate span (difference between current index and last higher price index)
        int ans = i - top.second;

        // Push current {price, index} onto stack
        st.push({price, i});

        // Move to the next day
        i++;

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    // Hardcoded test case:
    // Input: [100, 80, 60, 70, 60, 75, 85]
    // Output: [1, 1, 1, 2, 1, 4, 6]
    StockSpanner* obj = new StockSpanner();

    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    cout << "Stock span results: ";
    for(int price : prices) {
        cout << obj->next(price) << " ";
    }
    cout << endl;

    // Explanation:
    // - Day 1: 100 → No previous higher → span = 1
    // - Day 2: 80  → Previous higher (100) → span = 1
    // - Day 3: 60  → Previous higher (80) → span = 1
    // - Day 4: 70  → Previous higher (80) → span = 2
    // - Day 5: 60  → Previous higher (70) → span = 1
    // - Day 6: 75  → Previous higher (100) → span = 4
    // - Day 7: 85  → Previous higher (100) → span = 6

    return 0;
}
