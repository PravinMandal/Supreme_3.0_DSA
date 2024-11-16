// //code to be debug
// void swapAlternate(int arr[],int size){
//     for(int i=0;i<size-1;i=i+2){
//         int temp = arr[i];
//         arr[i+1] = arr[i];
//         arr[i] = temp;
//     }
// }

#include<iostream>
using namespace std;

void swapAlternate(int arr[],int size){
    for(int i=0;i<size-1;i=i+2){
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
}

int main(){

    int arr[]={2,1,4,3,7,5};
    int n=6;

    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    swapAlternate(arr,n);

    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;

}