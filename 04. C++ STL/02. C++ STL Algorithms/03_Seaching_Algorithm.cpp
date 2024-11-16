#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>

using namespace std;

int main()
{
    //binary_search
    vector<int>first(5);

    first.push_back(10);
    first.push_back(20);
    first.push_back(30);
    first.push_back(40);
    first.push_back(50);



    //// binary_search
    // int target= 40;
    // bool ans = binary_search(first.begin(), first.end(), target);
    // if( ans==1)
    // {
    //     cout<<"Target found";
    // }
    // else if( ans==0)
    // {
    //     cout<<"Target not found";
    // }



    // //lower_bound
    // int target = 35;
    // auto it= lower_bound(first.begin(), first.end(), target);
    ////agar target mil gya toh wahi return kr dega 
    ////but nhi mila then aage wala value mtlb bada wala value return kr dega
    // cout<<*it<<endl;



    // //upper_bound
    // auto it= upper_bound(first.begin(), first.end(), 40);
    // //40 hai vector mai still wo aage wala 50 de dega because upper bound hai
    // cout<<*it<<endl;



    



    return 0;
}