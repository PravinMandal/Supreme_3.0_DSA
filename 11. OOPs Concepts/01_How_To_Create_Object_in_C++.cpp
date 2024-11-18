#include<iostream>
using namespace std;

class Student{

public:
    //Attributes
    int id;
    int age;
    string name;
    int nos; //number of subjects
    int *gpa;

    //ctor: Default ctor(constructor)
    Student(){
        cout<<"Student default ctor called "<<endl;
    }

    //ctor: Parameterised ctor
    Student(int id,int age, string name, int nos,float gpa){
        cout<<"Student Parameterised ctor called"<<endl;
        this->id=id; // jo member variable 'id' h class mai usko intialize kr rhe h
        this->age=age;// class ka age= age(jo main fuction se aa rha h)
        this->name=name;
        this->nos=nos;
        this->gpa=new int(gpa);
        //this keyword current object(jis object ki abhi baat ho rhi h uspr point krta h)
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

};

int main(){
    // Student a;
    // a.id=21;
    // a.age=15;
    // a.name="babbar";
    // a.nos=6;
    // a.study();

    // Student b;
    // b.id=21;
    // b.age=15;
    // b.name="Rahul";
    // b.nos=6;
    // b.bunk();
    


    // Student A(29,19,"pravin",5); //stack memory mai store ho rha h
    // Student B(2,16,"babbar",6);

    // cout<<A.age<<" "<<A.name<<endl;
    // cout<<B.age<<" "<<B.name<<endl;
    // A.study();
    // B.bunk();


    // //Copy ctor
    // //student C(A); / aise bhi kr skte h copy;
    // Student C=A; // C mai ab A ka sb copy ho gya
    // cout<<C.name<<" "<<C.age<<endl;


    //Dynamic Allocation , or Student pointer
    Student *A=new Student(29,19,"Pravin",5 , 9.8);
    cout<<A->name<<" "<<A->age<<endl;
    A->study(); //destructor call nhi ho rha , hume khud krna pdega
    delete A;
    return 0;
}