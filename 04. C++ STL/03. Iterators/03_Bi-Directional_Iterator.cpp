#include<iostream>
#include<list>
using namespace std;


int main() {
    //list, deque ke implementation se bana h, toh hume isme forward as well as backward bhi move kr skte h
    //bi-directional iterator
    list<int> mylist;
    mylist.push_back(10);
    mylist.push_back(20);
    mylist.push_back(30);

    list<int>::iterator it = mylist.begin();

    while(it != mylist.end()) {
        (*it) = (*it) + 5;
        cout<<*it<<" ";
        it++;
    }cout<<endl;

    it = mylist.end();
    while(it != mylist.begin()) {
        it--; //pehle hi kr rhe h kyuki mylist.end pr toh kuch hota hi nhi mylist.end()-1 pr hota h
        (*it) = (*it) + 5;
        cout<<*it<<" ";
    }


    return 0;
}