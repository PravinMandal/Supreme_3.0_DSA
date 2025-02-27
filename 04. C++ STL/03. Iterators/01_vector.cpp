#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> arr = {1,2,3,4,5};
    vector<int>::iterator it = arr.begin();

    while(it != arr.end()) {
        cout<<*it<<" ";
        it++;
    }
    return 0;
}
