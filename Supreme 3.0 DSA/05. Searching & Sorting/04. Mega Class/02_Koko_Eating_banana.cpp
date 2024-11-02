// leetcode Qno 875: Koko eating banana
// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.


#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

bool CanKokoFinishBananasWithKspeed(vector<int>&piles,int h , int k){
    long long int TotalHoursTakenbyKokoToFinishAllBananas=0;
    for(int i=0 ; i<piles.size() ; i++){
        TotalHoursTakenbyKokoToFinishAllBananas += ceil(piles[i]/(double)k); 
        //k int tha toh typecast kr denge double mai tbhi ceil kaam krega kyuki ceil ke liye decimal chahiye toh hoga na but int nhi krta wo

        //ceil mtlb round off krke uska next number if decimal mai h
        // ceil(10/3)=3.33 = 4

        //floor mai niche wala le lega
        //floor(10/3)=3.33 =3
    }
    return TotalHoursTakenbyKokoToFinishAllBananas<=h;
    //agar condition satisfy hua then true jayega warna false 
}

int MinEatingSpeed(vector<int>& piles , int h){
    int s=1;
    auto it=max_element(piles.begin() , piles.end());
    int e=*it;
    int ans=-1;
    while(s<=e){
        int mid=s+((e-s)>>1);
        int k=mid;
        if(CanKokoFinishBananasWithKspeed(piles,h,k)){
            ans=k;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

int main(){

    vector<int> piles={3,6,7,11};
    int h=8;
    //hume k find krna hai
    int k=MinEatingSpeed(piles,h);
    cout<<"Min eating speed to eat all the banana's: "<<k<<endl;




    return 0;
}