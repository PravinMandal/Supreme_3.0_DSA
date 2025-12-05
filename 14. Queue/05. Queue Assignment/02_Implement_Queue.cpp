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

class MyQueue2 {
public:
    stack<int> s1, s2;

    MyQueue2() {
        // default constructor
    }
    
    void push(int x) {
        // queue push → simply stack s1 me daal do
        s1.push(x);
    }
    
    int pop() {
        int last = -1;

        // agar s2 me element already hain → wahi queue ka front hai
        if(!s2.empty()) {
            last = s2.top();
        } else {
            // s2 empty hai → s1 ke saare elements ulte s2 me daal do
            // taaki correct queue order ban jaye
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            last = s2.top();
        }

        // s2 ka top hi queue ka front hai → pop kardo
        s2.pop();
        return last;
    }
    
    int peek() {
        int front = -1;

        // agar s2 me elements hain → wahi front
        if(!s2.empty()) {
            front = s2.top();
        } else {
            // otherwise s1 ko reverse karke s2 me daalte hain
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            front = s2.top();
        }
        return front;
    }
    
    bool empty() {
        // dono stacks empty → queue empty
        return s1.empty() && s2.empty();
    }
};


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
