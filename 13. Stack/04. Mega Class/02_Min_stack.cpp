//leetcode: 155. Min Stack
#include <iostream>
#include <vector>
using namespace std;

class MinStack {
public:
    vector<pair<int,int>> v; //pair -> {value, miniumum element till now}
    MinStack() {
        
    }
    
    void push(int val) {
        if(v.empty()) {
            v.push_back({val,val});
        }
        else {
            v.push_back({val, v.back().second < val ? v.back().second : val});
        }
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
    }
};

int main() {
    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << "Top: " << st.top() << endl;        // Should print 2
    cout << "Min: " << st.getMin() << endl;     // Should print 2

    st.pop(); // removes 2

    cout << "Top after pop: " << st.top() << endl;    // Should print 7
    cout << "Min after pop: " << st.getMin() << endl; // Should print 3

    return 0;
}
