#include<iostream>
#include<vector>
#include<queue>
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
        // a.marks < b.marks;  ye true hua toh 'a' pehle hoga 'b' se
        // but priority queue mai jo top hota h wo sbse last wala hota h toh isse max heap wana condition banegi 
        // min heap ke liye: a.marks > b.marks
        // isse bade wale sab left mai and sbse right mai sbse chhota wala , mtlb min heap
        return a.marks > b.marks;
    }
};


int main() {

    // //max heap
    // priority_queue<int> pq;
    // priority_queue<int, vector<int>, less<int>> pq2;

    // //min heap
    // priority_queue<int, vector<int>, greater<int>> pq3;

    priority_queue<Student, vector<Student>, Comparator> pq;

    pq.push(Student(90, "pravin"));
    pq.push(Student(27, "kunal"));
    pq.push(Student(99, "love"));
    pq.push(Student(95, "lakhshya"));

    while(!pq.empty()) {
        cout<<pq.top().marks<<" "<<pq.top().name<<endl;
        pq.pop();
    }

    return 0;
}