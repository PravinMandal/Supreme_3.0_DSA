#include<iostream>
using namespace std;

void fancyPattern1(int n) {

    if(n>9) {
        cout<<"Please enter number <=9 "<<endl;
        return;
    }
    char num = '1';
    int count = 1;
    for(int row=0; row<n; row++) {
        for(int col=0; col<8-row; col++) {
            cout<<"* ";
        }
        for(int col=0; col<row+1; col++) {
            // num = '1';
            cout<<num;
            if(count != 9){
                cout<<" * ";
            }
            if(row==8){
                count++;
            }
        }
        for(int col=0; col<8-row-1; col++) {
            cout<<"* ";
        }
        cout<<endl;
        num++;
    }

}

int main() {

    int n;
    cout<<"Enter the size: "<<endl;
    cin>>n;

    fancyPattern1(n);

    return 0;
}