#include<iostream>
#include "algorithm.h" // ALGORITHM_H -> defined now
using namespace std;

int main() {
    
    int arr[] = {5, 4, 3, 2, 1};
    sort(arr, 5);

    return 0;
}

// g++ -o is used to make exe from .os
// g++ -c is used to make .os from .cpp

//1. make .os of all .cpp files: "g++ -c file.cpp"
//2. link all .os and make executable: "g++ a.o b.o main.o -o my_program"

//kyu kr rhe h ye sb?
//mera ek vendor hu jisne algo banaya hai and kisi client ko dena h, toh code toh nhi de skta
//toh mai .o file de dunga usse wo use kr payega and mera secret code reveal bhi nhi hoga
//algorithm.h banaya but usme maine code nhi likha
//algorithm.cpp banaya and uska .o file create krke algorithm.cpp delete kr diya