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

    void addEdge(int u, int v, int weight, bool direction) {
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

    void DFShelper(int src, unordered_map<int, bool>& visited) {
        visited[src] = true;
        cout<<src<<", ";
        for(auto nbr : adjList[src]) {
            //nbr is a pair
            int node = nbr.first;
            if(!visited[node]) {
                DFShelper(node, visited);
            }
        }
    }

    void DFStraversal(int n) {
        unordered_map<int, bool> visited;
        //humne for loop mai isiliye kiya hai taaki,
        //hum disconnected graph ko bhi handle kr sake and saare print kara sake
        for(int src=0; src<n; src++) {
            if(!visited[src]) {
                DFShelper(src, visited);
            }   
        }
        
    }
};

int main() {

    Graph g;

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
    cout<<endl<<"DFS: ";
    g.DFStraversal(7);


    return 0;
}