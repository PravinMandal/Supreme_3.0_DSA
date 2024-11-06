#include<iostream>
using namespace std;

int binarysearchRecursive(int arr[], int size, int s, int e , int target){
    //base case
    if(s>e){
        //start end se aage ho gya and ab tak target nhi mila mtlb target not found
        return -1;
    }
    int mid=s+(e-s)/2;
    if(arr[mid]==target){
        return mid;
    }
    if(arr[mid]<target){
        //right jao
        // s=mid+1;
        return binarysearchRecursive(arr,size,mid+1,e,target);
    }
    else{
        //left jao 
        return binarysearchRecursive(arr,size,s,mid-1,target);
    }
}

int binarysearch(int arr[], int size, int target){
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;

    while(s<=e){
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]<target){
            //right mai jao
            s=mid+1;
        }
        else{
            //left mai jao
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    //not found
    return -1;
}


int main(){

    int arr[]={10,20,30,40,50,60,70};
    int size=7;
    int target =10;
    int s=0;
    int e=size-1;

    int ans=binarysearch(arr,size,target);
    cout<<"Target index: "<<ans<<endl;

    int ans2=binarysearchRecursive(arr,size,s,e,target);
    cout<<"Target index: "<<ans2<<endl;





    return 0;
}