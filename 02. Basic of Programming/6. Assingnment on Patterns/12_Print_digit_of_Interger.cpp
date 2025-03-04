//Print all digits of integers
#include<iostream>
using namespace std;


int main() {
    int n = 3425345;

    while(n>0) {
        int digit = n%10;
        cout<<digit<<" ";
        n = n/10;
    }
}