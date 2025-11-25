//leetcode: 853 - Car Fleet

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool mycomp(pair<int, float>&a, pair<int, float>&b) {
        return a.first > b.first;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> cars;

        for(int i=0; i<position.size(); i++) {
            int t = target - position[i];

            pair<int, float> temp;
            temp.first = position[i];
            temp.second = (float)t/speed[i]; // time to reach target
            cars.push_back(temp);
        }

        // Sorting cars by position in decreasing order 
        // so we process cars from nearest to target → farthest

        //ye nhi krne ka kyuki wo pehle int check krega agar same rha toh float wale ko bhi compare krke sort krega phir
        // sort(cars.begin(), cars.end(), greater<pair<int,float>>()); 

        // sort(cars.begin(), cars.end(), mycomp);
        sort(cars.begin(), cars.end(), [](auto&a, auto&b) {
            return a.first > b.first;
        });

        float headCar = cars[0].second; // lead car time
        int numberOfFleet = 1;          // at least 1 fleet exists

        for(auto it : cars) {
            if(it.second > headCar) {
                // This car takes longer → forms a new fleet
                numberOfFleet++;
                headCar = it.second;
            }
            // else: this car joins the fleet of the headCar
        }

        return numberOfFleet;
    }
};

class Solution2 {
public:
    class Car {
    public:
        int pos, speed;
        Car(int p, int s):pos(p), speed(s){};
    };
    static bool mycomp(Car&a, Car&b) {
        return a.pos < b.pos;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car>cars;
        for(int i=0; i<position.size(); i++) {
            Car car(position[i], speed[i]);
            cars.push_back(car);
        }
        sort(cars.begin(), cars.end(), mycomp);

        stack<float>st;
        for(auto car : cars) {
            float time = (target-car.pos)/(float)car.speed;
            while(!st.empty() && st.top() <= time) {
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    Solution sol;

    // Hardcoded test case 1:
    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed     = { 2, 4, 1, 1, 3 };

    // Expected output: 3 fleets
    cout << "Number of Fleets = "
         << sol.carFleet(target, position, speed) << endl;

    // Hardcoded test case 2:
    target = 10;
    position = {3, 5, 7};
    speed    = {3, 2, 1};
    // Cars: (pos=7,t=3), (pos=5,t=2.5), (pos=3,t=~2.33)
    // All merge → 1 fleet
    cout << "Number of Fleets = "
         << sol.carFleet(target, position, speed) << endl;

    return 0;
}
