//gfg question : count digits
//leetcode: 2520. Count the Digits That Divide a Number
//count krna h number of digits ussi number mai jo uss number ko perfectly divide kr sake

#include<iostream>
using namespace std;

int countnumber(int num){
        int count=0;
        while(num!=0){
            num=num/10;
            count++;
        }
        return count;
    }
    
int evenlyDivides(int num){
    int n=countnumber(num);
    int initialans=num;
    int ans=0;
    int remander=0;
    for(int i=0 ; i<n ;i++){
        remander= num%10;
         num=num/10;
        if(remander!=0){
          
        if(initialans%remander==0){
            ans++;
        }
        }
        
    }
    return ans;
        
    }

int main(){

    int num=12;
    int ans=evenlyDivides(num);
    cout<<ans;


    return 0;
}