// kya hum ctor ko private bana skte h? -> Yes
#include<iostream>
using namespace std;

class Box{
    int width;
    //ctor
    Box(int _w):width(_w) {};
public:

    int getbox() const{
        return width;
    }

    void setbox(int _val){
        width=_val;
    }

    friend class Boxfactory;
};

class Boxfactory{
    int count;
public:

    Box getAbox(int _w){
        ++count;
        return Box(_w);
    }
};

int main(){

    // Box b(5);
    // cout<<b.getbox()<<endl;

    Boxfactory bfact;
    Box b=bfact.getAbox(5);
    b.setbox(10);
    cout<<b.getbox()<<endl;



    return 0;
}