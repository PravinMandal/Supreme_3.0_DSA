//leetcode: 4021. Minimum Operations to Make a Rotated Palindrome I

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int ans = INT_MAX;

        /*
            Try every possible rotation of the string.

            The cost of rotating the string by 'rotation'
            positions is counted directly as 'rotation'.
        */
        for(int rotation=0; rotation<n; rotation++) {

            int operations = rotation;

            /*
                Compare characters from both ends of the
                rotated string.

                Only n/2 pairs need to be checked because
                a palindrome mirrors characters around its center.
            */
            for(int i=0; i<(n/2); i++) {

                int left = s[(i+rotation)%n];
                int right = s[(n-i-1+rotation)%n];

                /*
                    Calculate the number of increments required
                    to change one character into the other.

                    Since the alphabet is circular, both directions
                    are considered and the cheaper one is selected.
                */
                int increment1 = (right-left+26)%26;
                int increment2 = (left-right+26)%26;

                operations += min(increment1, increment2);
            }

            // Keep the minimum cost among all rotations.
            ans = min(ans, operations);
        }

        return ans;
    }
};

int main() {

    Solution obj;

    // Hardcoded Test Case 1
    string s1 = "abc";

    // Hardcoded Test Case 2
    string s2 = "abcd";

    // Hardcoded Test Case 3
    string s3 = "aacecaaa";

    // Hardcoded Test Case 4
    string s4 = "zzzz";

    cout << "Test Case 1 Output: " << obj.minOperations(s1) << endl;
    cout << "Test Case 2 Output: " << obj.minOperations(s2) << endl;
    cout << "Test Case 3 Output: " << obj.minOperations(s3) << endl;
    cout << "Test Case 4 Output: " << obj.minOperations(s4) << endl;

    return 0;
}