//gfg: first negative integer in every window of size k
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Given class with FirstNegativeInteger method
class Solution {
public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        deque<int> q;
        vector<int> ans;

        // index store krenge hum queue ke andar kyuki wo hume bata dega
        // ki current element current window ke andar hai ki nhi
        for (int i = 0; i < k; i++) {
            if (arr[i] < 0) {
                q.push_back(i);
            }
        }

        // upr for loop se humne queue mai saare -ve number ke index store kr liya
        // jo first window mai hoga
        if (q.empty()) {
            ans.push_back(0);
        } else {
            int index = q.front();
            int element = arr[index];
            ans.push_back(element);
        }
        // maine ans mai push kr diye jo first -ve number tha first window mai

        for (int i = k; i < n; i++) {
            // removal of element which are not inside current window
            if (!q.empty() && q.front() < i-k+1 ) {
                q.pop_front();
            }
            // addition of new window
            int element = arr[i];
            if (element < 0) {
                q.push_back(i);
            }

            //inserting the element to ans
            if (q.empty()) {
                ans.push_back(0);
            } else {
                int index = q.front();
                int element = arr[index];
                ans.push_back(element);
            }
        }
        return ans;
    }
};

// Main function to test the FirstNegativeInteger method
int main() {
    // Test array and window size
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    // Create an object of the Solution class
    Solution solution;

    // Call the FirstNegativeInteger function
    vector<int> result = solution.FirstNegativeInteger(arr, k);

    // Print the result
    cout << "First negative integer in every window of size " << k << ": ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
