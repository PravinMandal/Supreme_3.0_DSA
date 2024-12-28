//leetcode:- 46. Permutaion
#include<iostream>
using namespace std;

void PrintPermutaion(string &str, int i){
    //base case
    if(i>=str.length()){
        cout<<str<<endl;
        return;
    }

    //mai i wale case pr sbko chance dunga
    for(int j=i ; j<str.length() ; j++){
        //swap krne pr wo position pr sbko mauka milega
        swap(str[i], str[j]);
        //recursion samhal lega aage ka
        PrintPermutaion(str,i+1);
        //backtracking , jo change kiya h usse wapas pehle jaise banana h
        swap(str[i], str[j]);
    }
}

int main(){
    string str="abc";
    int i=0;
    PrintPermutaion(str,i);
}