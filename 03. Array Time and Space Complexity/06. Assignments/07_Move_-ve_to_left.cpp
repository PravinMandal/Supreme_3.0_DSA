//Move all -ve numbers to left side of an array
#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int>arr = {1,2,-3,4,-5,6};

    int i=0;
    int j=arr.size()-1;
    while(i<j) {
        if(arr[i]<0) i++;
        else if(arr[j]>0) j--;
        else swap(arr[i], arr[j]);
    }

    for(auto i:arr) {
        cout<<i<<" ";
    }
    return 0;
}