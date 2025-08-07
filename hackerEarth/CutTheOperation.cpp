#include <bits/stdc++.h>
using namespace std;

long long CutTheOperations(int N, int K, vector<int> A) {
    map<long long, int> freq;

    // Count frequency of each number
    for (auto x : A) freq[x]++;

    // Sort keys in increasing order
    for (auto it : freq) {
        long long x = it.first;

        // Try to merge x*K into x if possible
        long long next = x * K;

        if (freq.find(next) != freq.end()) {
            int mergeable = min(freq[x], freq[next]);
            freq[next] -= mergeable;
            // We can merge 'mergeable' times
        }
    }

    // Count how many numbers have non-zero frequency left
    long long result = 0;
    for (auto it : freq) {
        if (it.second > 0) result++;
    }

    return result;
}



void runTest(int testNum, int N, int K, vector<int> A, long long expected) {
    long long result = CutTheOperations(N, K, A);
    if (result == expected) {
        cout << "Test Case " << testNum << " Passed\n";
    } else {
        cout << "Test Case " << testNum << " Failed\n";
        cout << "   Expected: " << expected << "\n";
        cout << "   Got     : " << result << "\n";
    }
}

int main() {
    // Sample Test Cases
    runTest(1, 3, 2, {3, 3, 4}, 0);
    runTest(2, 5, 5, {1, 3, 0, 3, 1}, 4);

    // Custom Test Cases
    runTest(3, 6, 5, {1, 1, 1, 1, 1, 1}, 6); // should need 6 ops (2 windows)
    runTest(4, 4, 0, {0, 0, 0, 1}, 1);       // one increment
    runTest(5, 5, 10, {11, 11, 11, 11, 11}, 0); // already valid

    return 0;
}
