#include <iostream>
using namespace std;

int main()
{
    int n, m, sum = 0;
    cout << " Enter n:- ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {

        cout << "Enter m:-  ";
        cin >> m;
        sum = sum + m;
    }
    cout << "Total sum is:- " << sum;

    return 0;
}