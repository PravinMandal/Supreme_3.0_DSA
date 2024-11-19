#include<iostream>
using namespace std;

class Shape //final: idhr final keyword laga diya toh iss class ko koi inherit nhi kr payega
{
public:
    virtual void draw(){ //virtual keyword ka use krte hi ab ye iss cheez ko runtime ke liye chhod dega
        cout<<"Generic drawing "<<endl;
    }
};

class Circle : public Shape{
public:
    void draw() override{ //override aisehi daal rhe h code ko more redable banata h ki haan override ho rha h draw func
        cout<<"Circle drawing "<<endl;
    }
};

class rectangle : public Shape{
public:
    void draw() override{
        cout<<"Rectangle drawing "<<endl;
    }
};

class Triangle : public Shape{
public:
    void draw() override{
        cout<<"Triangle drawing "<<endl;
    }
};


void ShapeDrawing(Shape *s){
    s->draw(); // ab usse pta h ki S hai toh base class ka object but usme humne kisi aur class ke object ka address store kiya h
    //ab late binding ho rhi h
    //runtime pr bind ho rha h
}


int main(){

    Circle c;//stack mai
    rectangle r;//stack mai
    Triangle *t=new Triangle(); //heap mai ho rha h


    ShapeDrawing(&c); //yaha pr mai circle ka c bhej rha hu but still base class wala draw func call hoke print ho rha h
    ShapeDrawing(&r); // mujhe chahiye ki ek ShapeDrawing ka function banau and jo shape bhejna h bhej ko wo print kara lu
    ShapeDrawing(t);
    //compiler early binding kr rha h toh hum virtual keyword ka use krke usko bewakoof banayenge
    //virtual keyword use krne ke baad wo seriously nhi leta and bolta h runtime pr dekhte h
    // and runtime pr pta chal jaata h ki konse class ka object bhej rhe h 


    //final keyword
    //final keyword jis class mai laga denge usko koi inherit nhi kr payega
    //uss parent class ka koi child class nhi bann payega
    //and agar usse hum virtual func(jisme virtual keyword use kiye h) usme final keyword laga denge toh koi function override bhi nhi kr payega






    

    
}