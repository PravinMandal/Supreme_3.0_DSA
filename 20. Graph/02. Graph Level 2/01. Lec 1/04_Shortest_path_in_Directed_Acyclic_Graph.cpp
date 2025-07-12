//gfg: Shortest path in Directed Acyclic Graph
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <climits>
using namespace std;

// User function Template for C++
class Solution {
  public:
    void topoSortDFS(int src, unordered_map<int, bool>& vis, stack<int>& ans, unordered_map<int, vector<pair<int,int>>>& adj) {
        vis[src] = true;

        for(auto nbr : adj[src]) {
            if(!vis[nbr.first]) {
                topoSortDFS(nbr.first, vis, ans, adj);
            }
        }
        ans.push(src);
    }
    
    vector<int> shortestPathDFS(int V, int src, unordered_map<int, vector<pair<int,int>>>& adj) {
        stack<int> topoOrder;
        unordered_map<int, bool> vis;
        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                topoSortDFS(i, vis, topoOrder, adj);
            }
        }
        //ab mere pass topo order ka stack ready hai
        vector<int> dist(V, INT_MAX);

        //initial state maintain
        // src = topoOrder.top();
        // topoOrder.pop();

        dist[src] = 0;

        //main logic
        while(!topoOrder.empty()) {
            int frontTop = topoOrder.top();
            topoOrder.pop();
            
            if(dist[frontTop] == INT_MAX) continue;

            for(auto nbr : adj[frontTop]) {
                //nbr -> {v,wt}
                int node = nbr.first;
                int weightDist = nbr.second;
                if(dist[frontTop] + weightDist < dist[node]) {
                    dist[node] = dist[frontTop] + weightDist;
                }
            }
        }
        
        for(int i = 0; i < V; ++i) {
            if(dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int,int>>> adjList;
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adjList[u].push_back({v,w});
        }
        
        vector<int> ans = shortestPathDFS(V, 0, adjList);
        return ans;
    }
};

// main function added for testing
int main() {
    Solution sol;

    // Sample graph:
    // Vertices: 6
    // Edges: (0->1,2), (0->4,1), (1->2,3), (4->2,2), (2->3,6), (4->5,4), (5->3,1)
    int V = 6;
    int E = 7;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {1, 2, 3},
        {4, 2, 2},
        {2, 3, 6},
        {4, 5, 4},
        {5, 3, 1}
    };

    vector<int> result = sol.shortestPath(V, E, edges);

    cout << "Shortest distances from source (0):\n";
    for(int i = 0; i < result.size(); i++) {
        cout << "Node " << i << ": " << result[i] << endl;
    }

    return 0;
}
