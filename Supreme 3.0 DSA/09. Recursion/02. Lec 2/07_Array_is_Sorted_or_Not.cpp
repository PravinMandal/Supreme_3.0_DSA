#include<iostream>
using namespace std;

bool ArrayisSortedOrNot(int arr[], int size , int index){
    if(index==size){
        //last tak aa gya bina false return hue
        //array sorted hai 
        return true;
    }
    if(arr[index]>arr[index+1] && (index+1)< size)
    {
        //aage wala element chhota h 
        //sorted nhi h
        return false;
    }
    bool ans=ArrayisSortedOrNot(arr,size,index+1);
}

int main(){

    int arr[]={10,20,30,40,60,15};
    int size=6;
    int index=0;

    bool ans=ArrayisSortedOrNot(arr,size,index);
    cout<<ans<<endl;

    return 0;
}