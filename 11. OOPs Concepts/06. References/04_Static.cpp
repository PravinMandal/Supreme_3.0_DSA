//static data member
//static member function
#include<iostream>
using namespace std;

class abc{
public:
    static int x,y;
    //saare instances(object) ke liye x and y ek hi copy share honge

    static void print() //static member function bana diya ab saare instances ke liye print function same hi hoga
    {
        //normally compiler ko pta kaise chalta h ki kis obj ke liye function call ho rha h
        //wo fuction mai this pointer use krta h and uss object jo point krta h jisne iss function ko call kiye h

        //isko static bana diye toh ab koi this pointer pass nhi ho rha h
        // agar x and y ko non static bana diye toh ye kaam bhi nhi krega
        //phir bss simple printing kr payenge bss

        cout<<x<<" "<<y<<endl;


    }
};

int abc::x;
int abc::y;
//static data member yaha bahar initialize krte h

int main(){

    abc obj1;
    obj1.x=5;
    obj1.y=10;
    obj1.print();

    abc obj2;
    obj2.x=15;
    abc::y=20; // ye ho paa rha h because of static member function
    obj1.print(); // x and y ki same copy share hoti h static data member mai isiliye ab iski value bhi 15 and 20 ho gyi hogi
    obj2.print();
    abc::print(); // sattic member function mai sbka print function same hi hoga toh aise bhi call kr skte h



    return 0;
}