//gfg: Painting Fences
//Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 adjacent posts have the same color.

#include<iostream>
using namespace std;

int getPaintWays(int n, int k){

    //base case
    if(n==1){
        return k; //see on notebook notes
    }
    if(n==2){
        return k+ k*(k-1); // k for same , k*(k-1) for diff
    }

    int ans=(k-1) * (getPaintWays(n-1,k) + getPaintWays(n-2,k));
    return ans;
}

int main(){

    int n=4; //number of posts
    int k=3; //number of colors

    int ans=getPaintWays(n,k);
    cout<<"the number of ways of painting the fence: "<<ans<<endl;

    return 0;
}