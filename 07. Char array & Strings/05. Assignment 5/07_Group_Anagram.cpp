//leetcode: 49. Group Anagrams
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map;

        for(string str : strs) {
            string copy = str;
            sort(copy.begin(), copy.end()); // sorting to create a key
            map[copy].push_back(str);       // group by sorted key
        }
        for(auto i : map) {
            ans.push_back(i.second);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // hardcoded test case
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    
    vector<vector<string>> ans = sol.groupAnagrams(strs);

    // printing result
    cout << "[ ";
    for(auto group : ans) {
        cout << "[ ";
        for(auto word : group) {
            cout << word << " ";
        }
        cout << "]";
    }
    cout << " ]" << endl;

    return 0;
}
