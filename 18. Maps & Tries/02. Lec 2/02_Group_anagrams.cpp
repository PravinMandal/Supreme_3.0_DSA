//leetcode: 49. Group Anagrams
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> ans;
        for(int i = 0; i < strs.size(); i++) {
            string original = strs[i];
            string copy = strs[i];
            sort(copy.begin(), copy.end());
            map[copy].push_back(original);
        }

        for(auto i : map) {
            ans.push_back(i.second);
        }
        return ans;
    }
};

int main() {
    // Example test case:
    // Input: ["eat", "tea", "tan", "ate", "nat", "bat"]
    // Expected Output: Grouped anagrams, e.g.,
    // [["eat","tea","ate"], ["tan","nat"], ["bat"]]
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    Solution sol;
    vector<vector<string>> ans = sol.groupAnagrams(strs);
    
    cout << "Grouped Anagrams:" << endl;
    for(auto group : ans) {
        for(auto word : group)
            cout << word << " ";
        cout << endl;
    }
    
    return 0;
}
