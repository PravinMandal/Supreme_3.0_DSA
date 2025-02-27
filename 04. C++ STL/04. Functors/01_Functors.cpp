#include<iostream>
using namespace std;

class functorOne {
public:
    int operator() (int a, int b) {
        //descending order mai compare krna chahte ho
        //if a>b -> true, 'a' should be placed before 'b'
        //that's why descending order banata h
        return a > b;
    }
};

int main()
{   

    functorOne cmp;

    if( cmp(10,5) == true ) {
        //functor is a object function
        cout<<"10 is greater than 5"<<endl;
    }
    else{
        cout<<"10 is less than 5"<<endl;
    }

    return 0;
}
