//gfg: Strongly Connected Components (Kosaraju's Algo)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    void topoSort(int node, unordered_map<int, bool>& visited, unordered_map<int, vector<int>>& adj, stack<int>& s) {

        // Mark current node as visited
        visited[node] = true;

        // Visit all unvisited neighbours
        for(auto nbr : adj[node]) {
            if(!visited[nbr])
                topoSort(nbr, visited, adj, s);
        }

        //backtrack

        /*
            Node is pushed after processing all its neighbours.

            This ensures nodes are stored according to
            finishing times.

            Node with highest finishing time remains on top.
        */
        s.push(node);
    }

    void dfs(int node, unordered_map<int, bool>& visited, unordered_map<int, vector<int>>& adjNew) {

        // Standard DFS traversal
        visited[node] = true;
        
        for(auto nbr : adjNew[node]) {
            if(!visited[nbr])
                dfs(nbr, visited, adjNew);
        }
    }

    int kosaraju(int V, vector<vector<int>> &edges) {
        
        // Step 1: Build original graph
        unordered_map<int, vector<int>> adj;

        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }
        

        /*
            STEP 2:
            Perform Topological-style DFS

            Store vertices according to finishing time.
        */
        stack<int> s;

        unordered_map<int, bool> visited;

        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                topoSort(i, visited, adj, s);
            }
        }
        
        //Kosaraju algorithm mai hum saare edges ka direction change kr dete hai
        // isse hum jo disconnected components hai usme jaa nhi paate
        // iss tarah se hum disconnected component ko identify kr skte hai

        /*
            STEP 3:
            Reverse all graph edges.

            Original:
            u ---> v

            Reversed:
            v ---> u

            This graph is called Transpose Graph.
        */
        unordered_map<int, vector<int>> adjNew;

        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adjNew[v].push_back(u);
        }
        
        /*
            STEP 4:
            Process nodes in decreasing finishing time
            using stack.

            Every DFS started from an unvisited node
            in transpose graph gives one SCC.
        */
        int count = 0;

        unordered_map<int, bool> visited2;

        while(!s.empty()) {

            int top = s.top();
            s.pop();

            if(!visited2[top]) {

                dfs(top, visited2, adjNew);

                // One complete SCC found
                count++;
            }
        }

        return count;
    }
};

int main() {

    Solution obj;

    // Hardcoded Test Case 1
    int V1 = 5;
    vector<vector<int>> edges1 = {
        {1,0},
        {0,2},
        {2,1},
        {0,3},
        {3,4}
    };

    // Hardcoded Test Case 2
    int V2 = 3;
    vector<vector<int>> edges2 = {
        {0,1},
        {1,2},
        {2,0}
    };

    // Hardcoded Test Case 3
    int V3 = 4;
    vector<vector<int>> edges3 = {
        {0,1},
        {1,2},
        {2,3}
    };

    cout << "Test Case 1 Output: " << obj.kosaraju(V1, edges1) << endl;
    cout << "Test Case 2 Output: " << obj.kosaraju(V2, edges2) << endl;
    cout << "Test Case 3 Output: " << obj.kosaraju(V3, edges3) << endl;

    return 0;
}