#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
  public:
    void topoBFS(int n, unordered_map<int,vector<int>>& adjList, vector<int>& ans) {
        unordered_map<int,int> indegree;
        queue<int>q;
        //inderee initialize krte hai
        for(int i=0; i<n; i++) {
            for(auto nbr : adjList[i]) {
                indegree[nbr]++;
            }
        }
        
        //initial state maintain kr rhe h
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int frontNode = q.front();
            ans.push_back(frontNode);
            q.pop();
            
            //pop krne ke baad dusro ki ingree kam ho gyi hogi
            //update krna hai indegree ke map ko
            //ab mujhe kya krna hai ki jiska indegree 0 hai usse remove krna h
            for(auto nbr : adjList[frontNode]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        unordered_map<int,vector<int>> adjList;
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
        }
        
        vector<int>ans;
        
        topoBFS(V,adjList, ans);
        
        if(ans.size() == V) {
            //mtlb topoplogical sorting ho gya
            //and correct aaya 
            //mtlb cyclic nhi h
            return false;
        }
        else {
            //galat aaya topological sorting 
            //cyclic hai
            return true;
        }
    }
};

// main function for testing
int main() {
    Solution sol;

    // Test case 1: Graph with a cycle
    int V1 = 4;
    vector<vector<int>> edges1 = {
        {0, 1}, {1, 2}, {2, 3}, {3, 1}
    };

    // Test case 2: Graph without a cycle
    int V2 = 4;
    vector<vector<int>> edges2 = {
        {0, 1}, {1, 2}, {2, 3}
    };

    cout << "Graph 1 (with cycle): " << (sol.isCyclic(V1, edges1) ? "Cycle detected" : "No cycle") << endl;
    cout << "Graph 2 (acyclic): " << (sol.isCyclic(V2, edges2) ? "Cycle detected" : "No cycle") << endl;

    return 0;
}
