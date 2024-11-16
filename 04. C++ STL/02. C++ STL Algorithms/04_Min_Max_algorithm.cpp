#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>

using namespace std;

int main()
{
    // min and max in ranges

     vector<int>arr;

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);


    auto it1= min_element(arr.begin(), arr.end());
    cout<<*it1<<endl;

    auto it2= max_element(arr.begin(), arr.end());
    cout<<*it2<<endl;


    return 0;
}