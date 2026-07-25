//leetcode: 547. Number of Provinces

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int src, unordered_map<int, bool>& visited, unordered_map<int, vector<int>>& adjList) {
        visited[src] = true;

        for(auto nbr : adjList[src]) {
            if(!visited[nbr]) 
                dfs(nbr, visited, adjList);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, vector<int>> adjList;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j] == 1)
                    adjList[i].push_back(j);
            }
        }

        unordered_map<int, bool> visited;
        int numberOfProvinces = 0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                numberOfProvinces++;
                dfs(i, visited, adjList);
            }
        }
        return numberOfProvinces;
    }
};

class Solution2 {
public:
    void dfs(int src, unordered_map<int, bool>& visited, vector<vector<int>>& isConnected) {

        // Mark current city as visited
        visited[src] = true;

        /*
            Traverse all possible connected cities.

            If isConnected[src][j] is 1,
            then there is a direct connection between src and j.

            DFS will visit all cities belonging to the same province.
        */
        for(int j=0; j<isConnected.size(); j++) {

            if(isConnected[src][j] && !visited[j]) 
                dfs(j, visited, isConnected);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        // Keeps track of visited cities
        unordered_map<int, bool> visited;

        int numberOfProvinces = 0;

        /*
            Every unvisited city represents a new province.

            Once DFS starts from that city,
            all connected cities of that province are marked visited.
        */
        for(int i=0; i<isConnected.size(); i++) {

            if(!visited[i]) {

                // Found a new province
                numberOfProvinces++;

                dfs(i, visited, isConnected);
            }
        }

        return numberOfProvinces;
    }
};

int main() {

    Solution2 obj;

    // Hardcoded test cases

    vector<vector<int>> isConnected1 = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    vector<vector<int>> isConnected2 = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };

    vector<vector<int>> isConnected3 = {
        {1,1,1},
        {1,1,1},
        {1,1,1}
    };

    cout << "Test Case 1 Output: " << obj.findCircleNum(isConnected1) << endl;
    cout << "Test Case 2 Output: " << obj.findCircleNum(isConnected2) << endl;
    cout << "Test Case 3 Output: " << obj.findCircleNum(isConnected3) << endl;

    return 0;
}