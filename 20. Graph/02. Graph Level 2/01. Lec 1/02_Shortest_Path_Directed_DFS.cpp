//topological order mujhe ek aisa sequence deta h jisse mai minimum distance ki updation kr skta hu
//isse guarantee milti h ki jis node ka minimum maine set kr diya wo change nhi hoga
#include<bits/stdc++.h>
using namespace std;

class Graph{
public: 
    unordered_map<int, list<pair<int,int>> > adj;
    void addEdge(int u, int v, int wt, bool direction) {
        //direction == 0 -> undirected
        //direction == 1 -> directed
        if(direction == 0) {
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        else {
            adj[u].push_back({v,wt});
        }
    }

    void topoSortDFS(int src, unordered_map<int, bool>& vis, stack<int>& ans) {
        vis[src] = true;

        for(auto nbr : adj[src]) {
            if(!vis[nbr.first]) {
                topoSortDFS(nbr.first, vis, ans);
            }
        }
        ans.push(src);

    }

    void shortestPathDFS(int src) {
        stack<int> topoOrder;
        unordered_map<int, bool> vis;
        topoSortDFS(src, vis, topoOrder);

        //ab mere pass topo order ka stack ready hai
        int n = topoOrder.size();
        vector<int> dist(n, INT_MAX);

        //initial state maintain
        src = topoOrder.top();
        topoOrder.pop();

        dist[src] = 0;
        
        for(auto nbr : adj[src]) {
            //nbr -> {v,wt}
            int node = nbr.first;
            int weightDist = nbr.second;
            if(dist[src] + weightDist < dist[node]) {
                dist[node] = dist[src] + weightDist;
            }
        }

        //main logic
        while(!topoOrder.empty()) {
            int frontTop = topoOrder.top();
            topoOrder.pop();

            for(auto nbr : adj[frontTop]) {
                //nbr -> {v,wt}
                int node = nbr.first;
                int weightDist = nbr.second;
                if(dist[frontTop] + weightDist < dist[node]) {
                    dist[node] = dist[frontTop] + weightDist;
                }
            }
        }

        cout<<"Printing Distance: ";
        for(auto i : dist) {
            cout<<i<<" ";
        }cout<<endl;


    }
};

int main() {
    Graph g;
    g.addEdge(0,4,3,1);
    g.addEdge(0,1,5,1);
    g.addEdge(0,2,13,1);
    g.addEdge(1,4,1,1);
    g.addEdge(1,2,7,1);
    g.addEdge(4,3,6,1);
    g.addEdge(3,2,2,1);

    int src = 0;
    g.shortestPathDFS(src);


    return 0;
}