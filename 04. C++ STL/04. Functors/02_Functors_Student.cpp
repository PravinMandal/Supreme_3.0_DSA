#include<iostream>
using namespace std;

class Student {
public:
    int marks;
    string name;
    Student(){} //default ctor 
    Student(int m, string n) {
        this->marks = m;
        this->name = n;
    }
};

//functor
class StudentComparator {
public:
    bool operator() (Student a, Student b) {
        //mai () round bracket ko overload kr rha hu 
        // taaki jo object h wo as a function jaise kaam kare
        //jiska marks kam hoga wo return hoga
        return a.marks < b.marks;
    }
};

int main() {

    Student s1;
    Student s2;

    s1.marks = 93;
    s1.name = "love";

    s2.marks = 97;
    s2.name = "lakshya";

    StudentComparator cmp;

    if( cmp(s1,s2) ) {
        cout<<"love ke marks lakshya se kam h"<<endl;
    }
    else {
        cout<<"lakshya ke marks love se kam h"<<endl;
    }

    return 0;
}