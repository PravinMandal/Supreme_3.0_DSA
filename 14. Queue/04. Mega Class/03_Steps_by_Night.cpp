//gfg: Steps by Knight
// HW: leetcode 862
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool explore(pair<int,int>& front, pair<int, int>& dest, queue<pair<int,int>>& q, vector<vector<bool>>& vis, int n) {
        //knight ke saare possiblities try kr rhe h
        // 8 jagah move kr skta hai ek position se
        int x[] = {1,1,-1,-1,2,2,-2,-2};
        int y[] = {2,-2,2,-2,1,-1,1,-1};
        
        for(int i=0; i<8; i++) {
            int newX = front.first + x[i];
            int newY = front.second + y[i];
            
            //out of bound wale and visited wale pr nhi jaana
            if(newX<0 || newY<0 || newX>=n || newY>=n || vis[newX][newY]) {
                continue;
            }
            if(make_pair(newX,newY) == dest){
                return true;
            }
            q.push({newX, newY});
            vis[newX][newY] = true;
        }
        return false;
    }

    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // step 1: make 0 indexed
        pair<int, int> src = {knightPos[0]-1, knightPos[1]-1};
        pair<int, int> dest = {targetPos[0]-1, targetPos[1]-1};
        
        if(src == dest) return 0;
        vector<vector<bool>>vis(n, vector<bool>(n,false));
        queue<pair<int,int>> q;
        q.push(src);
        q.push({-1,-1}); // NULL add kiye h taaki level pata chal paaye
        
        vis[src.first][src.second] = true;
        int step = 1; //isse hum level count krenge;
        //jitna level hoga utna min step lgega dest pr pohochne ke liye
        
        while(!q.empty()) {
            pair<int,int> front = q.front();
            q.pop();
            if(front == make_pair(-1,-1)) {
                step++;
                if(!q.empty()) {
                    q.push({-1,-1});
                }
            }
            else {
                if(explore(front,dest,q,vis,n))
                    return step;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> knightPos = {4, 5}; // 1-based indexing
    vector<int> targetPos = {1, 1}; // 1-based indexing
    int boardSize = 6;

    int result = sol.minStepToReachTarget(knightPos, targetPos, boardSize);
    cout << "Minimum steps to reach target: " << result << endl;

    return 0;
}
