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

    void BellmanFord(int src, int n) {
        vector<int> dist(n+1, INT_MAX);

        //intitial state
        dist[src] = 0;

        //n-1 baar loop chalao
        for(int i=0; i<n-1; i++) {
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

                    //relaxation
                    if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }

        //n-1 relaxation mai ans aa hi jaata hai, guarantee hai
        //uske baad bhi change ho rha hai mtlb -ve cycle present hai
        //n-1 se ek zyda chalayenge and agar change hua mtlb -ve cycle present hai
        bool negativeCyclePres = false;
        for(auto a : adj) {
                for(auto b : a.second) {
                    int u = a.first;
                    int v = b.first;
                    int w = b.second;

                    //relaxation
                    if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        negativeCyclePres = true;
                        break;
                    }
                }
        }

        if(negativeCyclePres == true) {
            cout<<"Negative Cycle Present"<<endl;
        }
        else {
            cout<<"Negative cycle not present"<<endl;
            //printing
            cout<<"Printing Bellman ford result: "<<endl;
            for(int i=0; i<n; i++) {
                cout<<dist[i]<<" ";
            }
        }

        
    }
};

int main() {

    Graph g;
    g.addEdge(0,1,-1,1);
    g.addEdge(1,4,2,1);
    g.addEdge(4,3,-3,1);
    g.addEdge(3,2,5,1);
    g.addEdge(0,2,4,1);
    g.addEdge(1,2,3,1);
    g.addEdge(3,1,1,1);
    g.addEdge(1,3,2,1);

    //negative cycle present
    // g.addEdge(0,1,-1,1);
    // g.addEdge(1,0,-2,1);
   

    int size = 5;
    g.BellmanFord(0, size);

    return 0;
}