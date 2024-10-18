#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<int>TellPrime(int n){

    vector<int>prime(n+1,true);
    prime[0]=prime[1]=false;
    for(int i=2 ; i<=sqrt(n) ; i++){ 
        /*optimization 2. ab optimization 1 mai humne dekha ki wo i*i se start hota h
         isse samjhne ke liye 25 tk ka prime number dhundhte h. see hum i*i mai 5 put krenge joki 25 ka sqrt h uske baad wale waise bhi check nhi honge kyuki 6*6 toh 36 ho jaata h and waha tak ka check hi nhi krna toh hume outer loop sqrt of n tak hi chalana chahiye
         and uske pehle ke toh waise bhi check ho chuke h soo wo waste hi hota h and baar baar wahi check krke mark krta h joki unefficient tha but ab thik h  */
        if(prime[i]){
            for(int j=i*i ; j<=n ; j=j+i){ 
                /*optimization 1. 2*i se start krne pr aage ke saare number baar baar wahi se start krte jo pehle bhi humne not prime mark 
                   kiya hua h sooo agar hum i*i kre toh wo problem thik ho jaati h for eg 5 ,  isko pehle ki tarah krte toh 5,10,15,20 ye sab wapas check hota but jab ki ye sab pehle se not prime marked hai. i*i krne pr ye sb skip hoke sidhe 25 se start hoga and ye pattern hum dry run krke sabme check kr skte h sahi aata h i*i ke pehle wale sab check ho chuke hote h. */

                prime[j]=false;
            }
        }
    }
    return prime;


}


int main(){
    int n;
    cout<<"Enter the number till you want prime numbers:- ";
    cin>>n;

    vector<int> prime=TellPrime(n);
    for(int i=0 ; i<=n ; i++){

    if(prime[i]){
        cout<<i<<" ";
    }


    }


    return 0;
}