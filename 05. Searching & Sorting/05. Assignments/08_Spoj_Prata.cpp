//spoj: PRATA - Roti Prata
#include<bits/stdc++.h>
using namespace std;
 
bool isPossible(vector<int>& cookRank, int nP, int mid) {
    int currP = 0; //initial cooked prata
    for(int i=0; i<cookRank.size(); i++) {
        int R = cookRank[i], j=1;
        int timeTaken = 0;
        while(true) {
            if(timeTaken +(j*R) <= mid) {
                currP++;
                timeTaken += j*R;
                j++;
            }
            else {
                break;
            }
        }
        if(currP >= nP) {
            return true;
        }
    }
    return false;
}
 
int minTimeToCompleteOrder(vector<int>& cookRank, int nP) {
    int s = 0;
    int higestRank = *max_element(cookRank.begin(), cookRank.end());
    int e = higestRank * (nP * (nP+1)>>1);
    int ans = -1;
    
    while(s<=e) {
        int mid = s + ((e-s)>>1);
        if(isPossible(cookRank, nP, mid)) {
            //mid time mai ho gya toh isse zyade time mai bhi ho jayega
            ans = mid;
            e = mid-1;
        }
        else {
            s = mid+1;
        }
    }
    return ans;
}
 
int main() {
    // Hardcoded testcase
    int T = 1;
    cout << "Testcase: " << T << endl;
    
    // Example testcase from SPOJ PRATA:
    // 1
    // 10 4
    // 1 2 3 4
    int nP = 10, nC = 4;
    vector<int> cookRank = {1, 2, 3, 4};
    
    cout << minTimeToCompleteOrder(cookRank, nP) << endl;
    
    return 0;
}
