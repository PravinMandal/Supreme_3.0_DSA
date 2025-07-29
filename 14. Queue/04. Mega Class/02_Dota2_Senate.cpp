//leetcode: 649. Dota2 Senate
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiantQ, direQ;
        int position = 0;
        while (position < senate.length()) {
            char ch = senate[position];
            if (ch == 'R') radiantQ.push(position++);
            else direQ.push(position++);
        }

        while (!radiantQ.empty() && !direQ.empty()) {
            int rFront = radiantQ.front(); radiantQ.pop();
            int dFront = direQ.front(); direQ.pop();

            if (rFront < dFront) {
                radiantQ.push(position++);
            } else {
                direQ.push(position++);
            }
        }

        if (!radiantQ.empty()) return "Radiant";
        else return "Dire";
    }
};

int main() {
    Solution sol;
    string senate = "RDDRR";  // Hardcoded input

    string result = sol.predictPartyVictory(senate);

    cout << "Winning party: " << result << endl;

    return 0;
}
