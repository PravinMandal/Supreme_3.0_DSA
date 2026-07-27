//gfg: Kruskal's Minimum Spanning Tree

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Comparator function to sort edges based on weight
    static bool mycomp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

    int findParent(int node, vector<int>& parent) {

        /*
            Find the ultimate parent (representative)
            of the current set.

            Path Compression is used so that future
            searches become much faster.
        */
        if(parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node], parent); // path compression
    }

    void unionSet(int u, int v, vector<int>& rank, vector<int>& parent) {

        /*
            Union by Rank

            Attach the tree having smaller rank
            under the tree having larger rank.

            If both ranks are equal, make one the
            parent and increase its rank.
        */
        if(rank[u] < rank[v]) {

            parent[u] = v;
            rank[v]++;

        } else {

            parent[v] = u;
            rank[u]++;
        }
    }

    int kruskalsMST(int V, vector<vector<int>> &edges) {

        // Initially every vertex is its own parent
        vector<int> parent(V);

        // Rank helps keep the DSU tree balanced
        vector<int> rank(V, 0);

        for(int u = 0; u < V; u++)
            parent[u] = u;

        /*
            Sort all edges in ascending order of weight.

            Kruskal's Algorithm always picks the
            smallest available edge first.
        */
        sort(edges.begin(), edges.end(), mycomp);

        int ans = 0;

        /*
            Process every edge in increasing order.

            If both vertices belong to different sets,
            adding this edge will not create a cycle,
            so include it in the MST.
        */
        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            // Find representatives of both sets
            u = findParent(u, parent);
            v = findParent(v, parent);

            if(u != v) {

                // Include edge in MST
                ans += w;

                // Merge both connected components
                unionSet(u, v, rank, parent);
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    // Hardcoded Test Case 1
    int V1 = 4;
    vector<vector<int>> edges1 = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
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
    int V3 = 3;
    vector<vector<int>> edges3 = {
        {0,1,5},
        {1,2,3},
        {0,2,1}
    };

    cout << "Test Case 1 Output: "
         << obj.kruskalsMST(V1, edges1) << endl;

    cout << "Test Case 2 Output: "
         << obj.kruskalsMST(V2, edges2) << endl;

    cout << "Test Case 3 Output: "
         << obj.kruskalsMST(V3, edges3) << endl;

    return 0;
}