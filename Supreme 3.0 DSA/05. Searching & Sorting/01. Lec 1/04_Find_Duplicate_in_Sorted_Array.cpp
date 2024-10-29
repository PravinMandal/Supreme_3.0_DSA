#include<iostream>
using namespace std;

int findDuplicate(int arr[] , int n){

    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    int ans=-1;

    while(s<=e){
        int diff=mid-arr[mid];

        if(diff==0){
            //move right
            s=mid+1;
        }
        else if(diff==1){
            //ho bhi skta h nhi bhi store and compute
            //move left
            ans=arr[mid];
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;


}

int main(){

    int arr[]={0,1,2,3,4,5,5,6,7,8,9};
    int size=11;

    int ans=findDuplicate(arr,size);
    cout<<"Duplicate element is: "<<ans<<endl;



    return 0;
}