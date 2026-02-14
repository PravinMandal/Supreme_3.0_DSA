//leetcode: 973 K Closest Points to Origin

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;

        // Maintain a max-heap of size k based on squared distance
        for(auto i : points) {
            int first = i[0];
            int second = i[1];
            int dist = first*first + second*second;

            pq.push({dist, {first, second}});

            // Keep only k closest points in the heap
            if(pq.size() > k) pq.pop();
        }

        vector<vector<int>> ans;

        // Extract points from heap
        while(!pq.empty()) {
            auto top = pq.top(); pq.pop();
            ans.push_back({top.second.first, top.second.second});
        }

        return ans;
    }
};

class Solution2 {
public:
    class mycomp {
        public:
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            int distA = a.first*a.first + a.second*a.second;
            int distB = b.first*b.first + b.second*b.second;
            return distA < distB; //pq mai ulta hota hai, abhi max heap bana hai
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,int>, vector<pair<int, int>>, mycomp> pq;
        for(auto i : points) {
            pq.push({i[0], i[1]});
            if(pq.size() > k) pq.pop();
        }

        while(!pq.empty()) {
            auto top = pq.top(); pq.pop();
            ans.push_back({top.first, top.second});
        }
        return ans;
    }
};

int main() {
    Solution2 sol;

    // Hardcoded test case
    vector<vector<int>> points = {{1,3}, {-2,2}, {5,8}, {0,1}};
    int k = 2;

    vector<vector<int>> result = sol.kClosest(points, k);

    // Print k closest points
    for(auto &p : result) {
        cout << p[0] << " " << p[1] << endl;
    }

    return 0;
}
