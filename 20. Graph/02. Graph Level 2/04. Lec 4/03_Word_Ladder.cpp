//leetcode: 127. Word Ladder
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue< pair<string,int>> q;
        q.push({beginWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());
        //kyuki mai begin word use kr chuka hu, ab mai isko set se remove kr dunga
        st.erase(beginWord);

        while(!q.empty()) {
            pair<string,int> front = q.front();
            q.pop();

            string frontWord = front.first;
            int frontDist = front.second;

            if(frontWord == endWord) {
                return frontDist;
            }
            else {
                for(int index=0; index<endWord.length(); index++) {
                    char originalChar = frontWord[index];
                    for(char ch='a'; ch<='z'; ch++) {
                        frontWord[index] = ch;
                        if(st.find(frontWord) != st.end()) {
                            //set mai present hai, change kr skte hai
                            q.push({frontWord, frontDist+1});
                            st.erase(frontWord);
                        }
                    }
                    frontWord[index] = originalChar;
                }
            }
        }
        return 0;
    }
};

// main function to test the ladderLength function
int main() {
    Solution sol;

    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    int length = sol.ladderLength(beginWord, endWord, wordList);

    if(length == 0) {
        cout << "No transformation sequence possible." << endl;
    } else {
        cout << "Length of shortest transformation sequence: " << length << endl;
    }

    return 0;
}
