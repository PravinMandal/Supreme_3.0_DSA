#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Student {
public:
    int marks;
    string name;

    Student() {}
    Student(int m, string n) {
        this->marks = m;
        this->name = n;
    }
};

class Comparator {
public:
    bool operator() (Student a, Student b) {
        //agar same marks hua toh name se decide hoga
        if(a.marks == b.marks) {
            return a.name < b.name;
        }
        return a.marks < b.marks;
    }
};

int main() {

    vector<Student> arr;
    arr.push_back(Student(90, "love"));
    arr.push_back(Student(85, "lakshya"));
    arr.push_back(Student(85, "pravin"));

    sort(arr.begin(), arr.end(), Comparator());

    for(Student a: arr) {
        cout<<a.marks<<" "<<a.name<<endl;
    }

    return 0;
}