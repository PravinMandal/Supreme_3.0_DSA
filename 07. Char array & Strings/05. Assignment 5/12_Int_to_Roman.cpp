//leetcode: 12. Integer to Roman
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        map<int, string, greater<int>> map = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        string roman = "";
        for(auto it : map) {
            while(num >= it.first) {
                num -= it.first;
                roman += it.second;
            }
        }
        return roman;
    }
};

class Solution2 {
public:
    string intToRoman(int num) {
        string RomanSymbols[] = {
            "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
        };
        int values[] = {
            1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
        };

        string roman = "";
        for(int i=0; i<13; i++) {
            while(num >= values[i]) {
                roman += RomanSymbols[i];
                num -= values[i];
            }
        }
        return roman;
    }
};

int main() {
    Solution2 sol;

    // Hardcoded test cases
    cout << "3 -> " << sol.intToRoman(3) << endl;        // III
    cout << "4 -> " << sol.intToRoman(4) << endl;        // IV
    cout << "9 -> " << sol.intToRoman(9) << endl;        // IX
    cout << "58 -> " << sol.intToRoman(58) << endl;      // LVIII
    cout << "1994 -> " << sol.intToRoman(1994) << endl;  // MCMXCIV
    cout << "3999 -> " << sol.intToRoman(3999) << endl;  // MMMCMXCIX

    return 0;
}
