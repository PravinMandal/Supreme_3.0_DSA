//gfg: Fractional Knapsack

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<double> wtValRatio;
        for(int i=0; i<val.size(); i++) {
            double ratio = (val[i] * 1.0)/wt[i];
            wtValRatio.push_back(ratio);
        }
        
        priority_queue<pair<double, pair<int, int>> > maxHeap;
        //maxheap of {ratio, {val, wt}}
        //ab fill krte h
        for(int i=0; i<val.size(); i++) {
            maxHeap.push({wtValRatio[i], {val[i], wt[i]}});
        }
        
        double totalValue = 0;
        
        while(capacity != 0 && !maxHeap.empty()) {
            // imp while loop condition;
            auto front = maxHeap.top(); maxHeap.pop();
            
            double ratio = front.first;
            int value = front.second.first;
            int weight = front.second.second;
            
            if(capacity >= weight) {
                //toh poora include kr skta hu
                totalValue += value;
                capacity -= weight;
            }
            else {
                //poora nhi le skte kuch fraction hi lena pdega
                totalValue += ratio * capacity;
                capacity = 0;
                break;
            }
        }
        return totalValue;
    }
};

int main() {
    // Hardcoded test case instead of cin
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;

    Solution obj;
    double maxValue = obj.fractionalKnapsack(val, wt, capacity);

    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
