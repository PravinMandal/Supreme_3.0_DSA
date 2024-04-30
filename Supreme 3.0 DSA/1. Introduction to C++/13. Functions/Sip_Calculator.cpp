#include <iostream>
#include <math.h>
using namespace std;

// M is the amount you receive upon maturity.
// P is the amount you invest at regular intervals.
// n is the number of payments you have made.
// i is the periodic rate of interest.
// r = Expected return rate in % per annum

// M = P × ({[1 + i]^n – 1} / i) × (1 + i).
// i = r / 100 / 12

double sipcalculator(double p, double r, double n)

{
    double i=r/100/12;
    double m = p * ((pow(1 + i, n) - 1) / i) * (1 + i);
    return m;
}

int main()
{

    double maturityAmount = sipcalculator(25000, 12 , 24);
    cout << maturityAmount;
    return 0;
}