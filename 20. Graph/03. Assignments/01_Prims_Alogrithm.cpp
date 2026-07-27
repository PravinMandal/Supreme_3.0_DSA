//gfg: Minimum Spanning Tree (Prim's Algorithm)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    int getMinKey(vector<int>& key, vector<bool>& mst) {

        /*
            Select the vertex which:
            1. Is not yet included in MST.
            2. Has the minimum key value.

            This vertex will be added next to the MST.
        */
        int index = -1;
        int mini = INT_MAX;

        for(int i=0; i<key.size(); i++) {

            if(mst[i] == false && key[i] < mini) {
                mini = key[i];
                index = i;
            }
        }

        return index;
    }

    int spanningTree(int V, vector<vector<int>>& edges) {
        // Build adjacency list:
        // node -> {neighbour, edge weight}
        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        /*
            key[i] =
            Minimum edge weight required to connect
            vertex i to the growing MST.
        */
        vector<int> key(V, INT_MAX);

        // mst[i] tells whether vertex i is already
        // included in the Minimum Spanning Tree.
        vector<bool> mst(V, false);

        // Start Prim's Algorithm from vertex 0
        key[0] = 0;
        
        while(true) {

            // Pick the minimum key vertex
            int u = getMinKey(key, mst);

            // No more reachable vertices
            if(u == -1) break;
            
            // Include current vertex in MST
            mst[u] = true;

            /*
                Update all neighbouring vertices.

                If an edge offers a smaller weight than the
                currently known key value, update it.
            */
            for(auto edge : adj[u]) {

                int v = edge.first;
                int w = edge.second;
                
                if(mst[v] == false && w < key[v]) {
                    key[v] = w;
                }
            }
        }
        
        /*
            After Prim's Algorithm completes,
            key[] contains the weight of every edge
            selected in the MST.

            Sum of all key values = Total MST Weight.
        */
        int totalSumMST = accumulate(key.begin(), key.end(), 0);

        return totalSumMST;
    }
};

int main() {

    Solution obj;

    // Hardcoded Test Case 1
    int V1 = 3;
    vector<vector<int>> edges1 = {
        {0,1,5},
        {1,2,3},
        {0,2,1}
    };

    // Hardcoded Test Case 2
    int V2 = 5;
    vector<vector<int>> edges2 = {
        {0,1,2},
        {0,3,6},
        {1,2,3},
        {1,3,8},
        {1,4,5},
        {2,4,7},
        {3,4,9}
    };

    // Hardcoded Test Case 3
    int V3 = 4;
    vector<vector<int>> edges3 = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };

    cout << "Test Case 1 Output: "
         << obj.spanningTree(V1, edges1) << endl;

    cout << "Test Case 2 Output: "
         << obj.spanningTree(V2, edges2) << endl;

    cout << "Test Case 3 Output: "
         << obj.spanningTree(V3, edges3) << endl;

    return 0;
}