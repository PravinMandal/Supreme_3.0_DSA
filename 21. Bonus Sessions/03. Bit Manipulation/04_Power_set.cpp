//gfg: Power Set (Generate All Subsequences)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<string> AllPossibleStrings(string s) {
        vector<string> ans;
        int len = s.length();
        int n = (1 << len); //pow(2, len)
        
        //ye kaam kaise krega
        //0 -> 000
        //1 -> 001
        //2 -> 010 and soo on
        // toh jidr 1 hai uss position wale ko include warna exclude
        //aise subsequence nikal jayega
        for(int num=0; num < n ; num++) {
            //abhi saare num pr jaa rhe h, 000, 001, 010....
            string temp = "";
            //now i will go toh each index and check
            //ki include kru ya exclude
            for(int i=0; i<len; i++) {
                char ch = s[i];
                int mask = (1 << i);
                if(num & mask) {
                    //can include the char
                    temp.push_back(ch);
                }
            }
            if(temp.length() > 0) ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "abc";  // test case
    vector<string> result = sol.AllPossibleStrings(s);
    
    cout << "All subsequences:\n";
    for(string str : result) {
        cout <<  str << " "; 
    }
    return 0;
}
