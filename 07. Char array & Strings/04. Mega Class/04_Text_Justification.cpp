//leetcode: 68. Text Justification

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        // Iterate over all words
        for(int i=0; i<words.size(); i++) {

            string line = "";

            // temp will store words for current line
            vector<string> temp;

            // total characters (without spaces)
            int totalChar = 0;

            // Try to fit as many words as possible in current line
            // Condition ensures total length + minimum required spaces <= maxWidth
            while(i<words.size() && totalChar + words[i].length() + temp.size() <= maxWidth) {
                totalChar += words[i].length(); 
                temp.push_back(words[i]);
                i++;
            }

            // Adjust index because for loop will increment it
            i--;

            // Total spaces to distribute
            int spaces = maxWidth - totalChar; 

            int noOfWords = temp.size();

            // Case 1: More than one word in line
            if(noOfWords > 1) {

                // Equal spaces between words
                int spacesBetween = spaces/(noOfWords-1);

                // Extra spaces to distribute from left
                int extraSpaces = spaces % (noOfWords-1);

                // Special case: last line -> left justified
                if(i == words.size()-1) {

                    for(int k=0; k<temp.size(); k++) {
                        line += temp[k];

                        if(k != temp.size()-1)
                            line.push_back(' ');
                    }

                    // Fill remaining spaces at end
                    while(line.length() < maxWidth) {
                        line.push_back(' ');
                    }

                    ans.push_back(line);
                    continue;
                }

                // Normal full justification
                for(int k=0; k<temp.size(); k++) {

                    line += temp[k];

                    if(k == temp.size()-1) continue;

                    // Add equal spaces
                    for(int j=0; j<spacesBetween; j++) {
                        line.push_back(' ');
                    }

                    // Add one extra space if available
                    if(extraSpaces) {
                        line.push_back(' ');
                        extraSpaces--;
                    }
                }
            } 

            // Case 2: Only one word in line
            else if(noOfWords == 1) {

                line += temp[0];

                // Pad all remaining spaces to the right
                for(int j=0; j<spaces; j++) {
                    line.push_back(' ');
                }
            }

            // Add constructed line to answer
            ans.push_back(line);
        }

        string back = ans[ans.size()-1];

        return ans;
    }
};

int main() {

    // Hardcoded test case
    vector<string> words = {"This","is","an","example","of","text","justification."};
    int maxWidth = 16;

    Solution obj;

    vector<string> result = obj.fullJustify(words, maxWidth);

    cout << "Justified Text:\n";
    for(string &line : result) {
        cout << "\"" << line << "\"" << endl;
    }

    return 0;
}