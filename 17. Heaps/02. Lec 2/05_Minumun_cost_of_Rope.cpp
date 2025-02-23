//gfg: Minimum Cost of ropes
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        // Create a min-heap to store the rope lengths.
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // Push all rope lengths into the min-heap.
        for (int i = 0; i < arr.size(); i++) {
            pq.push(arr[i]);
        }
        
        int cost = 0;
        // Continue combining ropes until only one rope remains.
        while (pq.size() > 1) {
            // Remove the two smallest ropes.
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            
            // The cost to connect these two ropes.
            int sum = a + b;
            cost += sum;
            
            // Push the combined rope back into the min-heap.
            pq.push(sum);
        }
        return cost;
    }
};

int main() {
    /*
       Example:
       Input: arr[] = [4, 3, 2, 6]
       
       Explanation:
       1) Connect ropes of lengths 2 and 3. New rope = 2+3 = 5; cost = 5.
          New array: [4, 5, 6]
       2) Connect ropes of lengths 4 and 5. New rope = 4+5 = 9; cost = 5+9 = 14.
          New array: [9, 6]
       3) Connect ropes of lengths 9 and 6. New rope = 9+6 = 15; cost = 14+15 = 29.
       
       Output: 29
    */
    
    vector<int> arr = {4, 3, 2, 6};
    Solution sol;
    int ans = sol.minCost(arr);
    cout << "Minimum cost to connect ropes is: " << ans << endl;
    
    return 0;
}
