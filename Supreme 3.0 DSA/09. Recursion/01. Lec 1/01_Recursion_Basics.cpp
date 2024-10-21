#include<iostream>
using namespace std;

int getFactorial(int n){

    //Base case -> mandatory
    if(n==0 || n==1){
        return 1;
    }


    //recursive call -> mandatory
    //fact(n)= n * fact(n-1);
    //badi prblm ka sol choti prblm pr depend kr rha hai
    int recursionKaAns=getFactorial(n-1);
    //head recursion because bottom mai nhi h

    int finalans= n * recursionKaAns;

    return finalans;

    //processing -> Optional

}


//printing numbers from n to 1
void printCounting(int n){
    //base case
    if(n==0){
        return;
    }

    //processing 
    cout<<n<<" ";

    //recursive call
    printCounting(n-1); //tail recursion bcz ye bottom mai hai

}

//printing numbers from 1 to n
void printCountingStraigt(int n){

    //base case
    if(n==0){
        return;
    }

    //recursive call
    printCountingStraigt(n-1);

    //processing
    cout<<n<<" ";

}


int Power(int n){

    //base case
    if(n==0){
        return 1;
    }

    //recursion call
    //pow(2,n)= 2 * pow(2,n-1)
    int recursionAns=Power(n-1);
    int ans= 2 * recursionAns;
    return ans;
    
    //processing


}



int fib(int n){
    //base case
    if(n==0 || n==1){
        return n;
    }

    //recursion call
    int ans=fib(n-1)+fib(n-2);


    return ans;

    //processing

}



int getSum(int n){

    //base case
    if(n==1){
        return 1;
    }

    //recursive relation
    //sum(n)= n + sum(n-1)
    int recAns=getSum(n-1);
    int ans= n + recAns;

    return ans;

    //processing


}



int main(){

    int n;
    cout<<"Enter the number: ";
    cin>>n;


    int ans=getFactorial(n);
    cout<<"Factorial of "<<n<<" is: "<<ans<<endl;


    //printing numbers n to 1
    printCounting(n);
    cout<<endl;


    //printing numbers 1 to n
    printCountingStraigt(n);
    cout<<endl;


    int ans2=Power(n);
    cout<<ans2<<endl;


    int fibans=fib(n);
    cout<<fibans<<endl;


    int sumAns=getSum(n);
    cout<<sumAns<<endl;
    
    


    return 0;
}