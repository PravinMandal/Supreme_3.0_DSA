#include<iostream>
#include<math.h>
using namespace std;



void printcounting()
{
    for( int i=1;i<=100;i++)
    {
        cout<<i<<" ";
    }
    
}


int simpleinterest(int p, int r, int t)
{
    int SI = (p * r * t)/100 ;
    return SI;
}

void votechecker(int age)
{
    
    if ( age<=18)
    {
        cout<<" Not eligible for voting ";
    }
    else
    {
        cout<<"Eligible for voting ";
    }
}

// M is the amount you receive upon maturity.
// P is the amount you invest at regular intervals.
// n is the number of payments you have made.
// i is the periodic rate of interest.

// M = P × ({[1 + i]^n – 1} / i) × (1 + i).



double sipcalculator( int p ,int n, int i)
{
   double m= p*((pow(1+i, n)-1)/i)*(1+i);
   return m;
}



int main()
{
 printcounting();

 cout<<endl;

 int answerofsimpleinterest=simpleinterest (5000, 12 ,2);
 cout<< answerofsimpleinterest;

 cout<<endl;



votechecker(17);

cout<<endl;


cout<<sipcalculator(500,10, 12);
// cout<< maturityAmount;






return 0;
}