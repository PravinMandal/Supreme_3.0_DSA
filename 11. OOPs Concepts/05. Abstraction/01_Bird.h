#if !defined(BIRD_H)
#define BIRD_H
#include<iostream>

class Bird{
public: 
    virtual void eat()=0;
    virtual void fly()=0;
    //classes that inherit this class has to implement pure virtual function
};

class Sparrow : public Bird{
    void eat(){
        std::cout<<"sparrow is eating\n";
    }

    void fly(){
        std::cout<<"sparrow is flying\n";
    }
};

class Eagle: public Bird{
public:
    void eat(){
        std::cout<<"Eagle is eating \n";
    }

    void fly(){
        std::cout<<"Eagle is flying \n";
    }
};
#endif //Bird_H