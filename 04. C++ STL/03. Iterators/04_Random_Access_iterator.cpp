#include<iostream>
#include<vector>
using namespace std;


int main() {

    vector<int> arr = {10,20,30,40,50};

    vector<int>::iterator it = arr.begin();
    while(it != arr.end()) {
        //write
        (*it) = (*it) + 7;
        //read
        cout<<*it<<" ";
        //move forward
        it++;
    }cout<<endl;

    //let's move in backward direction
    it = arr.end();
    while(it != arr.begin()) {
        it--; //arr.end() -1 mai element hota h arr.end() mai nhi
        //write
        (*it) = (*it) + 3;
        //read
        cout<<*it<<" ";
    }cout<<endl;
    
    //arr = 20,30,40,50,60 , arr ab aisa bann chuka h
    //random access
    it = arr.begin()+3;
    cout<<*it<<endl;

    return 0;
}