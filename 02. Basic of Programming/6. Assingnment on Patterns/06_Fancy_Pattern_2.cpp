#include<iostream>
using namespace std;

void fancyPattern2(int n) {
    int num=1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<i+1; j++) {
            cout<<num;
            num++;
            if(j<i){
                cout<<"*";
            }
        }
        cout<<endl;
    }
    int start = num-n;
    for(int i=0; i<n; i++) {
        int k=start;
        for(int j=0; j<n-i; j++) {
            cout<<k;
            k++;
            if(j<n-i-1){
                cout<<"*";
            }
        }
        start = start - (n-i-1);
        cout<<endl;
    }

}

int main() {

    int n;
    cout<<"Enter the size: "<<endl;
    cin>>n;

    fancyPattern2(n);

    return 0;
}