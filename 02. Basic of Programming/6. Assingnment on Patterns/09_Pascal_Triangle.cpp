#include<iostream>
using namespace std;

void pascalTriangle(int n) {

    for(int i=1; i<=n; i++) {
        int c = 1;
        for(int j=1; j<=i; j++) {
            cout<<c<<" ";
            c = c * (i - j) /j;
        }
        cout<<endl;
    }
}

int main() {

    int n;
    cout<<"Enter the size: "<<endl;
    cin>>n;

    pascalTriangle(n);

    return 0;
}