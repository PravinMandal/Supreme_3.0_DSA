//compile time polymorphism mtlb hum isme same naam ke alag alag functions bana skte h , agar hum bss number of arguments or type change krde toh

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


int main(){
    int x=5;
    int y=4;
    int z=3;
    Add add;
    cout<<add.sum(x,y)<<endl;
    cout<<add.sum(x,y,z)<<endl;
    cout<<add.sum(5.2,3.7)<<endl;

    return 0;
}