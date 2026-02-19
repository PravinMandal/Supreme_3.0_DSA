//leetcode: 1878 Get Biggest Three Rhombus Sums in a Grid

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkBounds(vector<vector<int>>& grid, vector<pair<int, int>>& v) {
        int row = grid.size();
        int col = grid[0].size();
        for(auto i : v) {
            if(i.first >= 0 && i.first < row && i.second >= 0 && i.second < col) 
                continue;   
            else 
                return false;   
        }
        return true;
    }

    bool getAllVertices(vector<vector<int>>& grid, vector<pair<int, int>>& v, pair<int, int> c, int& delta) {
        pair<int, int> top = {c.first - delta, c.second};
        pair<int, int> right = {c.first, c.second + delta};
        pair<int, int> bottom = {c.first + delta, c.second};
        pair<int, int> left = {c.first, c.second - delta};

        v[0] = top;
        v[1] = right;
        v[2] = bottom;
        v[3] = left;

        if(checkBounds(grid, v)) {
            return true;
        }
        return false;
    }

    void getAllSum(vector<vector<int>>& grid, int& cx, int& cy, priority_queue<int>& pq) {
        // Single cell rhombus
        pq.push(grid[cx][cy]);

        int delta = 1;
        vector<pair<int, int>> v(4);

        while(getAllVertices(grid, v, {cx, cy}, delta)) {
            pair<int, int> top = v[0];
            pair<int, int> right = v[1];
            pair<int, int> bottom = v[2];
            pair<int, int> left = v[3];

            int csum = grid[top.first][top.second] +
                       grid[right.first][right.second] +
                       grid[bottom.first][bottom.second] +
                       grid[left.first][left.second];

            int diff = right.first - top.first;

            // all cells between top -> right
            for(int i = 1; i < diff; i++) {
                csum += grid[top.first + i][top.second + i];
            }

            // all cells between right -> bottom
            for(int i = 1; i < diff; i++) {
                csum += grid[right.first + i][right.second - i];
            }

            // all cells between bottom -> left
            for(int i = 1; i < diff; i++) {
                csum += grid[bottom.first - i][bottom.second - i];
            }

            // all cells between left -> top
            for(int i = 1; i < diff; i++) {
                csum += grid[left.first - i][left.second + i];
            }

            pq.push(csum);
            delta++;
        }
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> ans;
        priority_queue<int> pq;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                getAllSum(grid, i, j, pq);
            }
        }

        // Extract top 3 distinct rhombus sums
        while(!pq.empty() && ans.size() < 3) {
            int top = pq.top();
            pq.pop();
            if(ans.empty() || ans.back() != top) {
                ans.push_back(top);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    vector<vector<int>> grid = {
        {3, 4, 5, 1, 3},
        {3, 3, 4, 2, 3},
        {20, 30, 200, 40, 10},
        {1, 5, 5, 4, 1},
        {4, 3, 2, 2, 5}
    };

    vector<int> result = sol.getBiggestThree(grid);

    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
