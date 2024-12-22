#include<iostream>
using namespace std;

class A{
    int x;
public:
    A(int _val):x(_val) {};

    friend class B; //friend keyword use krne se koi dusra class ya function uske private member variables ko access kr skta h
    friend void Print(const A&);
};

class B{
public:
    void print(const A&a){
        cout<<a.x<<endl;
    }
};

void Print(const A&a){
    cout<<a.x<<endl;
}

int main(){
    A a(5);
    B b;
    b.print(a);
    Print(a);


    return 0;
}