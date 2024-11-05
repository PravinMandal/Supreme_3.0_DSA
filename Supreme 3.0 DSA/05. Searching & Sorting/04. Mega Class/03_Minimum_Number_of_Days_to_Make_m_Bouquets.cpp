//leetcode qNo 1482 
// You are given an integer array bloomDay, an integer m and an integer k.
// You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
// The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
// Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.


#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

bool canwemakeMbouquetsinDdays(vector<int>&bloomDay, int m,int k, int day){
    int counter=0;
    for(int i=0 ; i<bloomDay.size() ; i++){
        if(bloomDay[i]<= day){// flowers bloom ho gya h
            counter++;
        }
        if(counter==k){
            m--;
            counter=0;
            if(m==0) break;
        }
        if(bloomDay[i]>day){
            counter=0;
        }
    }
    return m==0; //agar m==0 ho gya mtlb uss din bann jayega bouquets return true ho jayega
}


int minDays(vector<int>& bloomDay, int m, int k){
    long long int requirement= (long long int)m * (long long int)k;
    if(bloomDay.size()< requirement) return -1;
    if(bloomDay.size()==requirement) return *max_element(bloomDay.begin() , bloomDay.end()); //aur efficient bann gya isse just think 
    //agar 6 flower h and bouquet banane ke liye bhi 6 flower hi lgega toh hume last flower ke bloom hone tak ka wait krna pdega

    int start=*min_element(bloomDay.begin() , bloomDay.end());
    int end=*max_element(bloomDay.begin() , bloomDay.end());
    int ans=0;

    while(start<=end){
        int mid=start+(end-start)/2;
        int day=mid;
        if(canwemakeMbouquetsinDdays(bloomDay,m,k,day)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
 }

int main(){
    vector<int>bloomDay ={1,10,3,10,2};
    int m=3;
    int k=1;

    int ans=minDays(bloomDay,m,k);
    cout<<"Minimum Number of Days to Make m Bouquets: "<<ans;


}