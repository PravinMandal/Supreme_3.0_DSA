//leetcode: 347. Top K Frequent Elements

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        
        //freq store kr rha hu
        for(int i=0; i<nums.size(); i++) {
            freq[nums[i]]++;
        }

        //min heap banaya hai
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        for(pair<int, int> i : freq) {
            //second pr freq hai, freq ke based pr sort krenge min heap ka use krke
            pq.push({i.second, i.first});
            if(pq.size() > k) {
                //k se bada hua toh pop, isse k size ka most frequent pq bana hua rhega
                //isse kya hoga ki jo least frequent hoga wo remove ho jayega
                //and min heap lene ka ye fayada ki 'n' space ke jagah 'k' space mai hi ho jayegad
                pq.pop(); //removing least frequent
            }
        }

        vector<int> ans;
        while(!pq.empty()) {
            pair<int,int> num = pq.top();
            // auto [freq, num] = pq.top(); //ye bhi chalega
            pq.pop();
            ans.push_back(num.second);
        }
        return ans;
    }
};

// Driver code
int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    Solution sol;
    vector<int> result = sol.topKFrequent(nums, k);

    cout << "Top " << k << " Frequent Elements: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
