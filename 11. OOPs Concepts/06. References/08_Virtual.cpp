#include<iostream>
using namespace std;

class Base{
public:
    Base(){
        cout<<"Base ctor called "<<endl;
    }

    virtual ~Base(){
        //boht imp h base class ke dtor mai virtual use krna taaki derived class ke dtor bhi use ho sake
        cout<<"Base dtor called "<<endl;
    }
};

class Derived:public Base{
    int *a;
public:
    Derived(){
        a=new int[1000];
        cout<<"Derived ctor called "<<endl;
    }

    ~Derived(){
        delete[] a;
        cout<<"Derived dtor called "<<endl; //but humne dekha ki Derived ka dtor toh call hi nhi ho rha
        //ab call nhi ho rha toh delete[] a; bhi kaam nhi krega toh memory leak ka darr hai
        //isiliye hum isse handle krne ke liye base class ke dtor mai virtual use krte h
        //ab base class ke dtor mai virtual use krne ke baad derived class ka dtor bhi call ho rha h
    }
};

int main(){

    Base *b=new Derived();
    delete b;

    return 0;
}