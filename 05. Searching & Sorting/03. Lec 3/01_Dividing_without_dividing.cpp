// Given two integers one is a dividend and the other is the divisor,
// we need to find the quotient when the dividend is divided by the divisor without the use of any ” / “ and ” % “ operators

// Input: dividend = 10, divisor = 2
// Output: 5
// Explanation: 10/2 = 5.

// Input: dividend = 10, divisor = 3
// Output: 3
// Explanation: 10/3 = 3.33333… which is truncated to 3.

// Input: dividend = 10, divisor = -2
// Output: -5
// Explanation: 10/-2 = -5


//ye bhi search space ka question hai

#include<iostream>
using namespace std;

int GetQuotient(int dividend, int divisor)
{
    int s=0;
    int e=dividend;
    int mid = s+(e-s)>>1; // idhr humne right shift kiya 2 se divide krne ke liye kyuki divide ka use nhi kr skte
    int ans =-1;

    while( s<=e )
    {
        if((divisor*mid) == dividend) // divisor*quotient+remaider= dividend
        {
            return mid;
        }
        else if((divisor*mid) < dividend)
        {
            //abhi kam hai toh ye ans ho bhi skta h nhi bhi soo store and compute
            ans=mid;
            s=mid+1;
        }
        else
        {
            //ye toh answer ho hi nhi skta
            e=mid-1;

        }
        //ye mai humesha bhul jaata hu
        mid = s+(e-s)>>1;

        
    }
    return ans;
}

int main()
{
    int dividend = 20;
    int divisor = -5;

    int ans= GetQuotient(abs(dividend),abs(divisor));// abs mtlb absolute, ye mod ki tarah kaam krta h -ve rhega toh usse bhi +ve krke bhejega
    
    if( dividend*divisor < 0 )
    {
        ans=0-ans;
    }
    cout<<"Quotient is: "<< ans<<endl;

    return 0;
}