//gfg: Bit Manipulation

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void bitManipulation(int num, int i) {
        //LSB se 0th indexing se chalu hota h
        //but question mai 1 se kiya hai toh usse thik kro
        i = i-1; 
        int getMask = (1<<i);
        int get;
        int ans = (num & getMask);
        if(ans == 0) get = 0;
        else get = 1;
        
        
        //now set
        int setMask = (1<<i);
        int set = num | setMask;
        
        //clear
        int clearMask = ~(1<<i);
        int clear = num & clearMask;
        
        cout<<get<<" "<<set<<" "<<clear;
        
    }
};

int main() {
    Solution obj;
    // hardcoded test case
    int num = 5, i = 2; // Example: num = 5 (binary 101), i = 2
    obj.bitManipulation(num, i);
    return 0;
}
