//hume isme next smallest element find krke uss number ko ans ke vector mai store krna h
//koi bhi element ke just right smallest , mtlb usse chhota hona chahiye
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

void findAns(vector<int>&arr, stack<int>&s, vector<int>&ans){
    int n=arr.size();
    for(int i=n-1; i>=0; i--){
        while(s.top() >= arr[i]){
            //agar top wala element bada h the remove krdo kyuki jo abhi new chhota element h wo chhota h and jo aage aayenge
            //unke liye toh ye jo chhota wala h wo smallest hoga , naaki jisse pop kr rhe h wo kyuki wo comparitively bada h
            s.pop();
        }
        //yaha tak aa ya mtlb ab stack ke top pr jo element h wo element se chhota h
        ans.push_back(s.top());
        s.push(arr[i]);
    }
}

int main(){

    vector<int>v={8,6,2,4,3};
    stack<int>s;
    s.push(-1);
    vector<int>ans;

    findAns(v,s,ans);
    reverse(ans.begin() , ans.end());
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}