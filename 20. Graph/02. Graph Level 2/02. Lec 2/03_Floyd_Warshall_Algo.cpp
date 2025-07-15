#include<bits/stdc++.h>
using namespace std;

class Graph{
public: 
    unordered_map<int, list<pair<int,int>> > adj;
    void addEdge(int u, int v, int w, bool direction) {
        if(direction == 0) {
            //undirected graph
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        else {
            adj[u].push_back({v,w});
        }
    }

    void FloydWarshallAlgo(int n) {
        vector<vector<int>>dist(n, vector<int>(n, 1e9));

        //step 1: diagonal 0 kro
        for(int i=0; i<n; i++) {
            dist[i][i] = 0;
        }

        //step 2: copy all distance from graph to matrix
        for(auto a : adj) {
            for(auto b : a.second) {
                //a-> pair<int, pair<int,int>>
                //a.first = u
                //a.second = pair<int,int>
                //b = pair<int,int>
                //b.first = v
                //b.second = weight

                int u = a.first;
                int v = b.first;
                int w = b.second;
                dist[u][v] = w;
            }
        }

        //main logic of helper node
        for(int helper=0; helper<n; helper++) {
            for(int src=0; src<n; src++) {
                for(int dest=0; dest<n; dest++) {
                    dist[src][dest] = min(dist[src][dest], (dist[src][helper] + dist[helper][dest]));
                }
            }
        }

        //printing floyd warshall
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout<<dist[i][j]<<", ";
            }
            cout<<endl;
        }
    }

    
};

int main() {

    Graph g;
    g.addEdge(0,2,-2,1);
    g.addEdge(2,3,2,1);
    g.addEdge(3,1,-1,1);
    g.addEdge(1,0,4,1);
    g.addEdge(1,2,3,1);
    
    int size = 4;
    g.FloydWarshallAlgo(size);

    return 0;
}