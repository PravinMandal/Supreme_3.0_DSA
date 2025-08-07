//leetcode: 767. Reorganize String
#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

struct comp {
    bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        priority_queue<pair<char, int>, vector<pair<char, int>>, comp> pq;

        for(char ch : s) {
            freq[ch]++;
        }

        for(auto it : freq) {
            pq.push({it.first, it.second});
        }

        string ans = "";

        while(pq.size() > 1) {
            //even number of letters wale handle ho gye
            auto firstelement = pq.top(); pq.pop();
            auto secondelement = pq.top(); pq.pop();

            ans.push_back(firstelement.first);
            ans.push_back(secondelement.first);

            if(--firstelement.second > 0) pq.push(firstelement);
            if(--secondelement.second > 0) pq.push(secondelement);
        }

        //agar ek element bacch gya, odd wala
        if(!pq.empty()) {
            //agar ek char bacha h and uski freq 1 se zyada hua, tab toh possible nhi h
            if(pq.top().second > 1) return "";
            ans.push_back(pq.top().first);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    string input1 = "aab";
    cout << "Output 1: " << sol.reorganizeString(input1) << endl;
    // Possible Output: "aba"

    // Test Case 2
    string input2 = "aaab";
    cout << "Output 2: " << sol.reorganizeString(input2) << endl;
    // Output: ""

    // Test Case 3
    string input3 = "vvvlo";
    cout << "Output 3: " << sol.reorganizeString(input3) << endl;
    // Possible Output: "vlvov"

    return 0;
}
