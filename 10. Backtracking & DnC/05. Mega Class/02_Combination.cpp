//leetcode:- 77. Combinations
#include<iostream>
#include<vector>
using namespace std;

void solve(vector<vector<int>>&ans, vector<int>&curr, int n, int k , int start){
    //base case
    if(k==0) // kyuki k kam krte jayenge and k jitna hi element curr mai store kr payenge
    {
        ans.push_back(curr);
        return;
    }

    for(int i=start; i<=n; i++){
        curr.push_back(i);
        solve(ans,curr,n,k-1,i+1);
        curr.pop_back(); //backtracking
    }
}

vector<vector<int>> combine(int n, int k){
    vector<vector<int>>ans;
    vector<int>curr;
    int start=1; //kyuki numbers 1 se start hoga [1,n]

    solve(ans,curr,n,k,start);
    return ans;
}

int main(){

    int n=4; // [1,n] tak numbers
    int k=2; // 2 ke combinations 

    vector<vector<int>>result=combine(n,k);

    cout << "The combinations are:" << endl;
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}