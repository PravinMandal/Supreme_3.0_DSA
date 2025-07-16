//ye algo hum Strongly connected Component(SCC) dhundhne ke liye use krte hai
//SCC-> ek aisa component jiske andar mai kisi bhi ek random node se shuruwat kr skta hu source node maan skta hu usko
//aur kisi bhi destination ko randomly choose kr skta hu, har ek source node se har ek dest. tak phochne ka rasta agar exist krta h
//toh wo component strongly connected component kehlayega

//hume number of SCC nikalna hai
//similar to No. of island but waha wo sachme disconnected the
//yaha pr connected hai, ek hi component hai jis multiple SCC milenge

//intuition ye hai ki wo disconnected hote ho ans aa jaata
//hume isse virtually disconnect krna pdega
//saare direction ko just ulta kr do
//phir hum ek SCC se dusre mai nhi jaa payenge, phir mil jayega number of SCC

#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    unordered_map<int, list<int> > adj;
    void addEdge(int u, int v, int direction) {
        if(direction == 0) {
            //undirected graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else {
            adj[u].push_back(v);
        }
    }

    void print(int n) {
        for(int i=0; i<n; i++) {
            cout<<i<<" -> {";
            for(auto nbr : adj[i]) {
                cout<<nbr<<",";
            }
            cout<<"}"<<endl;
        }
    }

    void topoSort(stack<int>& st, int i, unordered_map<int, bool>& visited) {
        //dfs se topological order nikalna hai
        for(auto nbr : adj[i]) {
            if(!visited[nbr]) {
                visited[nbr] = true;
                topoSort(st,nbr,visited);
            }
        }
        //backtrack
        st.push(i);
    }

    void dfs(int src, unordered_map<int, bool>& vis, unordered_map<int, list<int>>& adjNew) {
        vis[src] = true;
        cout<<src<<"-";
        for(auto nbr : adjNew[src]) {
            if(!vis[nbr]) {
                dfs(nbr,vis,adjNew);
            }
        }
    }

    void countSCC(int n) {
        //hume topological order nikalna pdega
        //saare direction reverse krne ke baad hume pata hona chahiye na, sahi order poora graph traverse krne ke liye
        stack<int> st;
        unordered_map<int, bool> visited;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                topoSort(st, i, visited);
            }
        }

        //yaha pr mujhe topo order mil gya hai
        //ab direction reverse krna hai saare node ka

        unordered_map<int, list<int>> adjNew;
        for(auto i : adj) {
            for(auto j : i.second) {
                int u = i.first;
                int v = j;
                adjNew[v].push_back(u);
            }
        }

        //new graph bann gya reverse direction wala
        //ab just SCC nikalna hai
        //dfs se ho jayega
        //topo order ka use krke nikalna hai
        //kyuki ussi order mai traverse krna h
        unordered_map<int, bool> vis;
        int count = 0;
        while(!st.empty()) {
            int top = st.top();
            st.pop();
            if(!vis[top]) {
                cout<<"SCC: ";
                dfs(top, vis, adjNew);
                cout<<endl;
                count++;
            }
        }
        cout<<"No. of SCC: "<<count;
    }
};

int main() {

    Graph g;
    g.addEdge(0,3,1);
    g.addEdge(3,2,1);
    g.addEdge(2,1,1);
    g.addEdge(1,0,1);
    g.addEdge(2,4,1);
    g.addEdge(4,5,1);
    g.addEdge(5,6,1);
    g.addEdge(6,4,1);
    g.addEdge(6,7,1);

    int n = 3;

    g.countSCC(n);
    // g.print(n);

    return 0;
}