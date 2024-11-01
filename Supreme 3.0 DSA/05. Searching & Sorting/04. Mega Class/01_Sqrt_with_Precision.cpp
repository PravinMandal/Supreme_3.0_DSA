//when can i apply search space pattern
//1. answer range mai aana chahiye , determine range
//2. hum jo mid nikalte h usse hum easily proof kr paaye ki wo answer hai ki nhi

#include<iostream>
#include<algorithm>
using namespace std;

int mysqrt(int num)
{
    int s=0;
    int e=num;
    int mid=s+((e-s)>>1);
    int ans=-1;

    while(s<=e){
        
        int prod=mid*mid;
        if(prod==num){
            ans=mid;
            return ans;
        }
        else if(prod<num){
            //ho bhi skta h nhi bhi
            //store and compute
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }

       mid=s+((e-s)>>1);
    }
    return ans;
}

double precisionSqrt(int n){

    double sqrt=mysqrt(n);
    int precision=13;
    double step=0.1;

    while(precision--){ // precision-- kiye taaki wo utne baar chal paye and -- hone ke baad utne number ke baad wo 0 bann jayega and loop stop ho jayega
        double j=sqrt;
        while(j*j<=n){
            sqrt=j;
            j=j+step; //7.1;
        }
        //after this while loop precision badhte jayega
        step=step/10;

    }
    return sqrt;

}

int main(){

    int n=63;

    double ans=precisionSqrt(n);
    printf("Precision Sqrt:  %.13f\n", ans);
    // cout bss 5 precision tk print kr skta h isilye printf use kr rhe h and isme custom precision daal skte h
    // isme humne %.13f mtlb 13 precision daala h and 'f' ka mtlb float
    // cout<<ans;





    return 0;
}