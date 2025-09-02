//leetcode: 1209. Remove All Adjacent Duplicates in String II
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        string ans = "";
        
        int times = 0;
        for(char ch : s) {
            if(ans.empty()) {
                ans.push_back(ch);
                times = 1;
            }
            else if(ch == ans.back()) {
                times++;
                ans.push_back(ch);
            }
            else {
                //back equal nhi hai current ch ke
                times = 1;
                ans.push_back(ch);
            }
            if(times == k) {
                while(times--) {
                    ans.pop_back();
                }
                //ab iske pehle bhi kuch char hai ab sahi jo 'times' hai
                //ab last se count krna pdega taaki wo aage feed kr paaye
                
                if(!ans.empty()) {
                    char last = ans.back();
                    int cnt = 0;
                    for(int i=ans.size()-1; i>=0 && ans[i] == last; i--) {
                        cnt++;
                    }
                    times = cnt;
                }
                else {
                    times = 0;
                }
            }
        }
        
        return ans;
    }
};

class Solution2 {
public:
    string removeDuplicates(string s, int k) {
        int i=0, j=0;
        vector<int> count(s.size());
        while(j < s.size()) {
            s[i] = s[j];
            count[i] = 1;
            if(i>0 && s[i-1] == s[i]) {
                count[i] += count[i-1];
            }
            if(count[i] == k) {
                i -= k;
            }
            i++; j++;
        }
        return s.substr(0, i);
    }
};

int main() {
    Solution2 sol;

    string s = "deeedbbcccbdaa";
    int k = 3;

    cout << sol.removeDuplicates(s, k) << endl; 
    // Expected output: "aa"
    
    return 0;
}
