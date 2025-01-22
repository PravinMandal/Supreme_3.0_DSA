//leetcode: 134. Gas Station
#include <iostream>
#include <vector>
#include <cmath> // for abs function
using namespace std;

// Given class with canCompleteCircuit method
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int balance = 0;
        int deficit = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++) {
            balance = balance + gas[i] - cost[i];
            // if balance +ve aaya toh koi baat nhi thik hai
            // -ve aaya mtlb deficit
            if (balance < 0) {
                deficit = deficit + abs(balance);
                // deficit aaya hai mtlb aage nhi jaa paaye
                // iska mtlb start update hoga
                start = i + 1;
                balance = 0;
            }
        }

        // check if the total balance after covering the deficit is non-negative
        if (balance - deficit >= 0) {
            return start;
        } else {
            return -1;
        }
    }
};

// Main function (driver code)
int main() {
    // Hardcoded test case
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    Solution obj;

    // Call the function and print the result
    int result = obj.canCompleteCircuit(gas, cost);
    cout << "Gas: ";
    for (int g : gas) cout << g << " ";
    cout << "\nCost: ";
    for (int c : cost) cout << c << " ";
    cout << "\nStarting Index: " << result << "\n";

    return 0;
}
