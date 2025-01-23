//leetcode: 239. Sliding Window Maximum
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Given class with maxSlidingWindow method
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            int element = nums[i];
            while (!dq.empty() && nums[dq.back()] < element) {
                dq.pop_back();
                // dq.back() se compare krke pop isiliye kr rha hu taaki usse element se pehle ke saare chhote pop hojaye
                // humne ek test case mai dekha ki front mai 1 chhota tha and new 0 se compare kiye toh wo bada tha
                // toh front se pop krte toh prbm tha but back se krne ke baad chhote waale delete ho jayenge 
                // test case: 131205
            }
            dq.push_back(i); // hum dq mai index store kr rhe h taaki sliding window mai check kr paaye ki wo element
            // window mai aayega ki nhi
        }

        int index = dq.front();
        int element = nums[index];
        ans.push_back(element);
        // window ka sbse bada element front mai hi hoga toh uss window ke biggest element ko push kr diye ans mai

        // ab aage ka krenge
        for (int i = k; i < nums.size(); i++) {
            // ab check krte h and jo next window mai nhi aayega usse remove krte hai
            while (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            // saare sliding window problem ke liye ye jo window check ki condition h wo same rhegi

            // ab pehle step ki tarah addition and remove and store krenge
            int element = nums[i];
            while (!dq.empty() && nums[dq.back()] < element) {
                dq.pop_back();
            }
            dq.push_back(i);

            int index = dq.front();
            int ansElement = nums[index];
            ans.push_back(ansElement);
        }
        return ans;
    }
};

// Main function to test the maxSlidingWindow method
int main() {
    // Test array and window size
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    // Create an object of the Solution class
    Solution solution;

    // Call the maxSlidingWindow function
    vector<int> result = solution.maxSlidingWindow(nums, k);

    // Print the result
    cout << "Maximum of each sliding window of size " << k << ": ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
