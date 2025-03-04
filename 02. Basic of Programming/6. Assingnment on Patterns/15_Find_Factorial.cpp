#include<iostream>
using namespace std;

int findFactorial(int n) {
    int fact = 1;

    for(int i=1; i<=n; i++) {
        fact = fact * i;
    }
    return fact;
}


int main() {

    int n;
    cout<<"Enter the Number: ";
    cin>>n;

    int ans = findFactorial(n);
    cout<<"Factorial of "<<n<<" is: "<<ans;
    
    return 0;
}