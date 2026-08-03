//leetcode: 1319. Number of Operations to Make Network Connected

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int src, unordered_map<int, bool>& visited, unordered_map<int, vector<int>>& adjList) {

        // Mark current computer as visited
        visited[src] = true;

        /*
            Visit all directly connected computers.

            DFS ensures that every computer belonging to the
            same connected component gets visited.
        */
        for(int nbr : adjList[src]) {

            if(!visited[nbr]) {
                dfs(nbr, visited, adjList);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        /*
            To connect n computers,
            at least (n-1) cables are required.

            If fewer cables exist,
            it is impossible to connect the entire network.
        */
        if(connections.size() < n-1) return -1;

        // Build an undirected graph.
        unordered_map<int, vector<int>> adjList;

        for(auto i : connections) {

            int u = i[0];
            int v = i[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        unordered_map<int, bool> visited;

        int ans = 0;

        /*
            Count the number of connected components.

            Every DFS call starts from an unvisited node
            and discovers one complete connected component.
        */
        for(int i = 0; i < n; i++) {

            if(!visited[i]) {

                dfs(i, visited, adjList);

                ans++;
            }
        }

        /*
            If there are 'ans' connected components,
            we need exactly (ans-1) cables
            to connect them together.
        */
        return ans-1;
    }
};

class Solution2 {
public:

    // Union by Rank
    void unionSet(int u, int v, vector<int>& rank, vector<int>& parent) {

        /*
            Attach the tree with smaller rank
            under the tree with larger rank.

            Rank represents an estimate of tree height.
        */
        if(rank[u] < rank[v]) {

            rank[v]++;
            parent[u] = v;

        } else {

            rank[u]++;
            parent[v] = u;
        }
    }

    // Find with Path Compression
    int getParent(int node, vector<int>& parent) {

        // Root node found
        if(node == parent[node])
            return node;

        /*
            Path Compression:

            Make every node on the path point
            directly to the ultimate parent.

            This significantly reduces the tree height
            and makes future find operations almost O(1).
        */
        return parent[node] = getParent(parent[node], parent);
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        /*
            At least (n-1) edges are required
            to connect n nodes.

            If fewer edges exist,
            it is impossible.
        */
        if(connections.size() < n-1)
            return -1;

        vector<int> parent(n);
        vector<int> rank(n, 0);

        // Initially every node is its own parent.
        for(int i = 0; i < n; i++)
            parent[i] = i;

        int extraEdge = 0;

        /*
            Process every connection.

            If endpoints belong to different components,
            merge them.

            Otherwise this edge is redundant.
        */
        for(auto connection : connections) {

            int u = connection[0];
            int v = connection[1];

            u = getParent(u, parent);
            v = getParent(v, parent);

            if(v != u) {

                unionSet(u, v, rank, parent);

            } else {

                extraEdge++; // iska koi use nhi hai abhi, kyuki less edges (-1 wala case) upr hi handle kar liye
            }
        }

        /*
            Every root node represents one connected component.
        */
        int disconnectedComponents = 0;

        for(int i = 0; i < n; i++) {

            if(parent[i] == i)
                disconnectedComponents++;
        }

        /*
            To connect k disconnected components,
            we need exactly (k-1) operations.
        */
        return disconnectedComponents - 1;
    }
};

int main() {

    Solution2 obj;

    // ---------------- Test Case 1 ----------------
    int n1 = 4;
    vector<vector<int>> connections1 = {
        {0,1},
        {0,2},
        {1,2}
    };

    // ---------------- Test Case 2 ----------------
    int n2 = 6;
    vector<vector<int>> connections2 = {
        {0,1},
        {0,2},
        {0,3},
        {1,2},
        {1,3}
    };

    // ---------------- Test Case 3 ----------------
    int n3 = 6;
    vector<vector<int>> connections3 = {
        {0,1},
        {0,2},
        {0,3},
        {1,2}
    };

    cout << "Test Case 1 Output: "
         << obj.makeConnected(n1, connections1) << endl;

    cout << "Test Case 2 Output: "
         << obj.makeConnected(n2, connections2) << endl;

    cout << "Test Case 3 Output: "
         << obj.makeConnected(n3, connections3) << endl;

    return 0;
}