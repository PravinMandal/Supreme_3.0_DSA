//gfg: Word Ladder II

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<string>> findSequences(vector<string> &words, string &s, string &e) {

        // Stores all words that are still available for traversal.
        unordered_set<string> st(words.begin(), words.end());

        /*
            Queue stores the complete transformation path instead of
            storing only a single word.

            This allows us to directly obtain every shortest sequence.
        */
        queue<vector<string>> q;

        q.push({s});

        vector<vector<string>> ans;

        /*
            Words visited in the current BFS level.

            They are removed from the set only after the level finishes,
            allowing multiple shortest paths to use the same word
            within the same level.
        */
        vector<string> usedOnLevel;

        usedOnLevel.push_back(s);

        int minSize = INT_MAX;

        // Current BFS level (path length).
        int level = 1;

        while(!q.empty()) {

            vector<string> frontStr = q.front();
            q.pop();

            /*
                If we already found a shortest sequence,
                then any longer sequence cannot be an answer.
            */
            if(!ans.empty() && frontStr.size() > ans[0].size())
                break;

            string backStr = frontStr.back();

            /*
                We have entered a new BFS level.

                Remove all words used in the previous level
                so they cannot be revisited in deeper levels.
            */
            if(level < frontStr.size()) {

                level = frontStr.size();

                for(auto i : usedOnLevel) {
                    st.erase(i);
                }

                usedOnLevel.clear();
            }

            // Found one shortest transformation sequence.
            if(backStr == e) {

                if(ans.empty())
                    ans.push_back(frontStr);

                else if(frontStr.size() == ans[0].size())
                    ans.push_back(frontStr);

                continue;
            }

            /*
                Try changing every character of the current word.

                Every valid dictionary word becomes the next BFS state.
            */
            for(int index = 0; index < backStr.size(); index++) {

                char currChar = backStr[index];

                for(char ch = 'a'; ch <= 'z'; ch++) {

                    if(currChar == ch)
                        continue;

                    backStr[index] = ch;

                    if(st.find(backStr) != st.end()) {

                        frontStr.push_back(backStr);

                        q.push(frontStr);

                        // Backtracking
                        frontStr.pop_back();

                        // Mark this word to be removed
                        // after the current level finishes.
                        usedOnLevel.push_back(backStr);
                    }
                }

                // Restore original character.
                backStr[index] = currChar;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    // ---------------- Test Case 1 ----------------
    vector<string> words1 = {
        "des","der","dfr","dgt","dfs"
    };

    string s1 = "der";
    string e1 = "dfs";

    vector<vector<string>> ans1 = obj.findSequences(words1, s1, e1);

    cout << "Test Case 1:\n";
    for(auto &path : ans1) {
        for(auto &word : path)
            cout << word << " ";
        cout << endl;
    }

    // ---------------- Test Case 2 ----------------
    vector<string> words2 = {
        "hot","dot","dog","lot","log","cog"
    };

    string s2 = "hit";
    string e2 = "cog";

    vector<vector<string>> ans2 = obj.findSequences(words2, s2, e2);

    cout << "\nTest Case 2:\n";
    for(auto &path : ans2) {
        for(auto &word : path)
            cout << word << " ";
        cout << endl;
    }

    // ---------------- Test Case 3 ----------------
    vector<string> words3 = {
        "hot","dot","dog","lot","log"
    };

    string s3 = "hit";
    string e3 = "cog";

    vector<vector<string>> ans3 = obj.findSequences(words3, s3, e3);

    cout << "\nTest Case 3:\n";

    if(ans3.empty()) {
        cout << "No transformation sequence exists.\n";
    }
    else {
        for(auto &path : ans3) {
            for(auto &word : path)
                cout << word << " ";
            cout << endl;
        }
    }

    return 0;
}