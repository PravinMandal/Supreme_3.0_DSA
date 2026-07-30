//leetcode: 126. Word Ladder II

#include <bits/stdc++.h>
using namespace std;

class Solution {

    // Stores the shortest level (distance from beginWord) for every visited word.
    unordered_map<string, int> mpp;

    // Stores all shortest transformation sequences.
    vector<vector<string>> ans;

private:

    // DFS is used to backtrack from endWord to beginWord
    // using only the words that belong to the shortest path.
    void dfs(string currWord, string& beginWord, vector<string>& seq) {

        // Base case:
        // If we have reached the begin word,
        // reverse the sequence because we built it backwards.
        if(currWord == beginWord) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int sz = beginWord.size();

        // Current shortest distance of currWord from beginWord.
        int steps = mpp[currWord];

        /*
            Try changing every character of currWord.

            We only move to a word whose level is exactly one less.
            This guarantees that DFS reconstructs only the shortest paths.
        */
        for(int i = 0; i < sz; i++) {

            char original = currWord[i];

            for(char ch = 'a'; ch <= 'z'; ch++) {

                if(ch == original)
                    continue;

                currWord[i] = ch;

                // Valid predecessor in the shortest path.
                if(mpp.find(currWord) != mpp.end() &&
                   mpp[currWord] == steps - 1) {

                    seq.push_back(currWord);

                    dfs(currWord, beginWord, seq);

                    // Backtracking
                    seq.pop_back();
                }
            }

            // Restore original character.
            currWord[i] = original;
        }
    }

public:

    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string>& wordList) {

        // Stores words that are not visited yet.
        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<string> q;

        q.push(beginWord);

        // beginWord is at level 1.
        mpp[beginWord] = 1;

        st.erase(beginWord);

        int sz = beginWord.size();

        /*
            ---------------- BFS ----------------

            BFS computes the minimum distance (level)
            from beginWord to every reachable word.

            The first time we visit a word,
            it is guaranteed to be via the shortest path.
        */
        while(!q.empty()) {

            string front = q.front();
            q.pop();

            int currLevel = mpp[front];

            // Once endWord is reached,
            // its shortest distance has been found.
            if(front == endWord)
                break;

            for(int i = 0; i < sz; i++) {

                char original = front[i];

                for(char ch = 'a'; ch <= 'z'; ch++) {

                    if(ch == original)
                        continue;

                    front[i] = ch;

                    if(st.find(front) != st.end()) {

                        mpp[front] = currLevel + 1;

                        q.push(front);

                        // Remove immediately to avoid revisiting.
                        st.erase(front);
                    }
                }

                // Restore original character.
                front[i] = original;
            }
        }

        /*
            If endWord was reached,
            reconstruct every shortest sequence using DFS.
        */
        if(mpp.find(endWord) != mpp.end()) {

            vector<string> seq;

            seq.push_back(endWord);

            dfs(endWord, beginWord, seq);
        }

        return ans;
    }
};

int main() {

    Solution obj;

    // ---------------- Test Case 1 ----------------
    string beginWord1 = "hit";
    string endWord1 = "cog";

    vector<string> wordList1 = {
        "hot","dot","dog","lot","log","cog"
    };

    vector<vector<string>> ans1 =
        obj.findLadders(beginWord1, endWord1, wordList1);

    cout << "Test Case 1:\n";
    for(auto &path : ans1) {
        for(auto &word : path)
            cout << word << " ";
        cout << endl;
    }

    // ---------------- Test Case 2 ----------------
    Solution obj2;

    string beginWord2 = "hit";
    string endWord2 = "cog";

    vector<string> wordList2 = {
        "hot","dot","dog","lot","log"
    };

    vector<vector<string>> ans2 =
        obj2.findLadders(beginWord2, endWord2, wordList2);

    cout << "\nTest Case 2:\n";

    if(ans2.empty()) {
        cout << "No transformation sequence exists.\n";
    }
    else {
        for(auto &path : ans2) {
            for(auto &word : path)
                cout << word << " ";
            cout << endl;
        }
    }

    // ---------------- Test Case 3 ----------------
    Solution obj3;

    string beginWord3 = "red";
    string endWord3 = "tax";

    vector<string> wordList3 = {
        "ted","tex","red","tax","tad","den","rex","pee"
    };

    vector<vector<string>> ans3 =
        obj3.findLadders(beginWord3, endWord3, wordList3);

    cout << "\nTest Case 3:\n";
    for(auto &path : ans3) {
        for(auto &word : path)
            cout << word << " ";
        cout << endl;
    }

    return 0;
}