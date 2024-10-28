#include<iostream>
#include<algorithm>
using namespace std;

bool checkTwoSum(int arr[] , int n , int target){
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(arr[i] + arr[j] == target){
                return true;
            }
        }
    }

    return false;

    //iski time complexity o(n^2) hai , bohot zyada h
}



//ye zyada aacha h because time complexity kam h
bool TwoPointerApproch(int arr[] , int n , int target ){


    sort(arr,arr+n); // 1,4,6,8,10,45 //o(nlogn)

    int i=0;
    int j=n-1;
    while(i<j){
        int currSum=arr[i]+arr[j];
       
        if(currSum==target){
            return true;
        }
        else if(currSum<target){ // sum target se chhota h toh i++ kro taaki number badh jaye 
            i++;
        }
        else if(currSum>target){ // sum taget se bada h toh j-- 
            j--;
        }
    }
    return false;


}




int main(){

    int arr[]{1,45,8,6,10,4};
    int size=6;
    int target= 17;

    bool ans=checkTwoSum(arr , size , target);
    cout<<ans<<endl;

    bool ans2=TwoPointerApproch(arr , size , target);
    cout<<ans2<<endl;



    return 0;
}