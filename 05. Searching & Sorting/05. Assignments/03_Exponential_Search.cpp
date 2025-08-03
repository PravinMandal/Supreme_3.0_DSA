#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int s, int e, int target) {
    int mid = s + (e-s)/2;
    while(s<=e) {
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target){
            s = mid+1;
        } 
        else {
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}

int expSearch(vector<int>& arr, int target) {
    int size = arr.size();
    if(arr[0] == target) return 0;
    int i = 1;
    while(arr[i]<=target && i<size) {
        i = i*2;
    }
    return binarySearch(arr, i/2, min(i,size), target);
}

int main() {
    
    vector<int> arr = {3,4,5,6,11,13,14,15,56,70};    
    int target = 13;
    int ans = expSearch(arr, target);
    cout<<"Target is on index: "<<ans<<endl;

    return 0;
}