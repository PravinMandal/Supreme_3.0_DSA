//leetcode: Contest Problem - Q1. Sort Integers by Binary Reflection

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        auto comp = [](int a) {
            string bin = bitset<32>(a).to_string();
            bin = bin.substr(bin.find('1'));
            reverse(bin.begin(), bin.end());
            return stoi(bin, NULL, 2);
        };

        sort(nums.begin(), nums.end(), [&] (int a, int b) {
            int num1 = comp(a);
            int num2 = comp(b);
            if(num1 == num2) return a < b;
            return num1 < num2;
        });
        return nums;
    }
};

class Solution2 {
public:
    int reflection(int x) {
        string rev;
        while(x > 0) {
            rev.push_back((x&1) + '0');   // store binary bits reversed, + '0' taaki int->char mai convert ho jaye
            x = x >> 1;                   // right shift
        }
        return stoi(rev, NULL, 2);        // convert reversed-binary string back to integer
    }

    vector<int> sortByReflection(vector<int>& nums) {
        // sorting based on reflection value
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            int ra = reflection(a);   // reflection of a
            int rb = reflection(b);   // reflection of b

            // if reflection equal → normal numerical comparison
            if(ra == rb) return a < b;

            // otherwise sort by reflection value
            return ra < rb;
        });
        return nums;
    }
};

// ---------------------- MAIN FUNCTION (HARDCODED TESTING) ----------------------
int main() {
    Solution2 sol;

    // Hardcoded test cases
    vector<int> nums1 = {5, 3, 6, 9};    
    // binary forms: 5=101→101, 3=011→110, 6=110→011, 9=1001→1001 
    // reflection values: 5→5, 3→6, 6→3, 9→9 
    // sorted by reflection → {6,5,3,9}

    vector<int> nums2 = {2, 7, 4, 1};  
    vector<int> nums3 = {8, 12, 15, 1, 5};

    auto print=[&](vector<int>& v){
        for(int x:v) cout<<x<<" ";
        cout<<"\n";
    };

    vector<int> res1 = sol.sortByReflection(nums1);
    vector<int> res2 = sol.sortByReflection(nums2);
    vector<int> res3 = sol.sortByReflection(nums3);

    print(res1);
    print(res2);
    print(res3);

    return 0;
}
