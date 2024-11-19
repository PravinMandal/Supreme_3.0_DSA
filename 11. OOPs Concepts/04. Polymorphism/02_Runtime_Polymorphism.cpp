#include<iostream>
using namespace std;

class Shape{
public:
    void draw(){
        cout<<"Generic drawing "<<endl;
    }
};

class Circle : public Shape{
public:
    void draw(){
        cout<<"Circle drawing "<<endl;
    }
};

class rectangle : public Shape{
public:
    void draw(){
        cout<<"Rectangle drawing "<<endl;
    }
};


void ShapeDrawing(Shape *s){
    s->draw();
}


int main(){

    Circle c;
    c.draw();
    rectangle r;
    r.draw();

    ShapeDrawing(&c); //yaha pr mai circle ka c bhej rha hu but still base class wala draw func call hoke print ho rha h
    ShapeDrawing(&r); // mujhe chahiye ki ek ShapeDrawing ka function banau and jo shape bhejna h bhej ko wo print kara lu

    


    

    
}