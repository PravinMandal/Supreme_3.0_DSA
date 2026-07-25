//leetcode: 787. Cheapest Flights Within K Stops
//Dijkstra's Algorithm se kiya hai
// Bellman ford se bhi kr skte hai, wo zyada efficient solution hoga
// jo question dijkstra's se ho skta hai wo saare questions bellman ford se bhi ho skte hai
// but jo bellman ford se ho skta hai wo dijkstra's se nhi ho skta hai, kyuki bellman ford negative weight ko bhi handle kr leta hai.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        // Adjacency list representation of graph
        // Stores: current city -> {destination city, ticket price}
        unordered_map<int, vector<pair<int, int>>> adjList;

        for(auto flight : flights) {

            int u = flight[0];
            int v = flight[1];
            int w = flight[2];

            adjList[u].push_back({v, w});
        }


        /*
            Priority Queue works like Dijkstra's algorithm.

            Stores:
            {total cost till now, current city, number of stops}

            Minimum cost path is processed first.
        */
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0, src, 0});


        /*
            visited[city] stores the minimum number of stops
            required to reach that city.

            If we reach same city with more stops,
            that path can be ignored.
        */
        vector<int> visited(n, INT_MAX);


        while(!pq.empty()) {


            auto top = pq.top();
            pq.pop();


            int cost = top[0];
            int city = top[1];
            int stops = top[2];


            // Destination reached with minimum possible cost
            if(city == dst)
                return cost;


            /*
                If stops exceed k,
                this path is not allowed.
            */
            if(stops > k)
                continue;


            /*
                If this city was already reached using
                fewer stops, current path is not useful.
            */
            if(visited[city] < stops)
                continue;


            visited[city] = stops;


            /*
                Explore all neighbouring cities.

                Add:
                new total cost
                destination city
                increased stop count
            */
            for(auto& nbr : adjList[city]) {

                pq.push({
                    cost + nbr.second,
                    nbr.first,
                    stops + 1
                });
            }
        }


        // No valid path found within k stops
        return -1;
    }
};


int main() {

    Solution obj;


    // Hardcoded test cases

    int n1 = 4;
    vector<vector<int>> flights1 = {
        {0,1,100},
        {1,2,100},
        {2,0,100},
        {1,3,600},
        {2,3,200}
    };

    int n2 = 3;
    vector<vector<int>> flights2 = {
        {0,1,100},
        {1,2,100},
        {0,2,500}
    };

    int n3 = 3;
    vector<vector<int>> flights3 = {
        {0,1,100},
        {1,2,100}
    };


    cout << "Test Case 1 Output: " 
         << obj.findCheapestPrice(n1, flights1, 0, 3, 1) << endl;

    cout << "Test Case 2 Output: " 
         << obj.findCheapestPrice(n2, flights2, 0, 2, 1) << endl;

    cout << "Test Case 3 Output: " 
         << obj.findCheapestPrice(n3, flights3, 0, 2, 0) << endl;


    return 0;
}