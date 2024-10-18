#include<iostream>
#include<vector>
using namespace std;

int CountPrime(int n){

    vector<bool>prime(n,true);
    prime[0]=prime[1]=false;
    int count=0;
    for(int i=2 ; i<n ; i++){
        if(prime[i]){
            count++;
            for(int j=2*i ; j<n ; j=j+i){
                prime[j]=false;
            }
        }
    }
    return count;


}


int main(){
    int n;
    cout<<"Enter the number till you want prime numbers:- ";
    cin>>n;

    int ans=CountPrime(n);
    cout<<"There are "<<ans<<" prime numbers till "<<n<<endl;


    return 0;
}