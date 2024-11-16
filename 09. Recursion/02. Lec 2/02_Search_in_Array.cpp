#include<iostream>
using namespace std;

bool SearchInArray(int arr[], int size , int index , int target){

    //base case
    if(index==size){
        //yaha tak aa gya mtlb target nhi mila kyuki array ke bound ke bahar aa gya
        return false;
    }

    if(arr[index]==target){
        return true;
    }

    bool ans=SearchInArray(arr,size,index+1,target);
    return ans;

}

int main(){

    int arr[]={10,20,30,40,50};
    int size=5;
    int index=0;
    int target=40;

    bool ans=SearchInArray(arr,size,index,target);
    cout<<ans;


    return 0;
}