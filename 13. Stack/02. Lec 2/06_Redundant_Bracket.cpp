//gfg: Expression contains redundant bracket or not
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int checkRedundancy(string s) {
        stack<char> st;
        int pair = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                st.push(ch); // Push opening bracket or operator
            } else if (ch == ')') {
                // When closing bracket is found
                if (!st.empty() && st.top() == '(') {
                    pair++;   // Found redundant pair
                    st.pop(); // Remove the '('
                } else {
                    // Remove operators until '(' is found
                    while (!st.empty() && st.top() != '(') {
                        st.pop();
                    }
                    st.pop(); // Remove the '('
                                       
                }
            }
        }
        return pair > 0 ? 1 : 0; // Return 1 if redundancy found, else 0
    }
};

int main() {
    Solution solution;

    // Test cases
    string test1 = "((a+b))"; // Redundant
    string test2 = "(a+(b)/c)"; // redundant
    string test3 = "(a+b*(c-d))"; // Not redundant
    string test4 = "((a+(b)))"; // Redundant

    // Display results
    cout << "Test 1: " << solution.checkRedundancy(test1) << " (Expected: 1)" << endl;
    cout << "Test 2: " << solution.checkRedundancy(test2) << " (Expected: 1)" << endl;
    cout << "Test 3: " << solution.checkRedundancy(test3) << " (Expected: 0)" << endl;
    cout << "Test 4: " << solution.checkRedundancy(test4) << " (Expected: 1)" << endl;

    return 0;
}
