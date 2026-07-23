//leetcode: 207. Course Schedule
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Solution {
public:
    bool topoSortBFS(unordered_map<int,list<int>>& adj, int n) {
        unordered_map<int,int> indegree;
        vector<int> ans;

        // calculate indegree of all nodes
        for(auto i : adj) {
            int u = i.first;
            for(auto j : i.second) {
                int v = j;
                indegree[j]++;
            }
        }

        queue<int>q;
        // push all nodes with 0 indegree
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int front = q.front();
            ans.push_back(front);
            q.pop();

            for(auto nbr : adj[front]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        return ans.size()==n ? true : false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adj;
        for(auto i : prerequisites) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
        }

        bool ans = topoSortBFS(adj, numCourses);
        return ans;
    }
};

class Solution2 {
public:
    bool isCyclicDFS(int src, unordered_map<int, vector<int>>& adjList, unordered_map<int, bool>& currentPath, unordered_map<int, int>& visited) {
        visited[src] = true;
        currentPath[src] = true;
        for(auto nbr : adjList[src]) {
            if(!visited[nbr]) {
                bool ans = isCyclicDFS(nbr, adjList, currentPath, visited);
                if(ans) return true;
            } else if(currentPath[nbr]) {
                //visited bhi hai and current path mai bhi hai
                return true;
            }
        }
        currentPath[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        for(auto i : prerequisites) {
            int u = i[1];
            int v = i[0];
            adjList[u].push_back(v);
        }

        unordered_map<int, bool> currentPath;
        unordered_map<int, int> visited;
        for(int i=0; i<numCourses; i++) {
            if(!visited[i]) {
                bool ans = isCyclicDFS(i, adjList, currentPath, visited);
                if(ans) return false;
            }
        }
        return true;
    }
};

// main function to test the code
int main() {
    Solution2 sol;

    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 1},
        {3, 2}
    };

    bool result = sol.canFinish(numCourses, prerequisites);

    if(result)
        cout << "All courses can be finished (no cycle in prerequisites)." << endl;
    else
        cout << "Cannot finish all courses (cycle detected in prerequisites)." << endl;

    return 0;
}
