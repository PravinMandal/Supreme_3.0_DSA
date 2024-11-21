#include<iostream>
#include "01_Bird.h"
using namespace std;

void birdDoesSomething(Bird *& bird){
    bird->eat();
    bird->fly();
    bird->eat();
    bird->eat();
    bird->fly();
    bird->eat();
    bird->eat();
    bird->fly();
    bird->eat();
}

int main(){

    Bird *bird=new Eagle(); // bss yaha eagle ki jagah sparrow krne se sb change ho jayega upr func mai saare line change krne ki zarurat nhi
    birdDoesSomething(bird);

   //Bird *b2=new tiger(); // khud se nhi bana skte pehle se jo humne banaya h header file usme hona chahiye

    return 0;
}
