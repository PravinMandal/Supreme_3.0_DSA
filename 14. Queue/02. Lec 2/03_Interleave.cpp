//gfg: interleave the first half of the queue with second half
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Given class with rearrangeQueue method
class Solution {
public:
    vector<int> rearrangeQueue(queue<int> &q1) {
        vector<int> ans;
        queue<int> q2;
        int half = q1.size() / 2;

        // Push first half elements of q1 into q2
        while (half--) {
            int element = q1.front();
            q1.pop();
            q2.push(element);
        }
        // Now, q2 contains the first half
        // q1 contains the second half after popping the first half

        int size = q1.size();
        while (size--) {
            ans.push_back(q2.front()); // Push front of q2 into ans
            q2.pop();                  // Remove front of q2
            ans.push_back(q1.front()); // Push front of q1 into ans
            q1.pop();                  // Remove front of q1
        }
        return ans;
    }
};

// Main function to test the rearrangeQueue method
int main() {
    queue<int> q;
    // Push some elements into the queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    // Create an object of the Solution class
    Solution solution;

    // Call the rearrangeQueue function
    vector<int> result = solution.rearrangeQueue(q);

    // Print the result
    cout << "Rearranged queue as vector: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
