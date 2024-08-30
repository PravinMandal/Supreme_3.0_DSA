#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

int main()
{
    vector<int> arr;
    arr.push_back(11);
    arr.push_back(22);
    arr.push_back(33);
    arr.push_back(44);
    arr.push_back(55);

    make_heap(arr.begin(), arr.end());
    for(int a: arr) 
    {
        cout<< a<<" ";
    }
    cout<<endl;
    //insertion
    arr.push_back(99);
    for(int a: arr) 
    {
        cout<< a<<" ";
    }
    cout<<endl;
    push_heap(arr.begin(), arr.end());
    for(int a: arr) 
    {
        cout<< a<<" ";
    }
    cout<<endl;

    //deletion
    pop_heap(arr.begin(), arr.end());
     for(int a: arr) 
    {
        cout<< a<<" ";
    }
    cout<<endl;
    //ab poore vector se usse hatana pdega wo last mai shift ho gya h
    arr.pop_back();
     for(int a: arr) 
    {
        cout<< a<<" ";
    }
    cout<<endl;



    //sort_heap
    sort_heap(arr.begin(), arr.end());
     for(int a: arr) 
    {
        cout<< a<<" ";
    }
    cout<<endl;

    



    return 0;
} 

