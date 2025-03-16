#include<iostream>
#include<vector>
using namespace std;

int main() {

    vector<vector<int>> arr;
    arr= {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    for(int col=0; col<arr[0].size(); col++) {
        //ab jo traversal h wo hume toggle krna pdega
        //even col number mai top to bottom
        //odd col number mai bottom to top
        if((col & 1) == 0) {
            //iske andar aaya mtlb even h
            //top to bottom jaana h
            for(int row=0; row<arr.size(); row++) {
                cout<<arr[row][col]<<" ";
            }
        }
        else {
            for(int row=arr.size()-1; row >= 0 ; row--) {
                cout<<arr[row][col]<<" ";
            }
        }
    }

    return 0;
}