// leetcode : 322. Coin Change
//You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

//Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

//You may assume that you have an infinite number of each kind of coin.


#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>&coins, int amount){
    //base case
    if(amount==0){
        //0 amount create krne ke liye 0 coins lgte h isiliye return 0
        return 0;
    }

    int minCoinAns=INT32_MAX;

    //har amount ke liye poore coins ke array ko traverse kr rhe h
    for(int i=0 ; i<coins.size() ; i++){
        int coin=coins[i];
        
        // if coin value > amount value , no need to call recursive function
        // agar coin chhota h amount value se then ke skte h recursive call
        if(coin<=amount){
            //1 coin toh use ho gya ab amount = amount-coin ho gya
            //baaki recursion samhal lega

            int recursionAns=solve(coins,amount-coin);
            //ho skta h recursionAns valid ho ya invalid ho
            //invalid case -> recursionAns -> INT_MAX
            //valid case -> recursionAns -> not equal to INT_MAX

            if(recursionAns!=INT32_MAX){
                //valid ans aaya h
                int coinsUsed=1+recursionAns;
                //kya above ans minimum hai
                minCoinAns=min(minCoinAns,coinsUsed);
            }
        }
    }
    return minCoinAns;
}



int coinChange(vector<int>&coins , int amount){
    int ans=solve(coins,amount);
    if(ans==INT32_MAX){
        return -1;
    }
    return ans;
}



int main(){

    vector<int>coins={1,2,5};
    int amount=11;

    int ans=coinChange(coins,amount);
    cout<<ans;



    return 0;
}