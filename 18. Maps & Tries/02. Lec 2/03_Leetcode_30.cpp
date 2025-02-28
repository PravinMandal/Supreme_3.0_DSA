//leetcode: 30. Substring with Concatenation of All Words
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    unordered_map<string, int> map;
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        for(int i = 0; i < words.size(); i++) {
            map[words[i]]++;
        }

        int wordlength = words[0].size();

        //offset logic-> 0,1,2, < wordlength
        //zaroori thodi h ki first index se hi wordlength ke hi element milenge
        //agar starting mai hi 'a' ya kuch random words aa gye toh 
        //toh saare indexes (wordlength) tk check kr lete h
        for(int offset = 0; offset < wordlength; offset++) {
            unordered_map<string, int> visited;

            //ans mila kya ye check krne ke liye we need to track count
            int count = 0;

            //ab mai wordlength ke substring ko uthaunga aur check krunga
            for(int i = offset; i + wordlength <= s.length(); i = i + wordlength) {
                string substr = s.substr(i, wordlength);

                //check wheather substr is valid or not
                if(map.find(substr) == map.end()) {
                    //invalid string 
                    //purane saare answer ko bhulana pdega
                    //new start krna pdega
                    visited.clear();
                    count = 0;
                }
                else {
                    //valid substr
                    visited[substr]++;
                    count++;

                    //GAME CHANGER:- removal
                    while(visited[substr] > map[substr]) {
                        //har word ke removal pr visited aur count dono mai wo word hatega
                        string temp = s.substr(i - (count - 1) * wordlength, wordlength);
                        visited[temp]--;
                        count--;
                    }

                    //ans mila kya
                    if(count == words.size()) {
                        //ans mil gya
                        //mujhe starting index ans mai insert krna h
                        ans.push_back(i - (count - 1) * wordlength);
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    // Example test case from LeetCode 30: Substring with Concatenation of All Words.
    // Input: s = "barfoothefoobarman", words = ["foo","bar"]
    // Expected Output: [0,9] because "barfoo" starts at index 0 and "foobar" starts at index 9.
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};

    Solution sol;
    vector<int> ans = sol.findSubstring(s, words);

    cout << "Starting indices of substrings: ";
    for (int index : ans) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
