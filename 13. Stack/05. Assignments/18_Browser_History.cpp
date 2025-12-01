//leetcode: 1472 - Design Browser History

#include <bits/stdc++.h>
using namespace std;

class BrowserHistory {
public:
    stack<string> backward;
    stack<string> forwardst;

    BrowserHistory(string homepage) {
        // browser shuru hota hai homepage se
        backward.push(homepage);
    }
    
    void visit(string url) {
        // new page visit → forward history clear
        while(!forwardst.empty()) forwardst.pop();
        backward.push(url);
    }
    
    string back(int steps) {
        // jab tak peeche jaa sakte hai
        while(backward.size() > 1 && steps--) {
            forwardst.push(backward.top());
            backward.pop();
        }
        return backward.top();
    }
    
    string forward(int steps) {
        // jab tak aage jaa sakte hai
        while(!forwardst.empty() && steps--) {
            backward.push(forwardst.top());
            forwardst.pop();
        }
        return backward.top();
    }
};


// ---------------------- MAIN FUNCTION ----------------------
int main() {
    // Hardcoded test case to demonstrate functionality
    BrowserHistory bh("leetcode.com");

    bh.visit("google.com");
    bh.visit("facebook.com");
    bh.visit("youtube.com");

    cout << bh.back(1) << endl;      // facebook.com
    cout << bh.back(1) << endl;      // google.com
    cout << bh.forward(1) << endl;   // facebook.com

    bh.visit("linkedin.com");

    cout << bh.forward(2) << endl;   // linkedin.com (can't go forward)
    cout << bh.back(2) << endl;      // google.com
    cout << bh.back(7) << endl;      // leetcode.com (can't go further)

    return 0;
}
