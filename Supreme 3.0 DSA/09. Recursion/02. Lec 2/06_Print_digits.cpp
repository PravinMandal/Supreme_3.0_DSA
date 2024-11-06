#include<iostream>
using namespace std;

void PrintDigits(int num){
    //base case
    if(num==0){
        return;
    }

    //baaki recursion samhal lega
    int newdigit=num/10;
    PrintDigits(newdigit);

    //1 case mai samhalunga 
    int digit=num%10;
    cout<<digit<<" ";
}


int main(){

    int num=24392978;
    PrintDigits(num);




    return 0;
}