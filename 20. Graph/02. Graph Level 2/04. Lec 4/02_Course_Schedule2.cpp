//leetcode: 210. Course Schedule II
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topoSortBFS(unordered_map<int, list<int>>& adj, int n) {
        unordered_map<int,int> indegree;
        vector<int>ans;

        for(auto i : adj) {
            int u = i.first;
            for(auto j : i.second) {
                int v = j;
                indegree[v]++;
            }
        }

        queue<int>q;
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

        if(ans.size() == n) {
            return ans;
        }
        else{
            vector<int> temp;
            return temp;
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adj;
        for(auto i : prerequisites) {
            int u = i[1];
            int v = i[0];
            adj[u].push_back(v);
        }

        vector<int>ans = topoSortBFS(adj, numCourses);
        return ans;
    }
};

// main function to test the code
int main() {
    Solution sol;

    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    vector<int> result = sol.findOrder(numCourses, prerequisites);

    if(result.empty()) {
        cout << "It's not possible to complete all courses (cycle detected)." << endl;
    } else {
        cout << "One possible course order is: ";
        for(int course : result) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}
