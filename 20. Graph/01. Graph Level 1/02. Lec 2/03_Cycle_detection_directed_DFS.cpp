#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    bool cycleDetectionDFSdirected(int src, unordered_map<int, bool>& visited, unordered_map<int, vector<int>>& adjList, unordered_map<int, bool>& dfsTracker) {
        visited[src] = true;
        dfsTracker[src] = true;
        
        for(auto nbr : adjList[src]) {
            if(!visited[nbr]) {
               bool ans = cycleDetectionDFSdirected(nbr, visited, adjList, dfsTracker);
               if(ans) {
                   return true;
               }
            }
            else if(visited[nbr] && dfsTracker[nbr]) {
                //repeated bhi hai and same path ka hai 
                //cycle present
                return true;
            }
        }
        //backtrack
        dfsTracker[src] = false;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adjList;
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsTracker;
        
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
        }
        
        for(int i = 0; i < V; i++) {
            adjList[i];         // Ensure every node is present
        }
        
        bool ans = false;
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                ans = cycleDetectionDFSdirected(i, visited, adjList, dfsTracker);
                if(ans) {
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Directed graph with a cycle: 0 → 1 → 2 → 0
    int V1 = 3;
    vector<vector<int>> edgesWithCycle = {{0, 1}, {1, 2}, {2, 0}};
    cout << "Graph 1 has cycle: " << (sol.isCyclic(V1, edgesWithCycle) ? "Yes" : "No") << endl;

    // Directed graph without a cycle: 0 → 1 → 2
    int V2 = 3;
    vector<vector<int>> edgesWithoutCycle = {{0, 1}, {1, 2}};
    cout << "Graph 2 has cycle: " << (sol.isCyclic(V2, edgesWithoutCycle) ? "Yes" : "No") << endl;

    return 0;
}
