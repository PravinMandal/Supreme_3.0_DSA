//gfg: Eventual Safe States
//leetcode: 802. Find Eventual Safe States

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> safeNodes(int V, vector<vector<int>>& edges) {

        /*
            Reverse Graph Construction

            Original Edge:
                u ---> v

            Reverse Edge:
                v ---> u

            We also maintain the indegree (actually outdegree
            of original graph) for Kahn's Algorithm.
        */
        unordered_map<int, vector<int>> adjList;
        unordered_map<int, int> inorder;

        for(auto i : edges) {

            int u = i[0];
            int v = i[1];

            // Reverse the edge
            adjList[v].push_back(u);

            // Count outgoing edges of original graph
            inorder[u]++;
        }

        vector<int> ans;

        /*
            Queue stores all terminal nodes.

            Terminal nodes have no outgoing edges
            in the original graph, so their indegree
            (outdegree in original graph) becomes zero.
        */
        queue<int> q;

        for(int i = 0; i < V; i++) {

            if(inorder[i] == 0) {

                q.push(i);

                ans.push_back(i);
            }
        }

        /*
            Apply Kahn's Algorithm on the reversed graph.

            Every time a node becomes zero indegree,
            it means all of its outgoing paths eventually
            lead to safe nodes.
        */
        while(!q.empty()) {

            int front = q.front();
            q.pop();

            for(auto nbr : adjList[front]) {

                inorder[nbr]--;

                if(inorder[nbr] == 0) {

                    q.push(nbr);

                    ans.push_back(nbr);
                }
            }
        }

        // Return safe nodes in sorted order
        sort(ans.begin(), ans.end());

        return ans;
    }
};

class Solution2 {
public:

    bool isCyclic(int src,
                  unordered_map<int, vector<int>>& graph,
                  unordered_map<int, bool>& visited,
                  unordered_map<int, bool>& dfsTracker,
                  vector<bool>& safeNodes) {

        // Mark current node as visited
        visited[src] = true;

        // Mark current node as part of current DFS recursion stack
        dfsTracker[src] = true;

        /*
            Traverse all neighbouring nodes.

            If any neighbour leads to a cycle,
            current node is also unsafe.
        */
        for(int nbr : graph[src]) {

            if(!visited[nbr]) {

                bool cyclic = isCyclic(nbr, graph, visited, dfsTracker, safeNodes);

                if(cyclic)
                    return true;

            } else if(visited[nbr] && dfsTracker[nbr]) {

                /*
                    Back edge found.

                    This means the neighbour is already
                    present in the current DFS path,
                    so a cycle exists.
                */
                return true;
            }
        }

        /*
            Remove current node from the recursion stack
            because its DFS is complete.
        */
        dfsTracker[src] = false;

        /*
            No cycle was found through this node.

            Hence, it is an eventual safe node.
        */
        safeNodes[src] = true;

        return false;
    }

    vector<int> safeNodes(int V, vector<vector<int>>& edges) {

        // Build adjacency list from edge list
        unordered_map<int, vector<int>> graph;

        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
        }

        vector<int> ans;

        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsTracker;

        // safeNodes[i] = true means vertex i is eventually safe
        vector<bool> safeNode(V, false);

        /*
            Perform DFS from every unvisited node.

            DFS identifies whether each node
            eventually reaches a cycle or not.
        */
        for(int i = 0; i < V; i++) {

            if(!visited[i])
                isCyclic(i, graph, visited, dfsTracker, safeNode);
        }

        // Collect all safe nodes
        for(int i = 0; i < V; i++) {

            if(safeNode[i])
                ans.push_back(i);
        }

        return ans;
    }
};

int main() {

    Solution obj;

    // Hardcoded Test Case 1
    int V1 = 7;
    vector<vector<int>> edges1 = {
        {0,1},
        {0,2},
        {1,2},
        {1,3},
        {2,5},
        {3,0},
        {4,5}
    };

    // Hardcoded Test Case 2
    int V2 = 5;
    vector<vector<int>> edges2 = {
        {0,1},
        {1,2},
        {2,3},
        {3,4}
    };

    // Hardcoded Test Case 3
    int V3 = 4;
    vector<vector<int>> edges3 = {
        {0,1},
        {1,2},
        {2,0},
        {2,3}
    };

    vector<int> ans1 = obj.safeNodes(V1, edges1);
    vector<int> ans2 = obj.safeNodes(V2, edges2);
    vector<int> ans3 = obj.safeNodes(V3, edges3);

    cout << "Test Case 1 Output: ";
    for(int x : ans1) cout << x << " ";
    cout << endl;

    cout << "Test Case 2 Output: ";
    for(int x : ans2) cout << x << " ";
    cout << endl;

    cout << "Test Case 3 Output: ";
    for(int x : ans3) cout << x << " ";
    cout << endl;

    return 0;
}