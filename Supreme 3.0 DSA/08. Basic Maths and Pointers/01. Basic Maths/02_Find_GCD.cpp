//GCD mtlb greatest common divisor
#include<iostream>
using namespace std;

int FindGCD(int a, int b)
{
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    while(a>0 && b>0){
    if(a>b){
        a=a-b;
    }
    if(b>=a){
        b=b-a;
    }
    }

    return a==0 ?b:a;
    
}


int main(){
    int a,b;
    cout<<"Enter number A and B to find there GCD: ";
    cin>>a>>b;

    int ans=FindGCD(a,b);
    cout<<"GCD of the given 2 numbers are: "<<ans<<endl;


    return 0;
}