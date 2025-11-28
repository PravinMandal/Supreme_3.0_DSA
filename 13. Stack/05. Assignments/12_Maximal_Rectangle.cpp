//leetcode: 85 - Maximal Rectangle

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findPrevSmallest(vector<int>& ans, vector<int>& arr) {
        stack<int> st;
        st.push(-1);
        for(int i=0; i<arr.size(); i++) {
            int element = arr[i];
            while( st.top() != -1 && arr[st.top()] >= element) {
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i);
        }
    }
    
    void findNextSmallest(vector<int>& ans, vector<int>& arr) {
        stack<int> st;
        st.push(-1);
        
        for(int i=arr.size()-1; i>=0; i--) {
            int element = arr[i];
            while(st.top() != -1 && arr[st.top()] >= element) {
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i);
        }
        
        for(int i=0; i<ans.size(); i++) {
            if(ans[i] == -1) {
                ans[i] = arr.size();
            }
        }
        reverse(ans.begin(), ans.end());
    }
    
    int getMaxAreainHistogram(vector<int> &arr) {
        vector<int>prevSmallest;
        vector<int>nextSmallest;

        // prev smaller element index for each histogram bar
        findPrevSmallest(prevSmallest, arr);

        // next smaller element index for each histogram bar
        findNextSmallest(nextSmallest, arr);
        
        int area = INT_MIN;
        
        // compute max rectangle using width * height
        for(int i=0; i<arr.size(); i++) {
            int height = arr[i];
            int width = nextSmallest[i] - prevSmallest[i] - 1;
            int currAns = height * width;
    
            area = max(area, currAns);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> v;
        int n = matrix.size();
        int m = matrix[0].size();

        // Converting matrix<char> → matrix<int>
        for(int i=0; i<n; i++) {
            vector<int> t;
            for(int j=0; j<m; j++) {
                t.push_back(matrix[i][j] - '0'); // convert '1'→1, '0'→0
            }
            v.push_back(t);
        }

        // First row histogram area
        vector<int> arr = v[0];
        int area = getMaxAreainHistogram(arr);

        // Build histogram row by row
        for(int i=1; i<n; i++) {
            for(int j=0; j<m; j++) {
                int num = v[i][j];
                if(num == 1) {
                    arr[j] += num;  // accumulate height
                } else {
                    arr[j] = 0;     // reset height if 0
                }
            }

            int currMax = getMaxAreainHistogram(arr);
            area = max(area, currMax);
        }
        return area;
    }
};

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    Solution sol;

    // Hardcoded test case:
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    // Expected: 6 (largest rectangle of 1s)
    cout << "Maximal Rectangle Area: "
         << sol.maximalRectangle(matrix) << endl;

    return 0;
}
