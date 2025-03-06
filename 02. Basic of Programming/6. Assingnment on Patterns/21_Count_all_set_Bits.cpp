//set bits mtlb ki uss number ke binary number mai kitne 1 hai;
#include<iostream>
using namespace std;

int countSetBits(int n) {
    int count=0;
    while(n > 0) {
        int remainder = n % 2;
        if(remainder == 1) {
            count++;
        }
        n = n/2;
    }
    return count;
}

int countSetBits2(int n) {
    int count=0;
    while(n>0) {
        if(n&1 == 1) {
            count++;
        }
        n = n>>1; //right shift kr diya
        // 10 -> 1010
        // 10>>1 -> 101
    }
    return count;
}

int main() {
    int n = 10;
    // 10-> 1010, number of set bits: 2

    int ans = countSetBits2(n);
    cout<<"Total number of set bits are: "<<ans<<endl;
}