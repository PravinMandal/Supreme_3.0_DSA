#include<iostream>
using namespace std;

void floydTrianglePattern(int n) {
    int num = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<i+1; j++) {
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
    }
}

int main() {

    int n;
    cout<<"Enter the size: "<<endl;
    cin>>n;

    floydTrianglePattern(n);

    return 0;
}