//leetcode: 2360. Longest Cycle in a Graph
// BFS se bhi Try kro

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int node, vector<int>& edges, vector<bool>& visited, vector<int>& dfsTracker, int& len, int currLen) {

        // No outgoing edge exists
        if(node == -1) return;


        // Mark current node as visited
        visited[node] = true;


        // Get next node in directed graph
        int nextNode = edges[node];


        // Current node does not point anywhere
        if(nextNode == -1) return;


        if(!visited[nextNode]) {

            /*
                Store the distance/time at which this node
                was visited in current DFS path.

                This helps detect cycle length.
            */
            dfsTracker[node] = currLen;


            // Continue DFS to next node
            dfs(nextNode, edges, visited, dfsTracker, len, currLen+1);


        } else if(dfsTracker[nextNode]) {

            /*
                If next node is already visited in the
                current DFS recursion path, then a cycle exists.

                Cycle length =
                current path length - starting point of cycle + 1
            */
            len = max(len, currLen-dfsTracker[nextNode]+1);
        }


        /*
            Remove current node from current DFS path.

            It is not part of any future cycle detection.
        */
        dfsTracker[node] = 0;
    }


    int longestCycle(vector<int>& edges) {

        int n = edges.size();


        // Stores nodes that are completely processed
        vector<bool> visited(n, 0);


        /*
            Stores nodes currently present in DFS recursion stack.

            Value represents the position/time when node
            entered current DFS path.
        */
        vector<int> dfsTracker(n, 0);


        int longestCycleLength = 0;


        for(int i=0; i<n; i++) {

            if(!visited[i]) {

                int len = 0;


                // Start DFS from unvisited node
                dfs(i, edges, visited, dfsTracker, len, 1);


                longestCycleLength = max(longestCycleLength, len);
            }
        }


        // If no cycle exists
        return longestCycleLength == 0 ? -1 : longestCycleLength;
    }
};


int main() {

    Solution obj;


    // Hardcoded test cases

    vector<int> edges1 = {3,3,4,2,3};

    vector<int> edges2 = {2,-1,3,1};

    vector<int> edges3 = {1,2,0};


    cout << "Test Case 1 Output: " << obj.longestCycle(edges1) << endl;
    cout << "Test Case 2 Output: " << obj.longestCycle(edges2) << endl;
    cout << "Test Case 3 Output: " << obj.longestCycle(edges3) << endl;


    return 0;
}