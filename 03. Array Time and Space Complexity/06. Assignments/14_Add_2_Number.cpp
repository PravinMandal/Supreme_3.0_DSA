//gfg: Add two numbers represented by two arrays
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string calc_Sum(vector<int>& arr1, vector<int>& arr2) {
        int i=arr1.size()-1;
        int j=arr2.size()-1;
        
        int carry = 0;
        string result = "";
        while(i>=0 || j>=0 || carry) {
            int sum = carry;
            if(i>=0) sum += arr1[i--];
            if(j>=0) sum += arr2[j--];
            
            carry = sum/10;
            result += (sum%10 + '0');
        }   
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;

    // Hardcoded testcase
    vector<int> arr1 = {9, 9, 9, 9}; 
    vector<int> arr2 = {1};

    cout << sol.calc_Sum(arr1, arr2) << endl; 
    // Expected output: "10000"

    return 0;
}
