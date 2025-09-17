//gfg: Generate all Subarrays
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(vector<int>& arr, int i, int j, vector<vector<int>>& ans, vector<int>& temp) {
        if(j >= arr.size()) {
            i++;
            j = i;
            temp.clear();
        }
        if(i >= arr.size()) return;
        
        temp.push_back(arr[j]);
        ans.push_back(temp);
        
        solve(arr, i, j+1, ans, temp);
    }
    vector<vector<int> > getSubArrays(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> temp;
        int i=0;
        int j=i;
        solve(arr, i, j, ans, temp);
        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded testcase
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> result = sol.getSubArrays(arr);

    cout << "All subarrays are:" << endl;
    for(auto& sub : result) {
        for(int x : sub) cout << x << " ";
        cout<<endl;
    }

    return 0;
}
