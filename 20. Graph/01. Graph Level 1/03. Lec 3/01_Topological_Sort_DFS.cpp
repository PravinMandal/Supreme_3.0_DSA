#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
  public:
    void topoDFS(int src, unordered_map<int, bool>& visited, unordered_map<int,vector<int>>& adjList, vector<int>& ans) {
        visited[src] = true;
        
        for(auto nbr : adjList[src]) {
            if(!visited[nbr]) {
                topoDFS(nbr, visited, adjList, ans);
            }
        }
        
        //backtrack
        ans.push_back(src);
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        unordered_map<int, bool> visited;
        unordered_map<int, vector<int>> adjList;
        vector<int> ans;
        int n = V;
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
        }
        
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                topoDFS(i, visited, adjList, ans);
            }
        }
        
        //yaha pr reverse kr dunga kyuki stack ke jagah vector use kiye hai
        //toh ans ulta aayega
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;

    // Example DAG:
    // 5 → 0 ← 4
    // ↓         ↑
    // 2         1
    // ↓
    // 3

    int V = 6;
    vector<vector<int>> edges = {
        {5, 0}, {4, 0}, {5, 2}, {2, 3}, {3, 1}
    };

    vector<int> result = sol.topoSort(V, edges);

    cout << "Topological Sort: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
