//Count Derangements (Permutation such that no element appears in its original position)

#include<iostream>
#include<vector>
using namespace std;

int solve(int n){
    //base case
    if(n==1) return 0;
    if(n==2) return 1;

    int ans= (n-1)*(solve(n-1)+solve(n-2));
    return ans;
}

int main(){

    vector<int>nums={1,2,3,4};
    int n=nums.size();

    int ans=solve(n);
    cout<<"Number of Permutation such that no element appears in its original position: "<<ans;


    return 0;

}