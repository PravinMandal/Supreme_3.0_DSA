//gfg: First Repeating Element
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to return the position of the first repeating element.
    int firstRepeated(vector<int> &arr) {
        int n = arr.size();
        int ans = INT_MAX;
        unordered_map<int,int> map;
       
        for(int i = 0; i < n; i++) {
            int element = arr[i];
            if(map.find(element) != map.end()) {
                ans = min(ans, map[element]);
            }
            else {
                map[element] = i + 1;
                //i+1 isiliye kiye kyuki 1 based indexing wala index return krna h
            }
        }
        if(ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};

int main() {
    // Example Test Case:
    // Input: arr = {10, 5, 3, 4, 3, 5, 6}
    // Expected Output: 2
    // Explanation: 
    // - 5 is the first repeating element with first occurrence at position 2 (1-based indexing)
    vector<int> arr = {10, 5, 3, 4, 3, 5, 6};
    
    Solution sol;
    int result = sol.firstRepeated(arr);
    
    cout << "The position of the first repeating element is: " << result << endl;
    return 0;
}
