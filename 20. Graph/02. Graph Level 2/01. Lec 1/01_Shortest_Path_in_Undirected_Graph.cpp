//gfg: Shortest Path in Undirected Graph
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
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
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

//main function for testing
int main() {
    Solution2 sol;

    // Sample graph (undirected)
    // 0 -- 1
    // |    |
    // 2 -- 3
    int n = 4;
    vector<vector<int>> adj(n);
    adj[0] = {1,2};
    adj[1] = {0,3};
    adj[2] = {0,3};
    adj[3] = {1,2};

    int src = 0;

    vector<int> result = sol.shortestPath(adj, src);

    cout << "Shortest distance from node " << src << " to other nodes:" << endl;
    for(int i=0; i<result.size(); i++) {
        cout << "Node " << i << " -> " << result[i] << endl;
    }

    return 0;
}
