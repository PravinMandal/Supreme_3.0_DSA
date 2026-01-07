#include<iostream>
using namespace std;

class NStack {
    int *a, *top, *next;
    int n; //no. of stacks
    int size; //size of the main array
    int freeSpot; //index of free spot in main array

    public :
        NStack(int _n, int _s) : n(_n), size(_s) {
            freeSpot = 0;
            a = new int[size];
            top = new int[n];
            next = new int[size];

            //initialize top array
            for(int i=0; i<n; i++) {
                top[i] = -1;
            }

            //initialize next array
            for(int i=0; i<size; i++) {
                next[i] = i+1;
            }
            next[size-1] = -1;
        }
        
        //push x into mth stack
        bool push(int x, int m) {
            if(freeSpot == -1) {
                return false; //stack overflow;
            }

            //1. find index
            int index = freeSpot;

            //2. update freeSpot
            freeSpot = next[index];

            //3. insert x at index
            a[index] = x;

            //4. update next
            next[index] = top[m-1];

            //5. update top
            top[m-1] = index;
            return true;
        }

        int pop(int m) {
            if(top[m-1] == -1) {
                return -1; //underflow
            }

            //just opposite kro push ka
            int index = top[m-1];
            top[m-1] = next[index];
            int popedElement = a[index];
            next[index] = freeSpot;
            freeSpot = index;
            return popedElement;
        }

        //destructor
        ~NStack() {
            delete[] a;
            delete[] top;
            delete[] next;
        }
};


int main() {

    NStack s(3, 6);

    cout<<s.pop(1)<<endl;
    cout<<s.push(10, 1)<<endl;
    cout<<s.push(11, 1)<<endl;
    cout<<s.push(12, 1)<<endl;
    cout<<s.push(13, 2)<<endl;
    cout<<s.push(14, 2)<<endl;
    cout<<s.push(15, 2)<<endl;
    cout<<s.push(16, 2)<<endl;
    cout<<s.pop(2)<<endl;
    cout<<s.pop(2)<<endl;
    cout<<s.pop(1)<<endl;
    cout<<s.pop(1)<<endl;

    return 0;
}