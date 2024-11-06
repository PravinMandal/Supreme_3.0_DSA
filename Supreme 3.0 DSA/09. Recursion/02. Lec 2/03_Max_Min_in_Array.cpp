#include<iostream>
using namespace std;

void MaxinArray(int arr[], int size , int index, int &maxi){
    //base case
    if(index==size){
        return;
    }
    maxi=max(maxi,arr[index]);

    MaxinArray(arr,size,index+1,maxi);
}

void MininArray(int arr[], int size , int index, int &mini){
    //base case
    if(index==size){
        return;
    }
    mini=min(mini,arr[index]);

    MininArray(arr,size,index+1,mini);
}
int main(){

    int arr[]={40,10,90,50,20,70};
    int size=6;
    int index=0;
    int maxi=INT32_MIN;
    int mini=INT32_MAX;

    MaxinArray(arr,size,index,maxi);
    cout<<"Max no in array: "<<maxi<<endl;

    MininArray(arr,size,index,mini);
    cout<<"Min no in array: "<<mini<<endl;



    return 0;
}