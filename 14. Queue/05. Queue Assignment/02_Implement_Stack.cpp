//leetcode: 232 - Implement Queue using Stacks

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> st;

    MyQueue() {
        // default constructor
    }

    // push element at BOTTOM of stack → queue ka front ban jayega
    void pushBottom(int n) {
        if(st.empty()) {
            st.push(n);
            return;
        } 

        // recursive reverse insertion
        int top = st.top();
        st.pop();
        pushBottom(n);
        st.push(top);
    }
    
    void push(int x) {
        // queue me push ka matlab → stack ke bottom me insert
        pushBottom(x);
    }
    
    int pop() {
        // queue ka front → stack ka top
        int top = st.top();
        st.pop();
        return top;
    }
    
    int peek() {
        // front element return karo
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    // Hardcoded example to test queue functionality
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.peek() << endl;  // 10
    cout << q.pop() << endl;   // 10

    cout << q.peek() << endl;  // 20
    cout << q.pop() << endl;   // 20

    cout << q.empty() << endl; // 0 (false)

    cout << q.pop() << endl;   // 30
    cout << q.empty() << endl; // 1 (true)

    return 0;
}
