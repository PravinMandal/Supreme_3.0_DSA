#include <iostream>
using namespace std;

int main()
{
    char grade;
    cout << "Enter your grade:- ";
    cin >> grade;
    // if (grade == 'a')
    // {
    //     cout << "Your marks will be in range of 90 to 100";
    // }
    // else if (grade == 'b')
    // {
    //     cout << "Your marks will be in range of 80 to 90";
    // }
    // else if (grade == 'c')
    // {
    //     cout << "Your marks will be in range of 70 to 80";
    // }
    // else if (grade == 'd')
    // {
    //     cout << "Your marks will be in range of 60 to 70";
    // }
    // else
    // {
    //     cout << "Your marks will be less then 60";
    // }

    // return 0;


    // switch case
    switch(grade)
    {
        case 'a': cout << "Your marks will be in range of 90 to 100"<<endl;
        break;
        case 'b': cout << "Your marks will be in range of 80 to 90"<<endl;
        break;
        case 'c': cout << "Your marks will be in range of 70 to 80"<<endl;
        break;
        case 'd': cout << "Your marks will be in range of 60 to 70"<<endl;
        break;
        default: cout << "Your marks will be less then 60"<<endl;
    }
}