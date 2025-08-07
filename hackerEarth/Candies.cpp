#include <bits/stdc++.h>
using namespace std;

// You have to write your solution here
int solve(int N, long long K, vector<int> A, vector<vector<int>> Edges) {
    unordered_map<int, vector<int>> adj;

    for(auto i : Edges) {
        int u = i[0];
        int v = i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 1;
}

// Test runner function
void runTest(int testNum, int N, long long K, vector<int> A, vector<vector<int>> Edges, int expected) {
    int result = solve(N, K, A, Edges);
    cout << "Test Case #" << testNum << ": ";
    if (result == expected) {
        cout << "PASSED " << endl;
    } else {
        cout << "FAILED " << endl;
        cout << "Expected: " << expected << ", Got: " << result << endl;
    }
}

// Main function with sample test cases
int main() {
    // Test Case 1: Sample Input from the problem statement
    runTest(
        1,
        6, 10,
        {4, 2, 3, 2, 5, 2},
        {{1,2},{1,3},{3,4},{3,5},{5,6}},
        3
    );

    // Test Case 2: All costs are 1, K is enough to go to root from anywhere
    runTest(
        2,
        5, 5,
        {1, 1, 1, 1, 1},
        {{1,2},{2,3},{3,4},{4,5}},
        5
    );

    // Test Case 3: Not enough money for even 1 candy
    runTest(
        3,
        4, 1,
        {5, 6, 7, 8},
        {{1,2},{2,3},{3,4}},
        0
    );

    // Test Case 4: Star shaped tree
    runTest(
        4,
        5, 6,
        {3, 2, 2, 2, 2},
        {{1,2},{1,3},{1,4},{1,5}},
        2
    );

    // Test Case 5: Linear tree with varying costs
    runTest(
        5,
        6, 7,
        {3, 1, 2, 4, 1, 2},
        {{1,2},{2,3},{3,4},{4,5},{5,6}},
        3
    );

    return 0;
}
