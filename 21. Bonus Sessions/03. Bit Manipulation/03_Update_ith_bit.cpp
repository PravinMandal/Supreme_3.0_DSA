//kisi bhi bit ko set krna hai toh, or krdo 1 ke sath
//kisi bhi bit ko 0 banana hai toh, and krdo 0 ke sath

#include<bits/stdc++.h>
using namespace std;

void clearBit(int& n, int i) {
    int clearMask = ~(1<<i);
    n = (n&clearMask);
}

void updateIthBit(int n, int i, int target) {
    //taret 1 ya 0 hoga
    //step 1 clear bit
    int clear;
    clearBit(n, i);

    //step 2: or krdo targetMask se, toh target 1 hoga toh ith bit pr 1 ho jayega warna 0;
    int targetMask = target<<i;
    int update = n | targetMask;

    cout<<"Updated: "<<update<<endl;
}

void clearlastIbits(int n, int i) {
    // -1 in binary -> 111111111111111111
    int mask = (-1 << i); // if i=3, mask-> 1111111111000
    n = n & mask;
    cout<<"after clearing last i bits: "<<n<<endl;
}

int countSetBits(int n) {
    int count = 0;
    while(n != 0) {
        count++;
        n = n & (n-1);
    }
    return count;
}

bool isPowerofTwo(int n) {
    int count = countSetBits(n);
    return count == 1 ? true:false;
}

void clearBitsInRange(int n, int i, int j) {
    int a = (-1 << (i+1));
    int b = ~(-1 << j);
    int mask = a | b;
    n = n & mask;

    cout<<"Number after clearing bits: "<<n<<endl;
}

int main() {
    int n = 10;

    updateIthBit(n, 2, 1); // 10 -> 1010, update 2nd(from LSB) bit to 1 --> 1110 -> 14;
    clearlastIbits(15, 2);
    int setBitsNum = countSetBits(15);
    cout<<"Number of set bits: "<<setBitsNum<<endl;

    bool poweroftwo = isPowerofTwo(8);
    cout<<"powerOfTwo: "<<poweroftwo<<endl;

    clearBitsInRange(15, 2, 1);


    return 0;
}