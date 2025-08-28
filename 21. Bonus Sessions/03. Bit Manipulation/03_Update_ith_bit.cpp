#include<bits/stdc++.h>
using namespace std;

void clearBit(int n, int i, int& clear) {
    int clearMask = ~(1<<i);
    clear = (n&clearMask);
}

void updateIthBit(int n, int i, int target) {
    //taret 1 ya 0 hoga
    //step 1 clear bit
    int clear;
    clearBit(n, i, clear);

    //step 2: or krdo targetMask se, toh target 1 hoga toh ith bit pr 1 ho jayega warna 0;
    int targetMask = target<<i;
    int update = clear | targetMask;

    cout<<"Updated: "<<update<<endl;
}

int main() {
    int n = 10;

    updateIthBit(n, 2, 1); // 10 -> 1010, update 2nd(from LSB) bit to 1 --> 1110 -> 14;


    return 0;
}