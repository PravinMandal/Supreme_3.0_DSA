//leetcode: 443. String Compression
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> s;
        for(int i=0; i<chars.size(); i++) {
            int count = 1;
            while(i+1 < chars.size() && chars[i] == chars[i+1]) {
                count++;
                i++;
            }
            s.push_back(chars[i]);
            if(count > 1) {
                stack<int> st;
                while(count != 0) {
                    int num = count % 10;
                    count = count / 10;
                    st.push(num);
                }
                while(!st.empty()) {
                    int intch = st.top(); st.pop();
                    char ch = intch + '0';
                    s.push_back(ch);
                }
            }
        }
        for(int i=0; i<s.size() && i < chars.size(); i++) {
            chars[i] = s[i];
        }
        return s.size();
    }
};

class Solution2 {
public:
    int compress(vector<char>& s) {
        int index=0, count=1;
        char prev = s[0];
        for(int i=1; i<s.size(); i++) {
            if(s[i] == prev) count++;
            else {
                s[index++] = prev;
                if(count > 1) {
                    int start = index;
                    while(count) {
                        s[index++] = count%10 + '0';
                        count/=10;
                    }
                    reverse(s.begin() + start, s.begin() + index);
                }
                prev = s[i];
                count = 1;
            }
        }

        s[index++] = prev;
        if(count > 1) {
            int start = index;
            while(count) {
                s[index++] = count%10 + '0';
                count/=10;
            }
            reverse(s.begin() + start, s.begin() + index);
        }
        
        return index;
    }
};

int main() {
    Solution2 sol;

    // Hardcoded test case
    vector<char> chars = {'a','a','b','b','c','c','c'};
    
    cout << "Original chars: ";
    for(char c : chars) cout << c << " ";
    cout << endl;

    int newLength = sol.compress(chars);

    cout << "Compressed chars: ";
    for(int i=0; i<newLength; i++) cout << chars[i] << " ";
    cout << endl;

    cout << "New Length: " << newLength << endl;

    return 0;
}
