//leetcode: 871 Minimum Number of Refueling Stops

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops = 0;
        int dist = 0;
        int fuel = startFuel;
        int i = 0;

        // Max heap storing {fuel, position} of reachable stations
        priority_queue<pair<int, int>> pq;

        while(true) {

            // Add all stations that can be reached with current fuel
            while(i < stations.size()) {
                if(stations[i][0] <= dist + fuel) {
                    pq.push({stations[i][1], stations[i][0]});
                    i++;
                } else break;
            }

            //travel with full fuel level
            dist += fuel;
            fuel = 0;

            //target tak pohoch gye
            if(dist >= target) break;

            //no fuel station withing reach
            if(pq.empty()) {
                stops = -1;
                break;
            }

            // Take fuel from the station with maximum fuel among reachable ones
            auto top = pq.top(); 
            pq.pop();

            // Recalculate fuel after reaching that station
            fuel = (dist - top.second) + top.first;
            dist = top.second;
            stops++;
        }
        return stops;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    int target = 100;
    int startFuel = 10;
    vector<vector<int>> stations = {
        {10, 60},
        {20, 30},
        {30, 30},
        {60, 40}
    };

    cout << sol.minRefuelStops(target, startFuel, stations) << endl;

    return 0;
}