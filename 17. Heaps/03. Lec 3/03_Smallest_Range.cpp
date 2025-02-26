//leetcode: 632. Smallest Range Covering Elements from K Lists
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

class Info {
public:
    int data;
    int rIndex;
    int cIndex;

    Info(int a, int b, int c) {
        this->data = a;
        this->rIndex = b;
        this->cIndex = c;
    }
};

class compare {
public:
    bool operator()(Info* a, Info* b) {
        // min heap type create kr rhe h: the smaller data value has higher priority.
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*, vector<Info*>, compare> pq;
        vector<int> ans;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        int totalRow = nums.size();
        // Insert the first element of each list into the min-heap.
        for (int row = 0; row < totalRow; row++) {
            int element = nums[row][0];
            Info* temp = new Info(element, row, 0);
            mini = min(mini, element);
            maxi = max(maxi, element);
            pq.push(temp);
        }
        // Initialize the answer range with the current min and max.
        int min_ans = mini;
        int max_ans = maxi;

        // Main loop: process the min-heap.
        while (!pq.empty()) {
            Info* front = pq.top();
            pq.pop();

            int frontData = front->data;
            int front_rIndex = front->rIndex;
            int front_cIndex = front->cIndex;

            // "ye mai bhool jaata hu" — update mini to the current smallest element.
            mini = front->data;

            // Update the range if the current range is smaller.
            if (maxi - mini < max_ans - min_ans) {
                min_ans = mini;
                max_ans = maxi;
            }

            // If there is a next element in the same row, push it into the heap.
            int currCol = nums[front_rIndex].size();
            if (front_cIndex + 1 < currCol) {
                int element = nums[front_rIndex][front_cIndex + 1];
                Info* temp = new Info(element, front_rIndex, front_cIndex + 1);
                maxi = max(maxi, element);
                pq.push(temp);
            }
            else {
                // Agar ek bhi row ke element khatam ho gye toh stop ho jaunga.
                // Kyuki mujhe range mein saare row ke element chahiye the.
                // Toh ek ke khatam hone ke baad mujhe stop ho jaana chahiye.
                break;
            }
        }
        ans.push_back(min_ans);
        ans.push_back(max_ans);
        return ans;
    }
};

int main() {
    /*
       Example Test Case:
       nums = [
           [4, 10, 15, 24, 26],
           [0, 9, 12, 20],
           [5, 18, 22, 30]
       ]
       
       Expected Output: [20, 24]
       Explanation:
       - One possible smallest range covering at least one element from each list is [20, 24].
    */
    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };

    Solution sol;
    vector<int> range = sol.smallestRange(nums);
    cout << "Smallest Range: [" << range[0] << ", " << range[1] << "]" << endl;

    return 0;
}
