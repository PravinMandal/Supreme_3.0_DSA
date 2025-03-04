#include<iostream>
using namespace std;

void butterflyPattern(int n) {
    n = 2*n;
    
    for(int i=0; i<n/2; i++) {

        for(int j=0; j<i+1; j++) {
            cout<<"* ";
        }
        for(int j=0; j<n-(2*(i+1)); j++) {
            cout<<"  ";
        }
        for(int j=0; j<i+1; j++) {
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i=0; i<n/2; i++) {
        for(int j=0; j<(n/2)-i; j++) {
            cout<<"* ";
        }
        for(int j=0; j<2*i; j++) {
            cout<<"  ";
        }
        for(int j=0; j<(n/2)-i; j++) {
            cout<<"* ";
        }
        cout<<endl;
    }
    
}

int main() {

    int n;
    cout<<"Enter the size: "<<endl;
    cin>>n;

    butterflyPattern(n);

    return 0;
}