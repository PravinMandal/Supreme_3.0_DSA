#include <iostream>
using namespace std;
int main()
{

    for (int i = 1; i <= 2; i = i + 1)
    {
        for (int j = 1; j <= 2; j = j + 1)
            cout << i * j << " ";
    }

    return 0;
}