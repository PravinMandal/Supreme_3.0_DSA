#include<iostream>
using namespace std;

 void printOddinArray(int arr[],int size,int index){

    //base case
    if(index==size){
        return;
    }
    if(arr[index]%2){//odd hoga toh hi enter krega
    cout<<arr[index]<<" ";
    }

    printOddinArray(arr,size,index+1);

 }


int main(){

    int arr[]={10,11,23,33,45,63,18,17};
    int size=8;
    int index=0;

    printOddinArray(arr,size,index);

    return 0;
}