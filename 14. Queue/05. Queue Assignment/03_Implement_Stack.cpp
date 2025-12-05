//leetcode: 225 - Implement Stack using Queues

#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() {
        // Default constructor
    }
    
    void push(int x) {
        // Queue ke end me push → but pop ke waqt rotate karenge
        q.push(x);
    }
    
    int pop() {
        // Last inserted element ko remove karne ke liye
        // baaki sabko rotate kar do queue ke end me
        for(int i=0; i < q.size()-1; i++) {
            int front = q.front();
            q.pop();
            q.push(front);
        }

        // Ab front hi last inserted (stack top) hai
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        // Queue ka last element hi stack ka top hota hai
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    MyStack st;

    // Hardcoded test cases

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl;  // 30
    cout << st.pop() << endl;  // 30

    cout << st.top() << endl;  // 20
    cout << st.pop() << endl;  // 20

    cout << st.empty() << endl; // 0 (false)

    cout << st.pop() << endl;   // 10
    cout << st.empty() << endl; // 1 (true)

    return 0;
}
