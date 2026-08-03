//leetcode: 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findNeighborsCities(int src, unordered_map<int, vector<pair<int, int>>>& adjList, unordered_map<int, bool>& visited, int distanceThreshold, vector<int>& dist, int sum) {

        // Stop exploring if current path already exceeds the allowed threshold.
        if(sum > distanceThreshold) return;

        // Mark current city as reachable.
        visited[src] = true;

        /*
            Explore all neighbouring cities.

            Each pair is stored as:
            {edgeWeight, neighbour}
        */
        for(auto nbr : adjList[src]) {

            int v = nbr.second;
            int w = nbr.first;

            /*
                Continue DFS if:
                1. Neighbour is not visited yet.
                2. A shorter path to neighbour is found.
            */
            if((visited.find(v) == visited.end()) || (dist[v] > (sum + w))) {

                dist[v] = sum + w;

                findNeighborsCities(v, adjList, visited, distanceThreshold, dist, sum + w);
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        // Build weighted undirected graph.
        unordered_map<int, vector<pair<int, int>>> adjList;

        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adjList[u].push_back({w, v});
            adjList[v].push_back({w, u});
        }

        int city = 0;
        int prevCity = INT_MAX;

        /*
            Run traversal from every city.

            Count how many cities are reachable
            within the given threshold.
        */
        for(int i = 0; i < n; i++) {

            unordered_map<int, bool> visited;

            // dist[j] stores shortest known distance from source city i.
            vector<int> dist(n, INT_MAX);
            dist[i] = 0;

            findNeighborsCities(i, adjList, visited, distanceThreshold, dist, 0);

            // Remove source city from the count.
            int cities = visited.size() - 1;

            /*
                If multiple cities have the same answer,
                choose the city having the larger index.
            */
            if(cities <= prevCity) {
                prevCity = cities;
                city = i;
            }
        }

        return city;
    }
};

class Solution2 {
public:
    int dijktras(int src, int n, unordered_map<int, vector<pair<int, int>>>& adjList, int& distanceThreshold) {

        // dist[i] stores the shortest distance from source to city i.
        vector<int> dist(n, INT_MAX);

        /*
            Set works as a priority queue.

            Stores pairs as:
            {distance, node}

            The node with minimum distance
            is always processed first.
        */
        set<pair<int, int>> st;

        dist[src] = 0;
        st.insert({0, src});

        int reachableCities = 0;

        while(!st.empty()) {

            // Extract node having minimum distance.
            auto minPair = *st.begin();

            int minNode = minPair.second;
            int minDist = minPair.first;

            st.erase(st.begin());

            /*
                Count only those cities whose shortest
                distance is within the threshold.

                Source city itself is excluded.
            */
            if((minNode != src) && minDist <= distanceThreshold)
                reachableCities++;

            /*
                Relax every outgoing edge.

                If a shorter path to neighbour is found,
                update its distance.
            */
            for(auto nbr : adjList[minNode]) {

                int nbrNode = nbr.first;
                int nbrDist = nbr.second;

                if(dist[minNode] + nbrDist < dist[nbrNode]) {

                    /*
                        Remove old distance entry
                        because std::set cannot contain
                        duplicate keys for Dijkstra updates.
                    */
                    auto result = st.find({dist[nbrNode], nbrNode});

                    if(result != st.end()) {
                        st.erase(result);
                    }

                    dist[nbrNode] = dist[minNode] + nbrDist;

                    st.insert({dist[nbrNode], nbrNode});
                }
            }
        }

        return reachableCities;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        // Build weighted undirected graph.
        unordered_map<int, vector<pair<int, int>>> adjList;

        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        int minReachableCities = INT_MAX;
        int city = 0;

        /*
            Run Dijkstra from every city.

            Count how many cities are reachable
            within the threshold distance.
        */
        for(int i = 0; i < n; i++) {

            int reachableCities = dijktras(i, n, adjList, distanceThreshold);

            /*
                If multiple cities have the same answer,
                choose the city having the larger index.
            */
            if(reachableCities <= minReachableCities) {

                minReachableCities = reachableCities;
                city = i;
            }
        }

        return city;
    }
};

int main() {

    Solution2 obj;

    // Hardcoded Test Case 1
    int n1 = 4;
    vector<vector<int>> edges1 = {
        {0,1,3},
        {1,2,1},
        {1,3,4},
        {2,3,1}
    };
    int threshold1 = 4;

    // Hardcoded Test Case 2
    int n2 = 5;
    vector<vector<int>> edges2 = {
        {0,1,2},
        {0,4,8},
        {1,2,3},
        {1,4,2},
        {2,3,1},
        {3,4,1}
    };
    int threshold2 = 2;

    // Hardcoded Test Case 3
    int n3 = 6;
    vector<vector<int>> edges3 = {
        {0,1,1},
        {1,2,2},
        {2,3,3},
        {3,4,4},
        {4,5,5}
    };
    int threshold3 = 6;

    cout << "Test Case 1 Output: " << obj.findTheCity(n1, edges1, threshold1) << endl;
    cout << "Test Case 2 Output: " << obj.findTheCity(n2, edges2, threshold2) << endl;
    cout << "Test Case 3 Output: " << obj.findTheCity(n3, edges3, threshold3) << endl;

    return 0;
}