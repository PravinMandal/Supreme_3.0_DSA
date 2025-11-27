//leetcode: 71 - Simplify Path

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void buildAns(stack<string>& st, string& ans) {
        if(st.empty()) return;

        string top = st.top(); st.pop();
        buildAns(st, ans);
        ans += top;
    }

    string simplifyPath(string path) {
        stack<string> st;
        int i = 0;

        while(i < path.size()) {

            int start = i;
            int end = i + 1;

            // Move `end` until next '/'
            while(end < path.size() && path[end] != '/') {
                ++end;
            }

            // Extract path token like "/", "/.", "/..", "/usr"
            string minPath = path.substr(start, end - start);

            // Move i forward
            i = end;

            // Skip "/" and "/."
            if(minPath == "/" || minPath == "/.") continue;

            if(minPath != "/..") {
                // A valid directory → push into stack
                st.push(minPath);
            }
            else if(!st.empty()) {
                // "/.." means go UP one directory → pop stack
                st.pop();
            }
        }

        // Build simplified path
        string ans = st.empty() ? "/" : "";
        buildAns(st, ans);
        
        return ans;
    }
};

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    Solution sol;

    // Hardcoded Test Case 1
    string p1 = "/home/";
    // Expected: "/home"
    cout << "Simplified: " << sol.simplifyPath(p1) << endl;

    // Hardcoded Test Case 2
    string p2 = "/a/./b/../../c/";
    // Expected: "/c"
    cout << "Simplified: " << sol.simplifyPath(p2) << endl;

    // Hardcoded Test Case 3
    string p3 = "/../";
    // Expected: "/"
    cout << "Simplified: " << sol.simplifyPath(p3) << endl;

    // Hardcoded Test Case 4
    string p4 = "/home//foo/";
    // Expected: "/home/foo"
    cout << "Simplified: " << sol.simplifyPath(p4) << endl;

    return 0;
}
