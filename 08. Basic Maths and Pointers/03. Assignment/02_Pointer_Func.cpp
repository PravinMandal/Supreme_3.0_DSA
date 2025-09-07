#include<bits/stdc++.h>
using namespace std;

int func(int x, int* py, int** ppz) {
    int y, z;
    **ppz += 1; // c = 5
    z = **ppz; // z = 5
    *py += 2; // c = 7
    y = *py; // y = 7
    x += 3; // x = 4 + 3 = 7
    return x+y+z; // 7+7+5
}

int main() {
    {
        int c, *b, **a;
        c = 4;
        b = &c;
        a = &b;
        cout<<func(c, b, a)<<endl;
        //output: 19
    }

    {
        int ***r, **q, *p, i=8;
        p = &i;
        (*p)++; // i=9
        q = &p;
        (**q)++; // i=10;
        r = &q;
        cout<<*p<<" "<<**q<<" "<<***r<<endl;
        //output: 10 10 10

    }
    
    return 0;
}