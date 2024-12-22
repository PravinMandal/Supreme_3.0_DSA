#include<iostream>
using namespace std;

class abc{

    mutable int x;
    int *y;
    const int z;

public:
    
    // //ctor old style
    // abc(int _x, int _y , int _z=0){
    // // int _z=0 ek default argument h mtlb agar niche se _z ki value nhi diye toh bhi chalega by default 0 ho jayega but agar koi value pass kiye toh wo override hoke jo value pass kiye h wo aa jayega
    // // default argument humesha right most position pr likhte h kahin bich mai nhi like skte error dega
    //     x=_x;
    //     y=new int(_y);
    //     z=_z;
    // }
    // isme hum const "z" ko initialize nhi kr skte

    //initialization list
    abc(int _x, int _y, int _z):x(_x), y(new int (_y)), z(_z){} // ye h modern tarika
    //idhr const ko bhi initialize kr skte h starting mai ek baar jaise kiye h
    

    int getX() const //ab is function mai koi bhi member variable change nhi ho payega
    //obsly hum nhi chahenge ki getter func mai koi bhi member variable change ho kyuki iska kaam getter wala h 
    {
        // agar still const hote hue bhi iss func mai member variable ko change krna h toh member variable mai "mutable" keyword use krna hoga uske baad hum reassign kr skte h
        // but mainly hum ye debug krte time hi mutable keyword ka use krte h, normal code mai good programmers nhi krte use
        x=10;
        return x;
    }
    void setX(int _val) // isme hum const use nhi krenge kyuki iss func mai hum chahte h kisi member variable ki valur reassign krna
    {
        x=_val;
    }

    int getY() const {
        return *y;
    }
    void setY(int _val){
        *y=_val;
    }

    int getZ() const{
        return z;
    }


};

void PrintABC( const abc &a){
    //idhr const object le liye toh ab iske andar agar koi func call krte h toh wo bhi mandatory const hona hi chahiye 
    cout<<a.getX()<<" "<<a.getY()<<" "<<a.getZ()<<endl;
    // idhr "a" sirf const func ko hi call kr skta h
    //iss func mai hum aisa koi bhi func use nhi kr skte jo object "a" ko change kr skta h
}

int main(){
    // abc a;
    // cout<<a.getX()<<endl;
    // cout<<a.getY()<<endl;
    // a.setX(5);
    // a.setY(10);
    // cout<<a.getX()<<endl;
    // cout<<a.getY()<<endl;

    abc a(1,2,3);
    PrintABC(a);

    return 0;
}


int main2(){

    // const int x=5; // x is const variable , ab isse change nhi kr skte // initialize kr skte h
    // // x=10; // reassign nhi kr skte
    // cout<<x<<endl;


    // //2. const with pointer

    // const int *a=new int(2); // CONST DATA , NON-CONST POINTER
    // // int const *a=new int(2); //same as line no. 14
    // cout<<*a<<endl;
    // // *a=5; // reassign nhi kr skte //can't change the content of pointer

    // int b=20;
    // a=&b; // pointer itself can be reassign
    // cout<<*a<<endl;


    // // CONST POINTER ,But NON-CONST DATA
    // int *const c=new int(5);
    // cout<<*c<<endl;
    // *c=30; // chal jayega
    // cout<<*c<<endl;

    // int d=20;
    // // a=&d; //ye nhi chalega


    // //CONST DATA AND CONST POINTER
    // const int *const a=new int(2);
    // cout<<*a<<endl;
    // *a=10; //ye nhi kr skte 
    // int b=40;
    // a=&b; // ye bhi nhi kr skte


    return 0;
}