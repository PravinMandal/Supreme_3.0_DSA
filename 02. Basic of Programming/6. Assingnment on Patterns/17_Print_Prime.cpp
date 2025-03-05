#include<iostream>
using namespace std;

void printPrime(int n) {
    for(int i=2; i<n; i++) {
        if(n%i == 0) return;
    }
    //yaha tak pohoch gya mtlb kisi se bhi divisible nhi hua, mtlb prime number h
    cout<<n<<" ";
}

int main() {

    int n = 30;

    for(int i=2; i<=n; i++) {
        printPrime(i);
    }

    return 0;
}