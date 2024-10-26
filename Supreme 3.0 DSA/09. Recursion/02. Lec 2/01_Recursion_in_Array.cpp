#include<iostream>
using namespace std;

void PrintArray(int arr[] , int size , int index){

    //Base case
    if(index==size){
        return;
    }

    //processing
    cout<<arr[index]<<" ";

    //recursive call
    PrintArray(arr, size , index+1);

}


int main(){

    int arr[]={10,20,30,40,50,60};
    int size=6;
    int index=0;

    PrintArray(arr,size,index);




    return 0;
}