//leetcode: 1631. Path With Minimum Effort
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>> > pq;
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));

        //initialization
        pq.push({0,{0,0}});
        dist[0][0] = 0;

        while(!pq.empty()) {
            pair<int,pair<int,int>> frontNode = pq.top();
            pq.pop();

            int currAbsDifference = frontNode.first;
            int x = frontNode.second.first;
            int y = frontNode.second.second;

            //destination check
            if(x==row-1 && y==col-1) { 
                return dist[x][y];
            }
            else {
                //move left, right, up, down
                int dx[] = {0,0,-1,1};
                int dy[] = {-1,1,0,0};

                for(int i=0; i<4; i++) {
                    int newX = x + dx[i];
                    int newY = y + dy[i];

                    //jidr move kr rhe h wo safe hai bhi ki nhi
                    if(newX >=0 && newX <row && newY >=0 && newY < col) {
                        int newAbsdiff = abs(heights[x][y] - heights[newX][newY]);

                        //as per question absDiff mai MAX wala store krna h
                        int maxAbsdiff = max(currAbsDifference, newAbsdiff);

                        //as per question, effort/dist mai minimum wala store krna h
                        if(maxAbsdiff < dist[newX][newY]) {
                            dist[newX][newY] = maxAbsdiff;
                            //jab bhi new MAXdifference calculate krte h, usse pq mai push krna h
                            pq.push({maxAbsdiff,{newX,newY}});
                        }
                    }
                }
            }
        }
        return 0;
    }
};

// main function to test the minimumEffortPath function
int main() {
    Solution sol;

    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    int effort = sol.minimumEffortPath(heights);

    cout << "Minimum Effort Required: " << effort << endl;

    return 0;
}
