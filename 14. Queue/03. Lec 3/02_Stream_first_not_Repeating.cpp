//gfg: first non repeating character in a stream
#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

// Given class with FirstNonRepeating method
class Solution {
public:
    string FirstNonRepeating(string &s) {
        unordered_map<char, int> freq;
        string ans = "";
        queue<char> q;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            freq[ch]++;
            q.push(ch);

            while (!q.empty()) {
                char frontElement = q.front();

                if (freq[frontElement] == 1) {
                    // toh yahi mera ans hai
                    // mai queue ke front element ko isiliye consider kr rha hu kyuki
                    // bola h ki ek se zyada non appeared char aaye toh first wala lena h
                    ans.push_back(frontElement);
                    // ab ans aane ke baad break krna pdega kyuki ek hi chahiye
                    break;
                } else {
                    // mtlb front element ki freq 1 se zyada h
                    q.pop(); // kyuki jo element abhi push hua wo pehle se h
                }
            }
            // important condition
            // agar sb duplicate the toh queue empty rhega
            // agar koi bhi unique element hoga toh queue empty nhi hogi
            if (q.empty()) {
                // mtlb koi bhi unique element nhi mila jo ek baar appear hua h
                ans.push_back('#');
            }
        }
        return ans;
    }
};

// Main function (driver code)
int main() {
    // Hardcoded test case
    string A = "aabc";
    Solution obj;

    // Call the function and print the result
    string ans = obj.FirstNonRepeating(A);
    cout << "Input String: " << A << "\n";
    cout << "First Non-Repeating Characters: " << ans << "\n";

    return 0;
}
