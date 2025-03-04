#include<iostream>
using namespace std;

bool checkEven(int n) {
    // if(n%2 == 0) return true;
    // else return false;

    if((n&1) == 0) return true;
    else return false;
}

int main() {

    int n;
    cout<<"Enter the Number: ";
    cin>>n;

    bool ans = checkEven(n);

    ans ? cout<<n<<" is an Even Number" : cout<<n<<" is an Odd Number";

    return 0;
}