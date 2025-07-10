#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
  public:
    void topoBFS(int n, unordered_map<int,vector<int>>& adjList, vector<int>& ans) {
        unordered_map<int,int> indegree;
        queue<int>q;
        //inderee initialize krte hai
        for(int i=0; i<n; i++) {
            for(auto nbr : adjList[i]) {
                indegree[nbr]++;
            }
        }
        
        //initial state maintain kr rhe h
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int frontNode = q.front();
            ans.push_back(frontNode);
            q.pop();
            
            //pop krne ke baad dusro ki ingree kam ho gyi hogi
            //update krna hai indegree ke map ko
            //ab mujhe kya krna hai ki jiska indegree 0 hai usse remove krna h
            for(auto nbr : adjList[frontNode]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
            
            
        }
        
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adjList;
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
        }
        
        vector<int>ans;
        
        topoBFS(V,adjList, ans);
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

    cout << "Topological Sort using BFS (Kahn's Algorithm): ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
