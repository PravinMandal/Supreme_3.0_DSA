#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    //creation
    unordered_map<int,int> Desk_map; // roll_no , Desk_no

    Desk_map[1]= 52;
    Desk_map[2]= 53;
    Desk_map[3]= 57;
    Desk_map[2]= 59; // reassign kr rhe h kyuki 2 pehle se hi h

    //ab isse iterate krne ke liye iterator banana pdega
    unordered_map<int,int>::iterator it;

    for(it= Desk_map.begin() ; it!= Desk_map.end() ; it++){
        int key= it->first; //syntax
        int value= it-> second;

        cout<<"Key: "<<key<< "  Value: "<<value<<endl;
    }
    cout<<endl;


    //another syntax

    for(auto it2 : Desk_map){
         int keys= it2.first; //syntax
        int values= it2.second;

        cout<<"Key: "<<keys<< "  Value: "<<values<<endl;
    }

    //find? kaise kre map mai
    // suppose key value 2 ka find krna h

    if(Desk_map.find(2) != Desk_map.end()){ //end ke equal nhi hua mtlb pehle hi mil gya mtlb // Found

        int value= Desk_map[2];
        cout<<"Value: "<< value<<endl;
    }
    else
    {
        //not found
        cout<<"Not found: ";
    }

    //deletion 
    //key se hi delete hoga

    Desk_map.erase(2); //erase ho gya
    cout<<"After erase"<<endl;
     for(auto it2 : Desk_map){
         int keys= it2.first; //syntax
        int values= it2.second;

        cout<<"Key: "<<keys<< "  Value: "<<values<<endl;
    }

    if(Desk_map.find(2) != Desk_map.end()){ //end ke equal nhi hua mtlb pehle hi mil gya mtlb // Found

        int value= Desk_map[2];
        cout<<"Value: "<< value<<endl;
    }
    else
    {
        //not found
        cout<<"Not found! ";
    }






    return 0;
}