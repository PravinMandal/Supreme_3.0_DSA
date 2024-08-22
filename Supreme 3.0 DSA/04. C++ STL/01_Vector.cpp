#include<iostream>
#include<vector>
using namespace std;

int main()
{

    vector<int>marks;
    marks.push_back(10);
    marks.push_back(20);
    marks.push_back(30);
    marks.push_back(40);


    //traversing the vector using iterator

    vector<int>::iterator it=marks.begin();

    while( it != marks.end())
    {
        cout<< *it <<" ";
        it++;
    }


    return 0;
}