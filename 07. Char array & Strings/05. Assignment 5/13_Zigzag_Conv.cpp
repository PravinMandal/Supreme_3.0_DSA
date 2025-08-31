//leetcode: 6. Zigzag Conversion
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;

        int n = s.size();
        string ans = "";

        int cycle = 2 * (numRows - 1);
        vector<int> step1(numRows), step2(numRows);
        for (int i = 0; i < numRows; ++i) {
            step1[i] = cycle - 2 * i; // primary step
            step2[i] = 2 * i;         // alternate step
        }

        for (int i = 0; i < numRows; ++i) {
            int index = i;
            bool check = true;
            while (index < n) {
                ans += s[index];

                // choose step for this turn
                int step = check ? step1[i] : step2[i];

                // if the chosen step is zero, use the other one immediately
                if (step == 0) step = check ? step2[i] : step1[i];

                index += step;
                check = !check;
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> zigzag(numRows);
        int i=0, row=0;
        bool direction = 1; // Top->bottom

        while(true) {
            if(direction) {
                while(row<numRows && i<s.size()) {
                    zigzag[row++].push_back(s[i++]);
                }
                row = row - 2;
            }
            else {
                while(row>=0 && i<s.size()) {
                    zigzag[row--].push_back(s[i++]);
                }
                row = 1;
            }
            if(i >= s.size()) break;
            direction = !direction;
        }
        
        string ans = "";
        for(string str : zigzag) {
            ans += str;
        }
        return ans;
    }
};

int main() {
    Solution2 sol;

    // Hardcoded test cases
    string s1 = "PAYPALISHIRING";
    int rows1 = 3;
    cout << "Input: " << s1 << ", numRows = " << rows1 << endl;
    cout << "Output: " << sol.convert(s1, rows1) << endl << endl;

    string s2 = "PAYPALISHIRING";
    int rows2 = 4;
    cout << "Input: " << s2 << ", numRows = " << rows2 << endl;
    cout << "Output: " << sol.convert(s2, rows2) << endl << endl;

    string s3 = "ABCD";
    int rows3 = 2;
    cout << "Input: " << s3 << ", numRows = " << rows3 << endl;
    cout << "Output: " << sol.convert(s3, rows3) << endl << endl;

    string s4 = "HELLO";
    int rows4 = 1;
    cout << "Input: " << s4 << ", numRows = " << rows4 << endl;
    cout << "Output: " << sol.convert(s4, rows4) << endl << endl;

    return 0;
}
