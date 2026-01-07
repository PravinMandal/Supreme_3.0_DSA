#include<iostream>
using namespace std;

class KQueue {
    int *arr, *front, *rear, *next;
    int freeSpot;
    int n; //size of main array
    int k; //num of queue
public:
    KQueue(int _n, int _k) : n(_n), k(_k) {
        freeSpot = 0;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        for(int i=0; i<k; i++) {
            front[i] = rear[i] = -1;
        }
        for(int i=0; i<n; i++) {
            next[i] = i+1;
        }
        next[n-1] = -1;
    }

    //push x into qith Queue
    bool push(int x, int qi) {
        //1. check overflow
        if(freeSpot == -1) {
            return false;
        }

        //2. find first free index
        int index = freeSpot;

        //3. update freespot
        freeSpot = next[index];

        //4. check if its first element of qith
        if(front[qi] == -1) {
            front[qi] = index;
        } else {
            next[rear[qi]] = index;
        }

        //5. update next
        next[index] = -1;

        //6. update rear
        rear[qi] = index;
        arr[index] = x;
        return true;
    }

    int pop(int qi) {
        //1. check underflow
        if(front[qi] == -1) {
            return -1;
        }

        //2. find index to pop
        int index = front[qi];

        //3. front ko update kro
        front[qi] = next[index];

        //4. manage freespot
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    ~KQueue() {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};


int main() {
    KQueue qi(9, 3);

    cout<<qi.pop(0)<<endl;
    cout<<qi.push(10,0)<<endl;
    cout<<qi.push(20,0)<<endl;
    cout<<qi.push(30,0)<<endl;
    cout<<qi.pop(0)<<endl;
    cout<<qi.push(40,1)<<endl;
    cout<<qi.push(50,1)<<endl;
    cout<<qi.push(60,1)<<endl;
    cout<<qi.push(70,1)<<endl;
    cout<<qi.push(80,2)<<endl;
    cout<<qi.push(90,2)<<endl;
    cout<<qi.push(100,2)<<endl;
    cout<<qi.push(110,2)<<endl;
    cout<<qi.pop(2)<<endl;
    cout<<qi.pop(2)<<endl;
    cout<<qi.pop(2)<<endl;

    return 0;
}