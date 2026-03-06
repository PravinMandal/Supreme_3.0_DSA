//leetcode: 692 Top K Frequent Words

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;

        unordered_map<string, int> mp;

        // Count frequency of each word
        for(string word : words) {
            mp[word]++;
        }

        // Convert map to vector for sorting
        vector<pair<string, int>> arr(mp.begin(), mp.end());

        // Sort by:
        // 1. Higher frequency first
        // 2. If frequency same, lexicographically smaller word first
        sort(arr.begin(), arr.end(), [](const auto &a, const auto &b){
            if(a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });

        // Take first k words
        for(int i = 0; i < k; i++) {
            ans.push_back(arr[i].first);
        }
    
        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    vector<string> words = {"i","love","leetcode","i","love","coding"};
    int k = 2;

    vector<string> result = sol.topKFrequent(words, k);

    // Print result
    for(string s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}