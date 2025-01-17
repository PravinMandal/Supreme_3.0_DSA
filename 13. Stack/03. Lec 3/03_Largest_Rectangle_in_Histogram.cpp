// leetcode 84: Largest Rectangle in Histogram
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    void nextSmallerElement(vector<int>& heights, vector<int>& nextAns){
        stack<int>st;
        st.push(-1);
        int n=heights.size();
        for(int i=n-1; i>=0; i--){
            int currElement=heights[i];
            while(st.top()!=-1 && heights[st.top()] >= currElement){
                st.pop();
            }
            nextAns.push_back(st.top());
            st.push(i);
        }
    }

    void prevSmallerElement(vector<int>& heights, vector<int>& prevAns){
        stack<int>st;
        st.push(-1);
        int n=heights.size();
        for(int i=0; i<n; i++){
            int currElement=heights[i];
            while(st.top()!=-1 && heights[st.top()] >= currElement){
                st.pop();
            }
            prevAns.push_back(st.top());
            st.push(i);
        }
    }


    int largestRectangleArea(vector<int>& heights) {
        vector<int>nextAns;
        vector<int>prevAns;

        nextSmallerElement(heights,nextAns);
        reverse(nextAns.begin() , nextAns.end());
        // ye mai bhul jaata hu
        //nextSmallerElement ke case mai jo -1 hota h wo last mtlb 6 represent krta h
        //but 6 ke badle -1 h toh width nikalte time dikkat hoga isiliye thik krdo
        for(int i=0; i<nextAns.size(); i++){
            if(nextAns[i] == -1){
                nextAns[i] = nextAns.size();
            }
        }

        prevSmallerElement(heights,prevAns);

        
        int maxArea=INT_MIN;
        for(int i=0; i<heights.size(); i++){
            int height=heights[i];
            int width=nextAns[i] - prevAns[i] - 1;
            int currAns=height*width;
            
            maxArea=max(maxArea,currAns);
        }

        return maxArea;
    }
};

int main() {
    Solution solution;

    // Input: Histogram bar heights
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    // Calculate the largest rectangle area
    int maxArea = solution.largestRectangleArea(heights);

    // Output the result
    cout << "The largest rectangle area is: " << maxArea << endl;

    return 0;
}
