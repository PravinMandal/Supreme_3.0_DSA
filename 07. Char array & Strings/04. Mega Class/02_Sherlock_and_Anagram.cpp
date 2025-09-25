//hackerrank: Sherlock and Anagrams
#include <bits/stdc++.h>
using namespace std;

int sherlockAndAnagrams(string s) {
    int ans = 0;
    unordered_map<string, int> freq;
    for(int i=0; i<s.size(); i++) {
        string str = "";
        for(int j=i; j<s.size(); j++) {
            str.push_back(s[j]);
            sort(str.begin(), str.end());
            if(freq.find(str) != freq.end()) {
                ans += freq[str];
            }
            freq[str]++;
        }
    }

    //or
    // jo answer mai insertion kr rhe hai usko combination wale formula se bhi kr skte the
    // for(auto it : freq) {
    //     int count = it.second;
    //     if(count > 1) {
    //         ans += (count * (count-1))/2; // combination wale formula se nikale nC2;
    //     }
    // }
    return ans;
}

int main() {
    // Hardcoded testcases
    cout << "Input: \"abba\" -> Output: " << sherlockAndAnagrams("abba") << endl;
    cout << "Input: \"abcd\" -> Output: " << sherlockAndAnagrams("abcd") << endl;
    cout << "Input: \"ifailuhkqq\" -> Output: " << sherlockAndAnagrams("ifailuhkqq") << endl;
    cout << "Input: \"kkkk\" -> Output: " << sherlockAndAnagrams("kkkk") << endl;

    return 0;
}
