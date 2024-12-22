#include<iostream>
using namespace std;

class abc{
public:
    int x;
    int *y;

    abc(int _x, int _y): x(_x), y(new int(_y)){}

    // //default dumb copy constructor: it does SHALLOW COPY
    // abc(const abc &obj){
    //     x=obj.x;
    //     y=obj.y;
    // }
    // isme problem ye h ki jab y copy ho rha h toh uska address bhi exactly copy ho jaa rha h but hume aisa nhi chahiye
    // just think ki ek hi address ko 2 log point kr rhe h
    
    //Our smart copy constructor //ab ye deep copy kr rha h
    abc(const abc &obj){
        x=obj.x;
        y=new int(*obj.y); // ye wo problem thik kr de rha h kyuki ab new address bana rha h and waha pr wo same value store kr de rha h
    }

    void print(){

        printf("X: %d\nPTR Y: %p\ncontent of Y: %d\n\n", x,y,*y);
    }
    
    ~abc(){
        delete y;
    }
};

int main(){

    abc a(1,2);
    cout<<"printing a\n";
    a.print();


    //abc b(a); // aise bhi copy constructor use kr skte h
    abc b=a; //ye normal default dumb copy constructor call kr rha h
    cout<<"printing b\n";
    b.print();
    *b.y=20;
    cout<<"printing a\n";
    a.print();
    cout<<"printing b\n";
    b.print();



    return 0;
}