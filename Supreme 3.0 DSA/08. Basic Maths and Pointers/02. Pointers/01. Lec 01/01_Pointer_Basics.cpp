#include<iostream>
using namespace std;

int main(){

    // int a=5;
    // int* ptr;
    // cout<<ptr;

    // cout<<sizeof(ptr)<<endl;

    // char ch='a';
    //  char* cptr=&ch;
    //  cout<<sizeof(cptr)<<endl;

    //  long b=1000;
    //  long* lptr=&b;
    // cout<<sizeof(lptr)<<endl;


    int a=20;
    int* ptr=&a;

    cout<<a<<endl;
    cout<<&a<<endl;
    // cout<<*a<<endl; //dereference krna chahta h but dereference toh address ka hota h and 'a' ne address show nhi kiya h toh error dega
    cout<<ptr<<endl;
    cout<<&ptr<<endl;
    cout<<*ptr<<endl;

    ptr=ptr+1; // direct iss line ko cout krne pr error aa rha tha
    cout<<ptr<<endl;

    *ptr=(*ptr)/2; // direct iss line ko cout krne pr error aa rha tha
    cout<<*ptr<<endl;

    *ptr=*ptr+1; // direct iss line ko cout krne pr error aa rha tha
    cout<<*ptr<<endl;

    cout<<a<<endl;







    return 0;
}