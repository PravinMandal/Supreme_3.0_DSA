//compile time polymorphism
//Operator overloading:
//hum isme same naam ke alag alag functions bana skte h , agar hum bss number of arguments or type change krde toh

#include<iostream>
using namespace std;

class Add{
public:
    
    int sum(int x,int y){
        cout<<"sum of 2 int "<<endl;
        return x+y;
    }

    int sum(int x,int y,int z){
        cout<<"sum of 3 int "<<endl;
        return x+y+z;
    }

    double sum(double x,double y){
        cout<<"sum of 2 double "<<endl;
        return x+y;
    }
};


class Complex{
public:
    int real;
    int imag;

    Complex(){
        real=imag=-1;
    }
    Complex(int r,int i): real(r), imag(i){

    };

    //syntax for operator overload
    // returntype operator<op>(argument)

    Complex operator+(const Complex&B){ //const mtlb hum B ko constant kr de rhe h and change nhi kr payenge(Good practice)
        //this A ko point krega A.fun(B) aise, represent kr rhe h aise but + function call krega yaha pr
        Complex temp;
        temp.real=this->real+B.real;
        temp.imag=this->imag+B.imag;

        return temp;
    }

    Complex operator-(const Complex&B){
        //this A ko point krega A.fun(B) aise, represent kr rhe h aise but + function call krega yaha pr
        Complex temp;
        temp.real=this->real-B.real;
        temp.imag=this->imag-B.imag;

        return temp;
    }

    bool operator==(const Complex&B){
        
        return (this->real==B.real) && (this->imag==B.imag);
    }



    void print(){
        printf("[%d + i%d]\n", this->real, this->imag);
    }
};


int main(){

    ////Function Overloading

    // int x=5;
    // int y=4;
    // int z=3;
    // Add add;
    // cout<<add.sum(x,y)<<endl;
    // cout<<add.sum(x,y,z)<<endl;
    // cout<<add.sum(5.2,3.7)<<endl;


    ////Operator overloading

    Complex A(3,9);
    A.print();
    Complex B(2,6);
    B.print();
    
    Complex C=A + B; // yaha pr + ko operator overload krna pdega 
    C.print();// ab hum kr paa rhe h addition because hume + ko overload kr diya kuch aur kaam krne ke liye 

    Complex D=A - B;
    D.print();

    bool a= A == B; //true hoga toh 1 store ho jayega but hum nhi kr skta toh hum "==" ka operator overloading kr denge
    cout<<a<<endl;

    return 0;
}