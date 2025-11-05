//gfg: The Celebrity Problem

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // Iterate through each person (represented by index i)
        for(int i = 0; i < mat.size(); i++) {
            bool can = true;

            // Step 1: Check if person 'i' knows anyone.
            // If 'i' knows any other person (mat[i][j] == 1), 
            // then 'i' cannot be a celebrity.
            for(int j = 0; j < mat.size(); j++) {
                if(i == j) continue;
                if(mat[i][j] == 1) {
                    can = false;
                    break;
                }
            }

            // If 'i' failed the first condition, move to the next person
            if(can == false) continue;

            // Step 2: Check if everyone else knows person 'i'
            for(int k = 0; k < mat.size(); k++) {
                if(i == k) continue;
                if(mat[k][i] == 0) {
                    can = false;
                    break;
                }
            }

            // If 'i' passed both checks, then 'i' is the celebrity
            if(can == true) return i;
        }

        // If no celebrity is found, return -1
        return -1;
    }
};

class Solution2 {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        stack<int> st;
        
        //step 1: push all person in stack
        for(int i=0; i<n; i++) {
            st.push(i);
        }

        //step 2: eliminate non-celebrities using pairwise comparison
        // if a knows b → a cannot be a celebrity
        // if a doesn't know b → b cannot be a celebrity
        while(st.size() != 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            
            if(mat[a][b]) {
                // a knows b, a is not a celebrity
                st.push(b);
            } else {
                // b knows a, b is not a celebrity
                st.push(a);
            }
        }
        
        //step 3: the last person remaining might be a celebrity
        int mightBeCelebrity = st.top(); st.pop();
        
        //step 4: verify if the person doesn’t know anyone
        for(int i=0; i<n; i++) {
            if(mightBeCelebrity == i) continue; // celebrity khud ko toh jaanta hi hai
            if(mat[mightBeCelebrity][i] == 1) return -1; // knows someone → not celebrity
        }
        
        //step 5: verify if everyone knows this person
        for(int i=0; i<n; i++) {
            if(mightBeCelebrity == i) continue;
            if(mat[i][mightBeCelebrity] != 1) return -1; // someone doesn’t know → not celebrity
        }
        
        return mightBeCelebrity; // person is celebrity
    }
};

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    // Hardcoded test case
    // Example:
    // 0 1 0
    // 0 0 0
    // 0 1 0
    // Person 1 is the celebrity (everyone knows 1, and 1 knows no one)
    vector<vector<int>> mat = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    Solution2 sol;
    int result = sol.celebrity(mat);

    if(result == -1)
        cout << "No celebrity found!" << endl;
    else
        cout << "Celebrity is person with index: " << result << endl;

    // Another test case
    // 0 1
    // 1 0
    // No celebrity (both know each other)
    vector<vector<int>> mat2 = {
        {0, 1},
        {1, 0}
    };

    result = sol.celebrity(mat2);
    if(result == -1)
        cout << "No celebrity found!" << endl;
    else
        cout << "Celebrity is person with index: " << result << endl;

    return 0;
}
