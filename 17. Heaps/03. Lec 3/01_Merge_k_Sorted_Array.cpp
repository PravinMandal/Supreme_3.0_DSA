//gfg: Merge K Sorted Arrays
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Info {
public:
    int data;
    int rIndex;
    int cIndex;
    
    Info(int x, int y, int z) {
        this->data = x;
        this->rIndex = y;
        this->cIndex = z;
    }
};

class compare {
public:
    bool operator()(Info* a, Info* b) {
        //min heap type create kr rhe h
        return a->data > b->data;
    }
};

class Solution {
public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        priority_queue<Info*, vector<Info*>, compare> pq;
        vector<int> ans;
        
        int totalRows = arr.size();
        int totalCols = arr[0].size();
        for (int row = 0; row < totalRows; row++) {
            int element = arr[row][0];
            Info* temp = new Info(element, row, 0);
            pq.push(temp);
        }
        
        //main logic
        while (!pq.empty()) {
            Info* front = pq.top();
            pq.pop();
            
            int frontdata = front->data;
            int front_rIndex = front->rIndex;
            int front_cIndex = front->cIndex;
            ans.push_back(frontdata);
            
            if (front_cIndex + 1 < totalCols) {
                int element = arr[front_rIndex][front_cIndex + 1];
                Info* temp = new Info(element, front_rIndex, front_cIndex + 1);
                pq.push(temp);
            }
        }
        return ans;
    }
};

int main() {
    // Test case: Merge k sorted arrays.
    // Example:
    // arr[] = {
    //   [1, 3, 5, 7],
    //   [2, 4, 6, 8],
    //   [0, 9, 10, 11]
    // }
    // K = 3
    // Expected Output: 0 1 2 3 4 5 6 7 8 9 10 11
    
    vector<vector<int>> arr = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {0, 9, 10, 11}
    };
    int K = arr.size();
    
    Solution sol;
    vector<int> merged = sol.mergeKArrays(arr, K);
    
    cout << "Merged array: ";
    for (int num : merged) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
