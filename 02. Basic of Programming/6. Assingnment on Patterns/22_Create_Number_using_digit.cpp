#include<iostream>
using namespace std;

int CreateNumber(int n) {
    int num=0;
    for(int i=0; i<n; i++) {
        int digit;
        cout<<"Enter the digit: ";
        cin>>digit;

        num = num * 10 + digit;
    }
    return num;
}

int main() {

    int n;
    cout<<"Enter the number of digits: "<<endl;
    cin>>n;

    int num = CreateNumber(n);
    cout<<"The number is: "<<num<<endl;

    return 0;
}