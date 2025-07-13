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

    void ShortestPathDijkstra(int src, int n) {
        vector<int> dist(n+1, INT_MAX);
        set<pair<int,int>> st;

        dist[src] = 0;
        st.insert({0,src});

        while(!st.empty()) {
            auto minPair = *(st.begin());
            //minPair ek pair hai
            //{dist, node}
            int distMinPair = minPair.first;
            int nodeMinPair = minPair.second;

            //pop this node
            st.erase(st.begin());

            for(auto nbr : adj[nodeMinPair]) {
                //nbr: {v,w}
                int nbrNode = nbr.first;
                int nbrDist = nbr.second;

                if(dist[nodeMinPair] + nbrDist < dist[nbrNode]) {
                    //2 kaam krna hai
                    //dist array ko set krna hai 
                    //set ko update krna hai
                    auto result = st.find({dist[nbrNode], nbrNode});
                    if(result != st.end()) {
                        //mil gya 
                        st.erase(result);
                    }
                    dist[nbrNode] = dist[nodeMinPair] + nbrDist;
                    st.insert({dist[nbrNode], nbrNode});
                }
            }
        }

        //printing 
        for(int i=0; i<n; i++) {
            cout<<dist[i]<<" ";
        }
    }
};

int main() {

    Graph g;
    g.addEdge(0,5,9,0);
    g.addEdge(0,3,6,0);
    g.addEdge(5,4,2,0);
    g.addEdge(4,3,11,0);
    g.addEdge(5,1,14,0);
    g.addEdge(1,4,9,0);
    g.addEdge(4,2,10,0);
    g.addEdge(1,2,7,0);
    g.addEdge(3,2,15,0);

    int size = 6;
    g.ShortestPathDijkstra(0, 6);

    return 0;
}