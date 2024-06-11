#include <iostream>
#include <math.h>
using namespace std;

void printcounting()
{
    for (int i = 1; i <= 100; i++)
    {
        cout << i << " ";
    }
}

int simpleinterest(int p, int r, int t)
{
    int SI = (p * r * t) / 100;
    return SI;
}

void votechecker(int age)
{

    if (age <= 18)
    {
        cout << " Not eligible for voting ";
    }
    else
    {
        cout << "Eligible for voting ";
    }
}

int main()
{
    printcounting();

    cout << endl;

    int answerofsimpleinterest = simpleinterest(5000, 12, 2);
    cout << answerofsimpleinterest;

    cout << endl;

    votechecker(17);

    cout << endl;

    return 0;
}