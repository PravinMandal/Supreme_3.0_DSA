//leetcode: 994. Rotting Oranges

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        // Queue stores all rotten oranges positions
        // Multi-source BFS starts from all rotten oranges together
        queue<pair<int, int>> q;

        int freshOranges = 0;

        /*
            Initial traversal:
            1. Count fresh oranges
            2. Store all rotten oranges as starting points
        */
        for(int i=0; i<row; i++) {

            for(int j=0; j<col; j++) {

                if(grid[i][j] == 1)
                    freshOranges++;

                if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        // If no fresh oranges exist, no time is required
        if(!freshOranges)
            return 0;


        int minutes = 0;

        // Four possible directions: right, down, left, up
        vector<pair<int, int>> directions = {
            {0, 1}, 
            {1, 0}, 
            {0, -1}, 
            {-1, 0}
        };


        /*
            BFS level represents one minute.

            Every level:
            - Process all currently rotten oranges
            - Make adjacent fresh oranges rotten
            - Add newly rotten oranges for next minute
        */
        while(!q.empty()) {

            bool madeRotten = false;

            // Number of oranges rotten at current minute
            int size = q.size();

            for(int i=0; i<size; i++) {

                pair<int, int> curr = q.front(); 
                q.pop();


                // Check all four neighbouring cells
                for(auto dir : directions) {

                    int newX = curr.first + dir.first;
                    int newY = curr.second + dir.second;


                    /*
                        Conditions:
                        1. New position should be inside grid
                        2. Orange should be fresh

                        Then make it rotten and add to queue.
                    */
                    if(newX >= 0 && newX < row && 
                       newY >= 0 && newY < col && 
                       grid[newX][newY] == 1) {

                        grid[newX][newY] = 2;

                        q.push({newX, newY});

                        freshOranges--;

                        madeRotten = true;
                    }
                }
            }


            // Increase time only if at least one orange became rotten
            if(madeRotten)
                minutes++;
        }


        // If fresh oranges are still remaining, they were unreachable
        if(freshOranges)
            return -1;


        return minutes;
    }
};


int main() {

    Solution obj;

    // Hardcoded test cases

    vector<vector<int>> grid1 = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    vector<vector<int>> grid2 = {
        {2,1,1},
        {0,1,1},
        {1,0,1}
    };

    vector<vector<int>> grid3 = {
        {0,2}
    };


    cout << "Test Case 1 Output: " << obj.orangesRotting(grid1) << endl;
    cout << "Test Case 2 Output: " << obj.orangesRotting(grid2) << endl;
    cout << "Test Case 3 Output: " << obj.orangesRotting(grid3) << endl;


    return 0;
}