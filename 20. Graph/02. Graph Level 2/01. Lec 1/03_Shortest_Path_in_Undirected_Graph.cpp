//gfg: Shortest Path in Undirected Graph
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
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
    Solution sol;

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
