#include<iostream>
using namespace std;

class Vehicle{
protected:
    string name;
    string model;
    int noOfTyres;
public:
    //constructor banate h
    Vehicle(string _name, string _model, int _noOfTyres){
        cout<<"I am inside vehicle ctor "<<endl;
        this->name=_name;
        this->model=_model;
        this->noOfTyres=_noOfTyres;
    }

    void start_engine(){
        cout<<"Engine is starting "<<name<<" "<<model<<endl;
    }
    void stop_engine(){
        cout<<"Engine is stopping "<<name<<" "<<model<<endl;
    }
    ~Vehicle(){
        cout<<"I am inside vehicle dtor "<<endl;
    }
};

class car:public Vehicle{
protected:
    int noOfDoors;
    string TransmissionType;

public: 
    car(string _name, string _model, int _noOfTyres, int _noOfDoors, string _TransmissionType):Vehicle(_name,_model,_noOfTyres){
        cout<<"I am inside car ctor "<<endl;
        this->noOfDoors=_noOfDoors;
        this->TransmissionType=_TransmissionType;
    }

    void startAC(){
        cout<<"AC is starting of "<<name<<" "<<model<<endl;
    }

    ~car(){
        cout<<"I am inside car dtor "<<endl;
    }
};

class motorCycle:public Vehicle{
protected:
    string handleBarStyle;
    string suspentionType;

public:
    motorCycle(string _name, string _model, int _noOfTyres, string _handleBarStyle, string _suspentionType):Vehicle(_name,_model,_noOfTyres){
        cout<<"motorCycle ctor called "<<endl;
        this->handleBarStyle=_handleBarStyle;
        this->suspentionType=_suspentionType;
    }

    void wheelie(){
        cout<<"wheelie maar rhe h "<<name<<endl;
    }

    ~motorCycle(){
        cout<<"I am inside motorCycle dtor "<<endl;
    }

};

int main(){
    car A("maruti","800",4,4,"manual");
    A.start_engine();
    A.startAC();
    A.stop_engine();

    motorCycle B("BMW","x",2,"u","hard");
    B.start_engine();
    B.wheelie();
    B.stop_engine();



    return 0;
}