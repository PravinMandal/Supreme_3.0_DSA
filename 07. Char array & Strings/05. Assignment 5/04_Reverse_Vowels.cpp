//leetcode: 345. Reverse Vowels of a String

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;

        // Define a set of vowels (both uppercase and lowercase)
        unordered_set<char> vowels = {
            'a', 'e', 'i', 'o', 'u',
            'A', 'E', 'I', 'O', 'U'
        };

        // Two pointer approach
        while (i <= j) {
            // If s[i] is not a vowel, move forward
            if (vowels.count(s[i]) == 0) {
                i++;
            }
            // If s[j] is not a vowel, move backward
            else if (vowels.count(s[j]) == 0) {
                j--;
            }
            // If both are vowels, swap them
            else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        return s;
    }
};

int main() {
    Solution sol;

    // Leetcode sample testcases
    string s1 = "hello";
    string s2 = "leetcode";

    cout << "Input: " << s1 << " => Output: " << sol.reverseVowels(s1) << endl;
    cout << "Input: " << s2 << " => Output: " << sol.reverseVowels(s2) << endl;

    return 0;
}
