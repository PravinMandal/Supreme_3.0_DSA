//leetcode: 621. Task Scheduler
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(int i=0; i<tasks.size(); i++) {
            freq[tasks[i]]++;
        }
        
        priority_queue<pair<int,char>> maxHeap;
        for(auto i : freq) {
            maxHeap.push({i.second, i.first});
        }
        int time = 0;
        while(!maxHeap.empty()) {
            int cycle = n + 1;
            vector<pair<int, char>>temp;
            while(cycle > 0 && !maxHeap.empty()) {
                //ek baar poora operation hoga poore heap se alag alag task perform honge
                // auto [freq, task] = maxHeap.top();
                pair<int, char> top = maxHeap.top();
                int freq = top.first;
                int task = top.second;
                maxHeap.pop();
                freq--;
                time++;
                cycle--;
                temp.push_back({freq, task});
            }

            //ab wapas push krna h temp wala maxHeap mai
            for(auto lefttask : temp) {
                if(lefttask.first > 0) {
                    maxHeap.push({lefttask.first, lefttask.second});
                }
            }

            //ab cycle jitna bacha hua h, utna idle lena pdega
            if(!maxHeap.empty()) {
                //agar maxHeap khali ho gya mtlb last mai h, iske baad koi aur task nhi h
                //toh idle add krne ki zaroorat nhi h
                time += cycle;
            }

        }
        return time;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<char> tasks1 = {'A','A','A','B','B','B'};
    int n1 = 2;
    cout << "Output 1: " << sol.leastInterval(tasks1, n1) << endl; // Expected: 8

    // Test Case 2
    vector<char> tasks2 = {'A','C','A','B','D','B'};
    int n2 = 1;
    cout << "Output 2: " << sol.leastInterval(tasks2, n2) << endl; // Expected: 6

    // Test Case 3
    vector<char> tasks3 = {'A','A','A','B','B','B'};
    int n3 = 0;
    cout << "Output 3: " << sol.leastInterval(tasks3, n3) << endl; // Expected: 6

    return 0;
}
