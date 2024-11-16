//isme hume pivot index btana h mtlb uss index ke left ke saare values ko sum krdo wo equal aana chahiye uske right ke saare values ke sum ke

#include<iostream>
#include<vector>
using namespace std;


//brute force method
int PivotIndex(vector<int>& arr ){//1,7,3,6,5,6
    int n=arr.size();
    for(int i=0 ; i<n ; i++){

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


//optimal solution
int prefixSumApproch(vector<int>& arr){
    int n=arr.size();
    vector<int>lsum(n,0); 
    vector<int>rsum(n,0);

    for(int i=1 ; i<n ; i++){
        lsum[i]=lsum[i-1]+arr[i-1];
    }

    for(int i=n-2 ; i>=0 ; i--){
        rsum[i]=rsum[i+1]+arr[i+1];
    }

    for(int i=0 ; i<n ; i++){
        if(lsum[i]==rsum[i]){
            return i;
        }
    }

    return -1;

}


int main(){

    // int arr[]={1,7,3,6,5,6};
    // int size=6;

    vector<int>arr;
    arr.push_back(1);
    arr.push_back(7);
    arr.push_back(3);
    arr.push_back(6);
    arr.push_back(5);
    arr.push_back(6);

    int ans1 = PivotIndex(arr);
    cout<<"Pivot Index is : "<<ans1<<endl;


    int ans2= prefixSumApproch(arr);
    cout<<"Pivot Index is : "<<ans2<<endl;


    return 0;
}