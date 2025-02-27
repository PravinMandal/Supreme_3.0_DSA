#include<iostream>
#include<forward_list>
using namespace std;


int main() {

    forward_list<int> list;
    //forward list ko as a singly linked list maan skte ho
    //jo normal list hota h wo doubly linked list ke jaise behave krta h

    list.push_front(10); //sirf push_front() hi kr skte h
    list.push_front(20);
    list.push_front(30);

    forward_list<int>::iterator it = list.begin();
    while(it != list.end()) {
        (*it) = (*it) + 5;
        it++;
    }
    it = list.begin();
    while(it != list.end()) {
        cout<<*it<<" ";
        it++;
    }

    //hum aisehi iterate kr skte h 
    // backward nhi kr skte ki, list.end() se list.begin() tk nhi jaa skte
    //it-- kroge toh error dega, kyuki ye singly linked list ki tarh behave krega and usme backward nhi jaa skte

    return 0;
}