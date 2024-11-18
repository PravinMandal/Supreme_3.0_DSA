#include<iostream>
using namespace std;

class Student{

private:
    //Attributes
    int id;
    int age;
    string name;
    int nos; //number of subjects
    float *gpa;
    string gf;

public:
    void setGpa(float a){
        //layer of authentication;
        *this->gpa=a; // isse ab hum gpa ko set kr skta h
    }
    float getGpa(){
        return *this->gpa;
    }
    int getAge(){
        return this->age;
    }

    //constructor humesha public mai hi rhta h
    //ctor: Default ctor(constructor)
    Student(){
        cout<<"Student default ctor called "<<endl;
    }

    //ctor: Parameterised ctor
    Student(int id,int age, string name, int nos,float gpa,string gf){
        cout<<"Student Parameterised ctor called"<<endl;
        this->id=id; // jo member variable 'id' h class mai usko intialize kr rhe h
        this->age=age;// class ka age= age(jo main fuction se aa rha h)
        this->name=name;
        this->nos=nos;
        this->gpa=new float(gpa);
        //this keyword current object(jis object ki abhi baat ho rhi h uspr point krta h uske class wale member variable pr) 
    }


    //ctor: Copy ctor
    Student(const Student &srcobj){ //srcobj=> A
        cout<<"Student Copy ctor called"<<endl;
        this->id=srcobj.id;
        this->age=srcobj.age;
        this->name=srcobj.name;
        this->nos=srcobj.nos;
        //ab jo current object aayega usme srcobj(source object) ke variables de initialize ho jayega , mtlb copy ho jaayega
        //this keyword current object(jis object ki abhi baat ho rhi h uspr point krta h)
    }


    //Behavoir / Methods / functions
    void study(){
        cout<<this->name <<" Studying"<<endl;
        //this keyword abhi jis object ki baat ho rhi h usse point krta h mtlb uske member variable pr jo class mai defined h
    }

    void bunk(){
        cout<<this->name<<" Bunking"<<endl;
    }


    //dtor(destructor)
    ~Student(){
        cout<<"Student default dtor called "<<endl;
        delete this->gpa; //hume ye khud krna pdega , jabhi dynamic memory allocation krte h khud hi krna pdta h
        //isliye destructor use hota h because of dynamic memory allocation ko delete krne ke liye
    }

private:
    void gfChatting(){
        cout<<this->name<<"Chatting with gf "<<endl;
    }

};


int main(){

    Student A(1,19,"babbar",6,8.9,"meenu");
    //private wali cheeze ab mai access nhi kr skta 
    //getter aur setter se kr skta hu
 
    cout<<A.getGpa()<<endl;
    A.setGpa(7.3);
    cout<<A.getGpa()<<endl;
    cout<<A.getAge()<<endl;

    


    return 0;
}