//isme hume pivot index btana h mtlb uss index ke left ke saare values ko sum krdo wo equal aana chahiye uske right ke saare values ke sum ke

#include<iostream>
using namespace std;

int PivotIndex(int arr[] , int n){//1,7,3,6,5,6

    for(int i=0 ; i<n ; i++){
        if(i==0) i++;

        int ans1=0;
        for(int k=0 ; k<i ; k++){
             ans1=ans1+ arr[k];
        }


        int ans2=0;
        for(int j=i+1 ; j<n ; j++){
             ans2=ans2+arr[j];
        }

    
        if(ans1==ans2){
            return i;
        }

    }
    return -1;

}


int main(){

    int arr[]={1,7,3,6,5,6};
    int size=6;

    int ans = PivotIndex(arr, size);
    cout<<"Pivot Index is : "<<ans<<endl;


    return 0;
}