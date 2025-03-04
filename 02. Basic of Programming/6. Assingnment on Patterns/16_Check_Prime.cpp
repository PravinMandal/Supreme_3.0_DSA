#include<iostream>
using namespace std;

bool checkPrime(int n) {
    for(int i=2; i<n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {

    int n;
    cout<<"Enter the Number: "<<endl;
    cin>>n;

    bool ans = checkPrime(n);

    if(ans) cout<<n<<" is a Prime Number ";
    else cout<<n<<" is not a Prime Number";

    return 0;
}