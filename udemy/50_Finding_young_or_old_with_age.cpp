#include <iostream>
using namespace std;
int main()
{
    int age;
    cout << "Enter your Age:- ";
    cin >> age;
    if (age >= 12 && age <= 50)
    {
        cout << "You are young !!! ";
    }
    else if (age >= 0 && age < 12)
    {
        cout << " You are just a kid ";
    }
    else if (age > 50 && age <= 150)
    {
        cout << " You are a Dadaji ";
    }
    else
    {
        cout << " Put your original age idiot ";
    }
    return 0;
}