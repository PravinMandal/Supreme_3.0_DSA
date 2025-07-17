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
        //q mai word and uska distance store kr rhe h

        unordered_set<string> st(wordList.begin(), wordList.end());
        //kyuki mai begin word use kr chuka hu, ab mai isko set se remove kr dunga

        st.erase(beginWord);

        while(!q.empty()) {
            pair<string,int> front = q.front();
            q.pop();

            string frontWord = front.first;
            int frontDist = front.second;

            if(frontWord == endWord) {
                //ans mil gya ab uske dist ko return krdo
                return frontDist;
            }
            else {
                for(int index=0; index<endWord.length(); index++) {
                    //original word store krke rakh lo
                    char originalChar = frontWord[index];
                    for(char ch='a'; ch<='z'; ch++) {
                        //saare word ko replace kro ek ek krke and
                        //check kro if wo set mai hai ki nhi
                        frontWord[index] = ch;
                        if(st.find(frontWord) != st.end()) {
                            //set mai present hai, change kr skte hai
                            //push krdo
                            q.push({frontWord, frontDist+1});
                            st.erase(frontWord);
                            //ye word use kr liya pura toh delete krdo
                            //nhi kiya toh wapas ye same word bann skta h and
                            //loop mai fass jayenge
                        }
                    }
                    //backtrack
                    //orginal hi rakho warna change ho gya toh durse word nhi bana payenge if
                    //isse through jaana hoga toh kyuki ab wo bacha hi nhi uski jagah kuch or store kr diya
                    //isilye pehle ki tarah kr do
                    //if iss word ko use krenge toh upr hi if condition mai wo set se delete ho jayega
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
