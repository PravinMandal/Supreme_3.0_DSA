#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;


int main() {

    unordered_map<int,string> uMap;
    map<int,string> oMap;

    uMap[2] = "baleno";
    uMap[1] = "scorpio";
    uMap[3] = "maruti";

    oMap[2] = "baleno";
    oMap[1] = "scorpio";
    oMap[3] = "maruti";

    
    cout<<"Printing unordered Map: "<<endl;
    for(auto it: uMap) {
        cout<<it.first<<"->"<<it.second<<endl;
    }

    cout<<endl<<"Printing ordered Map: "<<endl;
    for(auto it: oMap) {
        cout<<it.first<<"->"<<it.second<<endl;
    }


    //search or find
    // 2 method h: count() and find()

    //find() , iterator return krta h
    if(uMap.find(3) == uMap.end()) {
        //find krte krte end tak pohoch gya
        //not found
        cout<<"Element not found"<<endl;
    }
    else {
        cout<<"Element found"<<endl;
    }

    //count()
    if(oMap.count(4) == 0) {
        cout<<"Element not found"<<endl;
    }
    else {
        cout<<"Element found"<<endl;
    }


    return 0;
}