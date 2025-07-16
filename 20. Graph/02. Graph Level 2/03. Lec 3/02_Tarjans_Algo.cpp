//Bridge in a Graph
//ek aisa edge jisko hatane se no. of components badh jayenge

#include<bits/stdc++.h>
using namespace std;

class Graph{
public: 
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) {
        if(direction == 0) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else {
            adj[u].push_back(v);
        }
    }

    void countBridge(int src, int timer, int parent, vector<int>& tin, vector<int>& low, unordered_map<int,bool>& visited) {
        timer++;
        visited[src] = true;
        tin[src] = timer;
        low[src] = timer;

        //neigbour pr travel krte h
        for(auto nbr : adj[src]) {
            if(nbr == parent) {
                //kyuki undirected graph hai toh nbr parent bhi ho skta h
                continue;
            }
            else if(!visited[nbr]) {
                countBridge(nbr, timer, src, tin, low, visited);
                //abhi mai wapas aaya hu, lets do bridge check
                //ye mai bhool jaata hu
                low[src] = min(low[src], low[nbr]); 

                if(low[nbr] > tin[src]) {
                    //bridge exist
                    cout<<"Bridge Found: ";
                    cout<<src<<"-"<<nbr<<endl;
                }
            }
            else {
                //already visited and not parent
                //low ko update krdo if possible
                low[src] = min(low[src], low[nbr]);
            }
        }
    }
};

int main() {

    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(0,2,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);

    int n = 5;
    int src = 0;
    int timer = 0;
    int parent = -1;
    vector<int> tin(n);
    vector<int> low(n);
    unordered_map<int,bool> visited;

    g.countBridge(src,timer,parent,tin,low,visited);

    return 0;
}