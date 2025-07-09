#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    bool detectCycleUndirectedDFS(int src, unordered_map<int, bool>& visited, unordered_map<int, vector<int>>& adjList, int parent) {
        visited[src] = true;
        int ans = false;
        for(auto nbr : adjList[src]) {
            if(!visited[nbr]) {
                visited[nbr] = true;
                ans = detectCycleUndirectedDFS(nbr, visited, adjList, src);
            }
            else if(visited[nbr] && nbr != parent) {
                //cycle detected
                ans = true;
                break;
            }
        }
        return ans;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int, bool> visited;
        int n = V;
        unordered_map<int, vector<int>> adjList;
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        int parent = -1;
        int ans = false;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                ans = detectCycleUndirectedDFS(i, visited, adjList, parent);
            }
            if(ans) {
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Sample graph with cycle
    int V = 5;
    vector<vector<int>> edgesWithCycle = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0}
    };

    // Sample graph without cycle
    vector<vector<int>> edgesWithoutCycle = {
        {0, 1}, {1, 2}, {2, 3}
    };

    cout << "Graph 1 has cycle: " << (sol.isCycle(V, edgesWithCycle) ? "Yes" : "No") << endl;
    cout << "Graph 2 has cycle: " << (sol.isCycle(V, edgesWithoutCycle) ? "Yes" : "No") << endl;

    return 0;
}
