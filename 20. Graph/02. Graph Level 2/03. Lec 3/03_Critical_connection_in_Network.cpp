//leetcode: 1192. Critical Connections in a Network
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;

class Solution {
public:
    void countBridge(int src, int timer, int parent, vector<int>& tin, vector<int>& low,
                     unordered_map<int,bool>& visited, vector<vector<int>>& ans,
                     unordered_map<int, list<int>>& adj) {

        timer++;
        visited[src] = true;
        tin[src] = timer;
        low[src] = timer;

        for(auto nbr : adj[src]) {
            if(nbr == parent) {
                continue;
            }
            else if(!visited[nbr]) {
                countBridge(nbr, timer, src, tin, low, visited, ans, adj);
                low[src] = min(low[src], low[nbr]); 

                if(low[nbr] > tin[src]) {
                    vector<int> temp;
                    temp.push_back(src);
                    temp.push_back(nbr);
                    ans.push_back(temp);
                }
            }
            else {
                low[src] = min(low[src], low[nbr]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        int src = 0;
        int timer = 0;
        int parent = -1;
        vector<int> tin(n);
        vector<int> low(n);
        unordered_map<int,bool> visited;

        unordered_map<int, list<int>> adj;
        for(auto i : connections) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        countBridge(src, timer, parent, tin, low, visited, ans, adj);
        return ans;
    }
};

// main function for testing
int main() {
    Solution sol;

    int n = 5; // number of nodes
    vector<vector<int>> connections = {
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3},
        {3, 4}
    };

    vector<vector<int>> bridges = sol.criticalConnections(n, connections);

    cout << "Bridges (Critical Connections):\n";
    for(auto bridge : bridges) {
        cout << bridge[0] << " - " << bridge[1] << "\n";
    }

    return 0;
}
