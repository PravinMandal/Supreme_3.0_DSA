#include<iostream>
using namespace std;

#define PI 3.141592
//compilation se pehle preprocessor preprocessing krta h uss wakt jo aise #define krke likha hota h usse wo poore code mai manually put kr deta h
//jaha jaha PI likha hoga waha waha preprocessor Poori value 3.141592 khud manually put kr dega 
//hum isse ek khudka constant bana skte h

#define MAXX(x,y) (x>y ? x:y)


float circleArea(float r){
    return PI*r*r;
}

float CircleParimeter(float r){
    return 2*PI*r;
}

void fun(){
    int a=5;
    int b=10;
    int c= MAXX(a,b);
    // yaha pr preprocessor manually MAXX(a,b) ke jahah pr (x>y ? x:y) put krega Macro koi space bhi nhi leta 
    //just starting mai hi preprocessing krke saari jagah pr manually put kr deta h value
}

void fun2(){
    int x=15;
    int y=20;
    int c= MAXX(x,y);
}

void fun3(){
    int p=5;
    int q=10;
    int c= MAXX(p,q);
}

int main(){

    cout<<circleArea(51.33)<<endl;
    cout<<CircleParimeter(43.34)<<endl;

    return 0;
}