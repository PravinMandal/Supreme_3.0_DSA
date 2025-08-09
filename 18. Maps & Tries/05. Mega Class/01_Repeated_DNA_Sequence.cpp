// leetcode: 187. Repeated DNA Sequences
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> seqCount;
        vector<string> ans;

        if(s.size() < 10) return {};

        //saare 10 size window ke substr ko store kr le rhe h map mai
        //uski frequency
        for(int i = 0; i <= (int)s.length() - 10; i++) {
            string current10sizewindowsubString = s.substr(i, 10);
            seqCount[current10sizewindowsubString]++;
        }

        // for(auto it : seqCount) {
        //     if(it.second > 1) {
        //         ans.push_back(it.first);
        //     }
        // }
        for(auto it : seqCount) { // normal loop instead of structured bindings
            string str = it.first;
            int freq = it.second;
            if(freq > 1) {
                ans.push_back(str);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test case 1
    string s1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> result1 = sol.findRepeatedDnaSequences(s1);
    cout << "Output 1: ";
    for(auto &seq : result1) cout << seq << " ";
    cout << endl;
    // Expected: ["AAAAACCCCC","CCCCCAAAAA"]

    // Test case 2
    string s2 = "AAAAAAAAAAAAA";
    vector<string> result2 = sol.findRepeatedDnaSequences(s2);
    cout << "Output 2: ";
    for(auto &seq : result2) cout << seq << " ";
    cout << endl;
    // Expected: ["AAAAAAAAAA"]

    // Test case 3
    string s3 = "ACGTACGTAC";
    vector<string> result3 = sol.findRepeatedDnaSequences(s3);
    cout << "Output 3: ";
    for(auto &seq : result3) cout << seq << " ";
    cout << endl;
    // Expected: [] (no repeated 10-letter sequences)

    return 0;
}
