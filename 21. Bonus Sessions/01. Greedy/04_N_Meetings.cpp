//gfg: N Meetings in One Room

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int, int>> time;
        for(int i=0; i<start.size(); i++) {
            time.push_back({start[i], end[i]});
        }
        
        sort(time.begin(), time.end(), cmp);
        //ab time, meeting ke ending time se sort ho gya hai
        //jo meeting sbse pehle khatam hogi wo sabse pehle hai
        //humne time diff try kiya ki meeting ka end time - start time
        //but usse baat nhi bann rha tha
        //toh hum meeting ke ending time se nikalenge
        
        //hum itna toh sure hai ki pehle meeting toh pakka include krunga
        int count = 1;
        int prevStart = time[0].first;
        int prevEnd = time[0].second;
        
        for(int i=1; i<start.size(); i++) {
            int currStart = time[i].first;
            int currEnd = time[i].second;
            
            if(currStart > prevEnd) {
                //includ kr skta hu
                count++;
                //shifting
                prevStart = currStart;
                prevEnd = currEnd;
            }
        }
        return count;
    }
};

int main() {
    // Hardcoded test case instead of cin
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    Solution obj;
    int maxMeet = obj.maxMeetings(start, end);

    cout << "Maximum number of meetings: " << maxMeet << endl;

    return 0;
}
