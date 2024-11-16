// //code before debugging
// void linearSearch(int arr[], int n ,int val){
//     for(int i=0;i<n;i++){
//         if(arr[i]==val){
//             return;
//         }
//     }
//     return;
// }

#include<iostream>
using namespace std;

bool linearSearch(int arr[], int n ,int val){
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            return true;
        }
    }
    return false;
}

int main(){

    int arr[]={2,1,4,3,7,5};
    int n=6;
    int target=7;

    bool ans=linearSearch(arr,n,target);
    if(ans){
        cout<<"Found the target";
    }
    else
    {
        cout<<"not found";
    }

    return 0;

}