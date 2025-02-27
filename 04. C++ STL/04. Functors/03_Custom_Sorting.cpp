#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Comparator {
public:
    int operator()(int a, int b) {
        //a > b -> true, hua toh 'a' pehle jayega 'b' ke mtlb bada wala pehle
        //descending order
        return a > b;
    }
};

int main() {

    vector<int> arr = {20,15,10,30,25};
    
    //mujhe agar desecding order mai sort krna h toh khud ka custom comparator likhna pdega
    sort(arr.begin(), arr.end(), Comparator());

    for(int a: arr) {
        cout<<a<<" ";
    }cout<<endl;

    return 0;
}