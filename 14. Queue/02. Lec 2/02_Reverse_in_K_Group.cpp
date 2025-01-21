#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseinKGroup(queue<int> &q, int k, int count){

    if(count >= k){
        stack<int>st; //bahar banaaya hu kyuki loop ke andar banata toh loop ke bahar usse access nhi kr paata
        for(int i=0; i<k; i++){
            int element = q.front();
            q.pop();
            //queue se liye ab stack mai push krta hu
            st.push(element);
        }
        //yaha tk "k" elements stack mai store ho gye h ab queue ke last mai push kr deta hu
        //toh k elements reverse hoke queue ke starting se last mai chale jayenge
        for(int i=0; i<k; i++){
            int element = st.top();
            st.pop();
            //ab queue ke last mai insert kr dete hai
            q.push(element);
        }
        //ek case ho gya ab baaki recursion samhal lega
        reverseinKGroup(q,k,count-k);
    }
    else{
        //ab yaha aa gye mtlb "k" se kam element bache h 
        //ab hume direct front se "k" element utha kr queue ke last mai push krna pdega
        //iske liye stack ka use nhi krunga warna ye bhi reverse ho jayega
        for(int i=0; i<count; i++){
            int element = q.front();
            q.pop();
            q.push(element);
        }
    }
}

int main(){

    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
    q.push(110);

    int k=3;
    int count=q.size();
    //ye count ke liye rakha hi ki kitne elements bache hai
    reverseinKGroup(q,k,count);

    //printing
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}