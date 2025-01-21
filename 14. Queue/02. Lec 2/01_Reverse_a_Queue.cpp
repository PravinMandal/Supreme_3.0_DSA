#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseQueueRecursive(queue<int> &q){
    if(q.empty()){
        return;
    }
    int element=q.front();
    q.pop();
    reverseQueueRecursive(q);
    //ab wapas aate hue wapas puch krdo toh wo reverse ho jayega
    q.push(element);
}

void reverseQueue(queue<int> &q){
    //ab reverse krne ke liye hum stack ka use krenge
    stack<int>st;

    while(!q.empty()){
        int element = q.front();
        q.pop();
        st.push(element);
    }
    //ab yaha tk queue ke saare element stack mai store ho chuka hai
    //ab yaha se agar stack ke top ko excess krte krte pop kru toh mujhe reverse order mai elements milenge
    while(!st.empty()){
        int element = st.top();
        st.pop();
        q.push(element);
    }
}

int main(){

    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    reverseQueueRecursive(q);

    //printing
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }cout<<endl;

    return 0;
}