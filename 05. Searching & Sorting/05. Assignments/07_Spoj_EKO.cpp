//spoj: EKO - Eko
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<long long int>& trees, long long int& m, long long int& mid) {
    long long int totalWood = 0;
    for(long long int i=0; i<trees.size(); i++) {
        if(trees[i] > mid) {
            long long int wood = trees[i] - mid;
            totalWood += wood;
        }
    }
    return totalWood >= m;
}

long long int maxSawBladeHeight(vector<long long int>& trees, long long int& m) {
    long long int s = 0;
    long long int  e = *max_element(trees.begin(), trees.end());
    long long int ans = -1;
    while(s<=e) {
        long long int mid = s + ((e-s)>>1);
        if(isPossible(trees, m, mid)) {
            ans = mid;
            s = mid+1;
        }
        else {
            e = mid-1;
        }
    }
    return ans;
}

int main() {
    // Hardcoded testcase
    long long int n = 4, m = 7;
    vector<long long int> trees = {20, 15, 10, 17};

    cout << maxSawBladeHeight(trees, m) << endl;

    return 0;
}
