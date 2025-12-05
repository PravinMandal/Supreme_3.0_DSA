//leetcode: 225 - Implement Stack using Queues

#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q1, q2;
    bool flag = 1;
    MyStack() {
        
    }
    
    void push(int x) {
        flag ? q1.push(x) : q2.push(x);
    }
    
    int pop() {
        int ans = -1;
        if(flag) {
            flag = 0;
            while(q1.size() != 1) {
                q2.push(q1.front());
                q1.pop();
            }
            ans = q1.front();
            q1.pop();
        } else {
            flag = 1;
            while(q2.size() != 1) {
                q1.push(q2.front());
                q2.pop();
            }
            ans = q2.front();
            q2.pop();
        }
        return ans;
    }
    
    int top() {
        return flag ? q1.back() : q2.back();
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};


class MyStack2 {
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



// ---------------------- MAIN FUNCTION ----------------------
int main() {
    MyStack2 st;

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
