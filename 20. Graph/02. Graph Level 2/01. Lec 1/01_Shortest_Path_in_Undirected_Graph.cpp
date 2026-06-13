//gfg: Shortest Path in Undirected Graph
// SSSP : Single source shortest Path. ek source se saare node ka shortest path nikalna.
// BFS : saare path(edges) ka weight same hai isiliye work krta hai warna nhi krega.
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // Adjacency list representation of graph
        //parent ka use kr skte hai koi bhi destination se src tak ka path nikalne ke liye
        unordered_map<int, vector<int>> adj;

        // Build undirected graph
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        
        queue<int> q;

        // Start BFS from source node
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        
        // Standard BFS traversal
        while(!q.empty()) {

            auto frontNode = q.front(); 
            q.pop();

            // Visit all neighbours
            for(auto nbr : adj[frontNode]) {

                if(!visited[nbr]) {
                    visited[nbr] = true;

                    // Store parent for path reconstruction
                    parent[nbr] = frontNode;

                    q.push(nbr);
                }
            }
        }
        
        vector<int> ans(V, -1);

        // Calculate shortest distance using parent chain
        for(int i=0; i<V; i++) {

            // If node is unreachable and not source, skip
            if(i != src && parent.find(i) == parent.end()) {
                ans[i] = -1;
                continue;
            }

            int node = i;
            int count = 0;

            // Move backwards using parent array
            while(node != -1) {
                node = parent[node];
                count++;
            }

            ans[i] = count-1; // Distance from source
        }

        return ans;
    }
};


class Solution2 {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(int V, vector<vector<int>>& edges, int src) {
        
        int n = V;
        unordered_map<int, vector<int>> adj;
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(n, -1);
        queue<int>q;
        
        dist[src] = 0;
        q.push(src);
        
        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();
            
            for(auto nbr : adj[frontNode]) {
                if(dist[nbr] == -1) {
                    dist[nbr] = dist[frontNode]+1;
                    q.push(nbr);
                }
            }
        }
        
        return dist;
    }
};

class Solution3 {
  public:
    void getShortestPath(int& src, vector<int>& ans, vector<bool>& visited, unordered_map<int, vector<int>>& adj, int& n) {
        visited[src] = true;
        queue<int> q;
        ans[src] = 0;
        q.push(src);
        
        while(!q.empty()) {
            int frontNode = q.front(); q.pop();
            for(auto nbr : adj[frontNode]) {
                if(!visited[nbr]) {
                    ans[nbr] = ans[frontNode]+1;
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        int n = V;
        unordered_map<int, vector<int>> adj;
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> ans(n, INT_MAX);
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++) {
            getShortestPath(src, ans, visited, adj, n);
        }
        for(int i=0; i<n; i++) {
            if(ans[i] == INT_MAX) {
                ans[i] = -1;
            }
        }
        return ans;
    }
};

//main function for testing
int main() {
    Solution3 sol;

    int V = 4;

    // Sample graph (undirected)
    // 0 -- 1
    // |    |
    // 2 -- 3
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 3}
    };

    int src = 0;

    vector<int> result = sol.shortestPath(V, edges, src);

    cout << "Shortest distance from node " << src << " to other nodes:" << endl;
    for(int i = 0; i < result.size(); i++) {
        cout << "Node " << i << " -> " << result[i] << endl;
    }

    return 0;
}