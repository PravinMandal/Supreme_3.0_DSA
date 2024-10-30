//missing element from array with duplicates
#include<iostream>
#include<vector>
using namespace std;


int main(){

    vector<int>v={1,3,5,3,4};
    v.insert(v.begin(),69);
    //69 ko 0th index pr insert kr diya but uska koi kaam nhi h just kr rhe h taaki index ko 1 se use kr pau
    //vector ki size 6 ho gyi h

    for(int i=1 ; i<v.size() ; i++){
        //hum values ko as a index smjh kr use krenge 
        int index=abs(v[i]); //abs +ve krne ke liye use krte h ab index toh -ve nhi ho skta isiliye
        if(v[index]>0){
            v[index] *= -1; // v[index]= v[index]*-1;
        }
    }

    int missing=-1;
    for(int i=1 ; i<v.size() ; i++){
        if(v[i]>0){
            missing=i; //kyuki jo +ve h mtlb uss index pr jaakr hum kbhi uss index ke number ko -ve hi nhi kr paye mtlb wo index hi missing number hai
            break;
        }
    }
    cout<<endl;
    cout<<"Missing number is: "<<missing<<endl;
    return 0;
}