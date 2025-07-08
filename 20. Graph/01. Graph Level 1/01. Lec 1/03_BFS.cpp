#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

class Graph {
public:
    //first int -> u
    //second int -> v
    //third int -> wt
    unordered_map<int, list<pair<int,int>>> adjList;

    addEdge(int u, int v, int weight, bool direction) {
        //direction == 0 -> undirected graph
        //direction == 1 -> directed graph
        if(direction == 0) {
            //Undirected edge
            adjList[u].push_back({v, weight});
            adjList[v].push_back({u, weight});
        }
        else {
            //directed edge
            adjList[u].push_back({v, weight});
        }
    }

    void printAdjList(int n) {
        for(int i=0; i<n; i++) {
            cout<<i<<": {";
            list<pair<int,int>> temp = adjList[i];
            for(auto j : temp) {
                //j ek pair hai
                cout<<"("<<j.first<<","<<j.second<<")";
            }
            cout<<"}"<<endl;
        }
    }

    void BFStraversal(int src) {
        queue<int>q;
        unordered_map<int, bool> visited;
        //maintain initial state
        q.push(src);
        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();
            cout<<frontNode<<",";
            for(auto neighbour : adjList[frontNode]) {
                //neighbour pair hai 
                int node = neighbour.first;
                int weight = neighbour.second;
                if(visited[node] == false) {
                    q.push(node);
                    visited[node] = true;
                }
            }
        }
        cout<<endl;
    }
};

int main() {

    Graph g;
    // g.addEdge(0,1,3,1);
    // g.addEdge(0,2,4,1);
    // g.addEdge(1,2,1,1);
    // g.addEdge(2,3,16,1);

    g.addEdge(0,3,16,1);
    g.addEdge(0,5,16,1);
    g.addEdge(0,2,16,1);
    g.addEdge(3,5,16,1);
    g.addEdge(2,5,16,1);
    g.addEdge(5,4,16,1);
    g.addEdge(5,6,16,1);
    g.addEdge(4,1,16,1);
    g.addEdge(6,1,16,1);
    g.printAdjList(7);
    cout<<endl<<"BFS: ";
    g.BFStraversal(0);

    return 0;
}