#include<iostream>
using namespace std;

int main(){

    // char ch[]="LoveBabbar";
    // char* cptr=ch;
    // cout<<ch<<endl;
    // cout<<"Base address: "<<&ch<<endl;
    // cout<<cptr<<endl;


    char ch[100]="RacecaR";
    char* cptr=&ch[0];

    cout<<"ch:- "<<ch<<endl;
    cout<<"&ch[0]:- "<<&ch[0]<<endl;
    cout<<"&ch:- "<<&ch<<endl;
    cout<<"*(ch+3):- "<<*(ch+3)<<endl;
    cout<<"cptr:- "<<cptr<<endl;
    cout<<"&cptr:- "<<&cptr<<endl;
    cout<<"*(cptr+3):- "<<*(cptr+3)<<endl;
    cout<<"cptr+2:- "<<cptr+2<<endl;
    cout<<"*cptr:- "<<*cptr<<endl;
    cout<<"cptr+4:- "<<cptr+4<<endl;
    

    return 0;
}